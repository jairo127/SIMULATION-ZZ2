#pragma once
#include <queue>

class Machine
{
public:
	std::queue<int> file;
	int piece_en_cours;
	int dpe;
	Machine(int dpe);
};

