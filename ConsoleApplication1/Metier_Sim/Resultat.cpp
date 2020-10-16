#include "pch.h"
#include "Resultat.h"

Resultat::Resultat()
{
	for (int i = 1; i <= max_pieces; i++)
	{
		date_in[i] = -1;
		date_in_file[i] = -1;
		date_out_file[i] = -1;
		date_out[i] = -1;
		sejour_sys[i] = -1;
		sejour_file[i] = -1;
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
	int sum = 0;
	for (int i = 1; i <= piece; i++)
		sum += date_out[i] - date_in[i];
	sejour_sys[piece] = sum / piece;
	log += "Sortie P" + std::to_string(piece) + ", t = " + std::to_string(date) + "\n";
}

void Resultat::EntreePieceFile(int const piece, int const date)
{
	date_in_file[piece] = date;
}

void Resultat::SortiePieceFile(int const piece, int const date)
{
	date_out_file[piece] = date;
	int sum = 0;
	for (int i = 1; i <= piece; i++)
		sum += date_out_file[i] - date_in_file[i];
	sejour_file[piece] = sum / piece;
}

void Resultat::CalculerStats() // OBSOLETE
{
	for (int i = 1; i <= max_pieces; i++)
	{
		sejour_sys[i] = date_out[i] - date_in[i];
		sejour_file[i] = date_out_file[i] - date_in_file[i];
	}
}
