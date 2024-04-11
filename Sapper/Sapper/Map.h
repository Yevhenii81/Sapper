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

	void SetWidth(int w);
	void SetHeight(int h);
	void SetIsGameWon(bool value);
	void SetMap(const vector<vector<int>>& newMap);
	void SetMask(const vector<vector<int>>& newMask);
	void SetHandle(HANDLE newHandle);

	int GetWidth() const;
	int GetHeight() const;
	bool GetIsGameWon() const;
	vector<vector<int>> GetMap() const;
	vector<vector<int>> GetMask() const;
	HANDLE GetHandle() const;

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
