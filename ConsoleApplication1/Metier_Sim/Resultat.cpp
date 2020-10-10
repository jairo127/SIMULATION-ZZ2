#include "pch.h"
#include "Resultat.h"

Resultat::Resultat()
{
	for (int i = 1; i < max_pieces; i++)
	{
		date_in[i] = -1;
		date_out[i] = -1;
	}
}

void Resultat::EntreePiece(int const piece, int const date)
{
	date_in[piece] = date;
	log += "Entrée P" + std::to_string(piece) + ", t = " + std::to_string(date) + "\n";
}

void Resultat::SortiePiece(int const piece, int const date)
{
	date_out[piece] = date;
	log += "Sortie P" + std::to_string(piece) + ", t = " + std::to_string(date) + "\n";
}
