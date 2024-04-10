#pragma once

#include "Console.h"
#include "Map.h"

class Cell
{
private:
	bool isMine;
	bool isRevealed;
	int adjacentMines;
public:
	Cell();

	//метод, который рандомно расставляет мины
	void RandMines(int numMines, Map& map);
};