#pragma once
#include <queue>
#include "Piece.h"

class Input
{
	/// Number of piece in this Input
	int nb_piece;
	/// LIFO describing the pieces to insert
	std::queue<Piece> queue;
	/// W.I.P
};

