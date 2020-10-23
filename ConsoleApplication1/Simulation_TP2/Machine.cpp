#include "pch.h"
#include "Machine.h"
#include "Constants.h"

Machine::Machine(int uid, int queue_size) : uid(uid), queue_size(queue_size), process_time(-1), DPE(INFINITE), blocked(false) {}

void Machine::InsertNextMachine(int machine_uid, float distribution)
{
	next_machine.push_back(machine_uid);
	next_machine_distribution.push_back(distribution);
}

int Machine::Goto()
{
	std::default_random_engine generator;
	std::uniform_real_distribution<float> distribution(0.0, 1.0);
	int output = -1;
	float distr = distribution(generator);
	float sum = 0.0;
	for (int i = 0; i < next_machine_distribution.size(); i++)
	{
		sum += next_machine_distribution[i];
		if (distr <= sum)
		{
			output = next_machine[i];
			break;
		}
	}
	return output;
}

void Machine::AddFixedProcessTime(int process_time)
{
	this->process_time = process_time;
}

bool Machine::InsertPiece(Machine &m, Piece p, int Date_Simulation, Result &r)
{
	bool ret = true;
	if (server.uid == -1 && queue.empty()) // Cas serveur vide (donc file vide)
	{
		server = p;
		DPE = Date_Simulation + process_time;
	}
	else // Cas serveur utilisé (file vide ou non)
	{
		if (queue_size == -1) // Cas file infinie
			queue.push(p);
		else // Cas file finie
		{
			if (queue.size() >= queue_size) // Si la file est pleine
			{
				m.blocked = true;
				m.DPE = INFINITE;
				ret = false;
			}
			else // file non pleine
			{
				queue.push(p);
			}
		}
	}
	return ret;
}

Piece Machine::GetPieceOut()
{
	Piece output; // WARNING : Can return an empty piece
	if (server.uid != -1)
		output = server;
	return output;
}

