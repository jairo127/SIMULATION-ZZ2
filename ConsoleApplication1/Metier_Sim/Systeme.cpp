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
	if (imin == 2) // Si imin == 2 alors
	{
		Date_Simulation = m.dpe; // Date_Simulation = M.dpe
		r.log += "Fin traitement P" + std::to_string(m.piece_en_cours) + ", t = " + std::to_string(Date_Simulation) + "\n"; // (log)
		piece = m.piece_en_cours; // Retirer(M, P)
		m.piece_en_cours = -1; // M.Etat = vide
		out.file.push(piece); // Poser(Sortie, P)
		r.SortiePiece(piece, Date_Simulation); // (Stats sortie)

		if (m.file.size() <= 0) // Si estVide(file) alors
			m.dpe = infinite; // M.dpe = inf
		else
		{
			piece = m.file.front(); // Retirer(File,P)
			m.file.pop();
			if (in.bloque) // Si E.bloqué alors
				in.dpe = Date_Simulation; // E.dpe = Date_Simulation
			m.piece_en_cours = piece; // Poser(M, P)
			m.dpe = Date_Simulation + in.traitement; // M.dpe = Date_Simulation + Sa
			r.log += "Début traitement P" + std::to_string(m.piece_en_cours) + ", t = " + std::to_string(Date_Simulation) + "\n"; // (log)
		}
	}
	if (imin == 1) // Si imin == 1 alors
	{
		Date_Simulation = in.dpe; // Date_Simulation = E.dpe
		if (m.file.size() >= 9) // Si file est pleine alors
		{
			in.bloque = true; // E.etat = bloqué
			in.dpe = infinite; // E.dpe = inf
		}
		else // Sinon
		{
			piece = in.file.front(); // Retirer(E, P)
			in.file.pop();
			r.EntreePiece(piece, Date_Simulation); // (Stats entrée)
			if (m.piece_en_cours == -1) // Si serveur vide
			{
				m.piece_en_cours = piece; // Poser(M, P)
				m.dpe = Date_Simulation + in.traitement; // M.dpe = Date_Simulation + Sa
			}
			else // Sinon
			{
				m.file.push(piece); // Poser(File, P)
			}
			in.dpe = Date_Simulation + in.interclient; // E.dpe = Date_Simulation + Lam 
		}
		if (in.file.size() == 0) // Si file d'entrée vide
		{
			in.dpe = infinite;
			in.bloque = false; // éviter de rerentrer dans la cas 1
		}
			
	}
}

int Systeme::RechercheImin()
{
	int ret = 0;
	if (in.dpe < m.dpe)
		ret = 1;
	else
		ret = 2;
	if (in.dpe == infinite && m.dpe == infinite)
		ret = 0;
	return ret;
}

Resultat Systeme::Simuler()
{
	int imin = -1;
	Date_Simulation = 0;
	while (Date_Simulation < Date_Fin && imin != 0 )
	{
		imin = RechercheImin();
		TraiterEvenement(imin);
	}
	r.log += "Fin de la simulation, t = " + std::to_string(Date_Simulation) + "\n";
	return r;
}
