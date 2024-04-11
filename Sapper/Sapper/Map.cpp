#include "Map.h"


Map::Map() : width(0), height(0), isGameWon(false), h(GetStdHandle(STD_OUTPUT_HANDLE)) {}

void Map::SetWidth(int w)
{ 
	width = w; 
}

void Map::SetHeight(int h)
{
	height = h;
}

void Map::SetIsGameWon(bool value)
{
	isGameWon = value;
}

void Map::SetMap(const vector<vector<int>>& newMap)
{
	map = newMap;
}

void Map::SetMask(const vector<vector<int>>& newMask)
{
	mask = newMask;
}

void Map::SetHandle(HANDLE newHandle)
{
	h = newHandle;
}

int Map::GetWidth() const 
{ 
	return width; 
}

int Map::GetHeight() const 
{ 
	return height; 
}

bool Map::GetIsGameWon() const 
{ 
	return isGameWon; 
}

vector<vector<int>> Map::GetMap() const 
{
	return map;
}

vector<vector<int>> Map::GetMask() const 
{ 
	return mask; 
}

HANDLE Map::GetHandle() const 
{ 
	return h; 
}

//метод для инициализации игрового поля
void Map::InitializeMap()
{
	for (int i = 0; i < width; i++)
	{
		vector<int> temp;
		for (int j = 0; j < height; j++)
		{
			if (i == 0 || j == 0 || i == width - 1 || j == height - 1)
			{
				temp.push_back(WALL);
			}
			else
			{
				temp.push_back(HALL);
			}
		}
		map.push_back(temp);
	}
}

//метод для отображения игрового поля
void Map::PrintMap()
{
	Options(0, 0);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (mask[j][i] == HALL)
			{
				//SetConsoleTextAttribute(h, BLACK);
				cout << "."; //маска
				continue;
			}

			if (map[j][i] == WALL)
			{
				SetConsoleTextAttribute(h, WHITE);
				cout << (char)178; // стена
			}
			else if (mask[j][i] == 2)
			{
				cout << "!"; //флаг
			}
			else if (map[j][i] == HALL)
			{
				SetConsoleTextAttribute(h, BLACK);
				cout << " "; // коридор
			}
			else if (map[j][i] == MINE)
			{
				SetConsoleTextAttribute(h, GREEN);
				cout << "*"; //мина
			}
			else
			{
				SetConsoleTextAttribute(h, BLACK);
				SetConsoleTextAttribute(h, WHITE);
				cout << map[j][i];
			}
		}
		cout << "\n";
	}
}

//метод для расстановки чисел на игровом поле
void Map::NumberSetting()
{
	for (int i = 1; i < width - 1; i++)
	{
		for (int j = 1; j < height - 1; j++)
		{
			if (map[i][j] != MINE)
			{
				int count = 0;
				if (map[i - 1][j - 1] == MINE) count++;
				if (map[i - 1][j] == MINE) count++;
				if (map[i - 1][j + 1] == MINE) count++;
				if (map[i][j - 1] == MINE) count++;
				if (map[i][j + 1] == MINE) count++;
				if (map[i + 1][j - 1] == MINE) count++;
				if (map[i + 1][j] == MINE) count++;
				if (map[i + 1][j + 1] == MINE) count++;
				map[i][j] = count;
			}
		}
	}
}

//метод для инициализации маски (состояние ячеек)
void Map::InitializeMask()
{
	for (int i = 0; i < width; i++)
	{
		vector<int> temp;
		for (int j = 0; j < height; j++)
		{
			if (i == 0 || j == 0 || i == width - 1 || j == height - 1)
			{
				temp.push_back(WALL);
			}
			else
			{
				temp.push_back(HALL);
			}
		}
		mask.push_back(temp);
	}
}

//метод для открытия ячейки и обновления маски
int Map::OpenCell(int x, int y)
{
	if (mask[x][y] == HALL)
	{
		mask[x][y] = 1;

		if (map[x][y] == MINE)
		{
			SetConsoleTextAttribute(h, GREEN);
			cout << "*";
			return MINE;
		}
		else if (map[x][y] == HALL)
		{
			Fill(x, y, *this);
			return HALL;
		}
		else
		{
			SetConsoleTextAttribute(h, BLACK);
			SetConsoleTextAttribute(h, WHITE);
			cout << map[x][y];
			return map[x][y];
		}
	}
	if (CheckGameWon())
	{
		isGameWon = true;
		return -2;
	}
	return -1;
}

//метод для проверки выиграша в игре
bool Map::CheckGameWon()
{
	for (int i = 1; i < width - 1; i++)
	{
		for (int j = 1; j < height - 1; j++)
		{
			if (map[i][j] != MINE && mask[i][j] != 1) {
				return false; //если есть незамаскированные ячейки, игра не выиграна
			}
		}
	}
	return true; //все незамаскированные ячейки без мин, игра выиграна
}

//метод для заливки пустой области на игровом поле
//используется стек для хранения координат ячеек для заливки
//обновляем маску поля и отображаем изменения на экране
void Map::Fill(int px, int py, Map& map)
{
	stack<int> stk;
	stk.push(px);
	stk.push(py);

	int x = 0;
	int y = 0;
	while (!stk.empty())
	{
		y = stk.top();
		stk.pop();

		x = stk.top();
		stk.pop();

		if (map.map[x][y + 1] == HALL && map.mask[x][y + 1] == 0)
		{
			stk.push(x);
			stk.push(y + 1);
		}
		map.mask[x][y + 1] = 1;

		if (map.map[x][y - 1] == HALL && map.mask[x][y - 1] == 0)
		{
			stk.push(x);
			stk.push(y - 1);
		}
		map.mask[x][y - 1] = 1;

		if (map.map[x + 1][y + 1] == HALL && map.mask[x + 1][y + 1] == 0)
		{
			stk.push(x + 1);
			stk.push(y + 1);
		}
		map.mask[x + 1][y + 1] = 1;

		if (map.map[x + 1][y - 1] == HALL && map.mask[x + 1][y - 1] == 0)
		{
			stk.push(x + 1);
			stk.push(y - 1);
		}
		map.mask[x + 1][y - 1] = 1;

		if (map.map[x - 1][y + 1] == HALL && map.mask[x - 1][y + 1] == 0)
		{
			stk.push(x - 1);
			stk.push(y + 1);
		}
		map.mask[x - 1][y + 1] = 1;

		if (map.map[x - 1][y - 1] == HALL && map.mask[x - 1][y - 1] == 0)
		{
			stk.push(x - 1);
			stk.push(y - 1);
		}
		map.mask[x - 1][y - 1] = 1;

		if (map.map[x - 1][y] == HALL && map.mask[x - 1][y] == 0)
		{
			stk.push(x - 1);
			stk.push(y);
		}
		map.mask[x - 1][y] = 1;

		if (map.map[x + 1][y] == HALL && map.mask[x + 1][y] == 0)
		{
			stk.push(x + 1);
			stk.push(y);
		}
		map.mask[x + 1][y] = 1;

		if (stk.empty())
		{
			break;
		}
	}
	PrintMap(); //распечатка обновленной карты
}

// метод для установки флага на игровом поле
void Map::PlaceFlag(int x, int y)
{
	if (mask[y][x] == HALL) //проверяем, что ячейка еще не открыта
	{
		mask[y][x] = 2; //устанавливаем флаг
		PrintMap(); //обновляем экран после установки флага
	}
	else if (mask[y][x] == 2) //если в ячейке уже установлен флаг
	{
		mask[y][x] = HALL; //убираем флаг, восстанавливаем маску
		PrintMap(); //обновляем экран после удаления флага
	}
}
