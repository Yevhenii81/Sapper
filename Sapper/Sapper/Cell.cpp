#include "Cell.h"


Cell::Cell() : isMine(false), isRevealed(false), adjacentMines(0) {}

//метод, который рандомно расставляет мины
void Cell::RandMines(int numMines, Map& map)
{
	//проверка на количество мин, которые можно установить на поле
	if (numMines >= (map.width - 2) * (map.width - 2))
	{
		MessageBoxA(0, "Слишком много мин!", "Попробуйте заново!", MB_OK);
		return;
	}
	for (int i = 0; i < numMines; i++)
	{
		int x = 0;
		int y = 0;
		//поиск пустой ячейки, не занятой миной
		do
		{
			x = rand() % (map.width - 2) + 1;
			y = rand() % (map.height - 2) + 1;
		} while (map.map[x][y] == MINE);
		map.map[x][y] = MINE;
	}
}