#pragma once
#include <iostream>  //���������� ������������ ���� ��� ������ � ������/������� ����� ����������� ����� �����-������
#include <windows.h>  //���������� ������������ ���� ��� ������ � ��������� � ����������� Windows API
#include <conio.h>  //���������� ������������ ���� ��� ������ � ��������� ��� ������ � ���������� ������-������� � ����������� ��������
#include <ctime>  //���������� ����������� ���� ��� ������ � ��������� ��� ������ � �������� � �����
#include <vector>  //���������� ������������ ���� ��� ������ � ������������� ��������� � ������������ ������������ ������
#include <locale>  //���������� ������������ ���� ��� ������ � ������������ � ���������� ���������
#include <string>  //���������� ������������ ���� ��� ������ �� ��������
#include <stack>  //���������� ������������ ���� ��� ������� � ����������� ����

enum NumberColor { BLUE = 1, GREEN = 2, RED = 3, DARKBLUE = 4, BROWN = 5, TURQUOISE = 6, BLACK = 7, WHITE = 8 }; //������� ������� ����
enum KeyCode { ENTER = 13, SPACE = 32, LEFT = 75, RIGHT = 77, DOWN = 80, UP = 72 }; //���������� �����������
enum SapperObject { WALL = 100, HALL = 0, MINE = 10 }; //

using namespace std;

class Console
{
public:
	//����� ��� ��������� ������� ������� �� ������
	void Options(int x, int y);

	//�����, ������� ������� ������� ���� � ������ ������ ENTER ����� ������ ����
	void ShowLogo();

	//�����, ������� �������� ������
	void HideCursor(bool vision);

	void SetCursor(int x, int y);

	//����� ��� ��������� ���������� ������� (������ ����, �������� ����)
	void OptionsConsole();
};