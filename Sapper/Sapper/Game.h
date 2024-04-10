#pragma once
#include "Console.h"
#include "Map.h"
#include "Cell.h"

class Game
{
public:
	Map map;
	Cell cell;
	Console console;

	void ResizeMap(int w, int h, int numMines);

	void StartEasyLevel();

	void StartMediumLevel();

	void StartHardLevel();

	void Menu();

	//метод проиграша
	void GameOver();

	//метод выиграша 
	void Won();

	//метод, который запускает игру, инициализирует карту, расставляет мины,
	//позволяет игроку управлять персонажем и выполняет игровую логику
	void run();
};