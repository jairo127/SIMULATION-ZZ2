#pragma once

#include <iostream>
#include <string>
#include "Constantes.h"

class Resultat
{
public:
	std::string log;
	int date_in[max_pieces];
	int date_out[max_pieces];
	Resultat();
	void EntreePiece(int const piece, int const date);
	void SortiePiece(int const piece, int const date);
};

