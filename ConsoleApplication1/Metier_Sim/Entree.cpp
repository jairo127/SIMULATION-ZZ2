#include "pch.h"
#include "Entree.h"

Entree::Entree() : Entree(0,0,0) {}

Entree::Entree(int const nb_piece, int const interclient, int const traitement) :
	interclient(interclient), 
	traitement(traitement), 
	num_derniere_piece(nb_piece),
	dpe(0),
	nb_pieces_perdues(0),
	bloque(false)
{
	for (int i = 1; i <= num_derniere_piece; i++)
		file.push(i);
}
