#pragma once
#include <queue>
class Entree
{
public:
	int interclient; // Durée d'interarrivée des clients
	int traitement; // Durée de traitement d'une pièce
	int num_derniere_piece; // Numéro de la dernière pièce de la file
	int dpe;
	int nb_pieces_perdues;
	std::queue<int> file;
	bool bloque;
	Entree();
	Entree(int const nb_piece, int const interclient, int const traitement);
};

