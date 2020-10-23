#pragma once
class Piece
{
public:
	/// <summary>
	/// Unique identifier of a piece
	/// </summary>
	int uid;

	/// <summary>
	/// Type of the piece
	/// </summary>
	int type;

	/// <summary>
	/// Default constructor of piece
	/// </summary>
	Piece();

	/// <summary>
	/// Constructor of piece
	/// </summary>
	/// <param name="uid">Unique identifier of piece</param>
	/// <param name="type">Type of piece</param>
	Piece(int uid, int type);
};

