#pragma once


#include <iostream>
#include <fstream>
#include <string>

#include "Entree.h"
#include "Sortie.h"
#include "Machine.h"
#include "Resultat.h"
#include "Constantes.h"

class Systeme
{
public:
	Entree in;
	Sortie out;
	Machine m;
	Resultat r;
	int const Date_Fin;
	int Date_Simulation;
	Systeme(int const nb_piece, int const interclient, int const traitement, int const date_fin);
	void TraiterEvenement(int imin);
	int RechercheImin();
	Resultat Simuler();

};

