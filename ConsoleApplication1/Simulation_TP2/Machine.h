#pragma once
#include <queue>
#include <random>
#include "Piece.h"
#include "Result.h"

class Machine
{
public:
	/// Describe a unique identifier for a machine
	int uid;
	/// LIFO to describe the buffer before the server
	std::queue<Piece> queue;
	/// Describe the maximum size of the queue (-1 if infinite)
	int queue_size;
	/// Describe the piece 
	Piece server;
	/// Describe the process time of a piece
	int process_time;
	/// Describe the date of the next event
	int DPE;
	/// True if the machine is blocked
	bool blocked;
	/// Describe the next machine where the output can go
	std::vector<int> next_machine;
	/// Describe the probability for the piece to go to the next machine
	std::vector<float> next_machine_distribution;

	/// <summary>
	/// Constructor of a machine
	/// </summary>
	/// <param name="uid">UID of this machine</param>
	/// <param name="queue_size">Size of the buffer</param>
	Machine(int uid, int queue_size);
	
	/// <summary>
	/// Add a machine to the output possibilities
	/// </summary>
	/// <param name="machine_uid">UID of the machine to add</param>
	/// <param name="distribution">Probability to go to this machine</param>
	void InsertNextMachine(int machine_uid, float distribution);

	/// <summary>
	/// Return the machine where the output go
	/// </summary>
	/// <returns>UID of the destination</returns>
	int Goto();

	/// <summary>
	/// Add a fixed processing time for the machine
	/// </summary>
	/// <param name="process_time"></param>
	void AddFixedProcessTime(int process_time);

	/// <summary>
	/// Calculate the direct process time of a piece with a constant distribution
	/// </summary>
	/// <param name="avg">Average of the constant law</param>
	/// <returns>Process time of the piece</returns>
	int CalculateProcessTime_Constant(int avg);

	/// <summary>
	/// Insert a piece in the machine
	/// Stats not implemented
	/// </summary>
	/// <param name="m">Machine that the piece come from</param>
	/// <param name="p">Piece to insert</param>
	/// <param name="Date_Simulation">Date of the simulation</param>
	/// <param name="r">Result object to insert stats</param>
	/// <returns>true if success else false</returns>
	bool InsertPiece(Machine& m, Piece p, int Date_Simulation, Result& r);

	/// <summary>
	/// Return the piece that finished its process and empty the server
	/// </summary>
	/// <returns>Piece that finished its process</returns>
	Piece GetPieceOut();
};

