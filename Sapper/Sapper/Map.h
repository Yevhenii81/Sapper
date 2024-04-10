#pragma once
#include "Console.h"

class Map : public Console
{
private:
	/*int width = 10;
	int height = 10;*/
	int width;
	int height;
	friend class Cell;
	friend class Game;

	bool isGameWon;  //переменная для отслеживания выиграша
	vector<vector<int>> map;  //двумерный вектор для игрового поля
	vector<vector<int>> mask;  //двумерный вектор для маски игрового поля
	HANDLE h;  //дескриптор для работы с консолью
public:
	/*Map(int w, int h) : width(w), height(h), h(GetStdHandle(STD_OUTPUT_HANDLE))
	{
		InitializeMap();
		InitializeMask();
	}*/

	Map();

	void setWidth(int w);
	int getWidth() const;
	void setHeight(int h);
	int getHeight() const;
	void setIsGameWon(bool value);
	bool getIsGameWon() const;
	void setMap(const std::vector<std::vector<int>>& newMap);
	std::vector<std::vector<int>> getMap() const;
	void setMask(const std::vector<std::vector<int>>& newMask);
	std::vector<std::vector<int>> getMask() const;
	void setHandle(HANDLE newHandle);
	HANDLE getHandle() const;

	//метод для инициализации игрового поля
	void InitializeMap();

	//метод для отображения игрового поля
	void PrintMap();

	//метод для расстановки чисел на игровом поле
	void NumberSetting();

	//метод для инициализации маски (состояние ячеек)
	void InitializeMask();

	//метод для открытия ячейки и обновления маски
	int OpenCell(int x, int y);

	//метод для проверки выиграша в игре
	bool CheckGameWon();

	//метод для заливки пустой области на игровом поле
	//используется стек для хранения координат ячеек для заливки
	//обновляем маску поля и отображаем изменения на экране
	void Fill(int px, int py, Map& map);

	// метод для установки флага на игровом поле
	void PlaceFlag(int x, int y);
};