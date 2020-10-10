#pragma once
#include <queue>
class Entree
{
public:
	int interclient; // Dur�e d'interarriv�e des clients
	int traitement; // Dur�e de traitement d'une pi�ce
	int num_derniere_piece; // Num�ro de la derni�re pi�ce de la file
	int dpe;
	int nb_pieces_perdues;
	std::queue<int> file;
	bool bloque;
	Entree();
	Entree(int const nb_piece, int const interclient, int const traitement);
};

