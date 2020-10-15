#include "pch.h"
#include "Systeme.h"

Systeme::Systeme(int const nb_piece, int const interclient, int const traitement, int const date_fin) : m(Machine(interclient)), Date_Simulation(0), Date_Fin(date_fin)
{
	in = Entree(nb_piece, interclient, traitement);
	r.log += "Initialisation de la simulation...\n";
}

void Systeme::TraiterEvenement(int imin)
{
	int piece = -1;
	if (imin == 2)
	{
		// Actualisation date simu
		Date_Simulation = m.dpe;
		// ajout log
		r.log += "Fin traitement P" + std::to_string(m.piece_en_cours) + ", t = " + std::to_string(Date_Simulation) + "\n";
		// Retirer(M, P)
		piece = m.piece_en_cours;
		m.piece_en_cours = -1;
		// Poser(Sortie, P)
		out.file.push(piece);
		r.SortiePiece(piece, Date_Simulation); // stats

		if (m.file.size() <= 0)
			m.dpe = infinite; // dpe = inf
		else
		{
			// Retirer(File,P)
			piece = m.file.front();
			m.file.pop();
			if (in.bloque)
				in.dpe = Date_Simulation;
			// Poser(M, P)
			r.log += "Début traitement P" + std::to_string(m.piece_en_cours) + ", t = " + std::to_string(Date_Simulation) + "\n";
			m.piece_en_cours = piece;
			m.dpe = Date_Simulation + in.traitement;
		}
	}
	if (imin == 1)
	{
		if (in.file.size() > 0)
		{
			Date_Simulation = in.dpe;
			if (m.file.size() == 9)
			{
				in.bloque = true;
				in.dpe = infinite;
			}
			else
			{
				// Retirer(E, P)
				piece = in.file.front();
				in.file.pop();
				r.EntreePiece(piece, Date_Simulation);
				if (m.piece_en_cours == -1)
				{
					m.piece_en_cours = piece;
					m.dpe = Date_Simulation + in.traitement;
				}
				else
				{
					// Poser(File, P)
					m.file.push(piece);
				}
				in.dpe = Date_Simulation + in.interclient;
			}
		}
		else
			in.dpe = infinite;
	}
}

int Systeme::RechercheImin()
{
	int ret = 0;
	if (in.dpe == m.dpe)
	{
		if (m.piece_en_cours < in.file.front())
			ret = 2;
		else 
			ret = 1;
	}
	if (in.dpe > m.dpe)
		ret = 2;
	if (in.dpe < m.dpe)
		ret = 1;
	return ret;
}

Resultat Systeme::Simuler()
{
	Date_Simulation = 0;
	while (Date_Simulation < Date_Fin || out.file.size() != in.num_derniere_piece)
	{
		int imin = RechercheImin();
		TraiterEvenement(imin);
	}
	r.log += "Fin de la simulation, t = " + std::to_string(Date_Simulation) + "\n";
	return r;
}
