#pragma once

#include <iostream>
#include <string>
#include "Constantes.h"

class Resultat
{
public:
	std::string log;
	int date_in[max_pieces + 1];
	int date_in_file[max_pieces + 1];
	int date_out_file[max_pieces + 1];
	int date_out[max_pieces + 1];
	
	int sejour_sys[max_pieces + 1];
	int sejour_file[max_pieces + 1];

	Resultat();
	void EntreePiece(int const piece, int const date);
	void EntreePieceFile(int const piece, int const date);
	void SortiePieceFile(int const piece, int const date);
	void SortiePiece(int const piece, int const date);
	void CalculerStats();
};

