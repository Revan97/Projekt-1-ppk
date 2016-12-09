//ConsoleApplication8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int pointA_x = 47;
const int pointA_y = 0;
const int pointB_x = 47;
const int pointB_y = 95;
const int pointC_x = 22;
const int pointC_y = 45;
const int size_x = 48;
const int size_y = 96;
const float half_of = 0.5;

void point(int pointD_x, int pointD_y, int lkrokow, char tablica[size_x][size_y], char sign);
void tab( int pointD_x, int pointD_y, int lkrokow, char tablica[size_x][size_y], bool file, char sign);
void box(char letter, char sign, bool &stop);
int main()
{
	srand(time(NULL));

	int pointD_x, pointD_y;
	pointD_x = rand() % size_x;
	pointD_y = rand() % size_y;

	char tablica[size_x][size_y];
	int lkrokow;
	bool file;
	bool stop=false;
	char letter;
	char sign;
	
	cout << "Podaj ilosc krokow: ";
	cin >> lkrokow;
	cout << "Czy wypisac do pliku?[Tak-t/Nie-n]: ";
	cin >> letter;
	cout << "Podaj dowolny znak: ";
	cin >> sign;
	box(letter, sign, stop);
	if (stop)
	{
		cout << "program zatrzymany" << endl;
		cin.get();
		cin.get();
		return 0;
	}
		if (letter == 't')
		{
			file = true;
		}
		else
			if (letter == 'n')
			{
				file = false;
			}
	tab(pointD_x, pointD_y, lkrokow, tablica, file, sign);
	cin.get();
	cin.get();
	return 0;
}
void point(int pointD_x, int pointD_y, int lkrokow, char tablica[size_x][size_y], char sign) //oblicza nowe wspó³¿êdne punktu D
{
	for (int n = 0; n < lkrokow; n++)
	{
		int kostka = (rand() % 3) + 1; //losowanie wartoœci od 1-3

		if (kostka == 1)
		{
			pointD_x =half_of*(pointA_x + pointD_x);
			pointD_y = half_of*(pointA_y + pointD_y);
		}
		else
			if (kostka == 2)
			{
				pointD_x = half_of*(pointB_x + pointD_x);
				pointD_y = half_of*(pointB_y + pointD_y);
			}
			else
				if (kostka == 3)
				{
					pointD_x = half_of*(pointC_x + pointD_x);
					pointD_y = half_of*(pointC_y + pointD_y);
				}
		if (tablica[pointD_x][pointD_y] != '=') // nie pozwala na zamienienie wierzcho³ka trójk¹ta
		{
			tablica[pointD_x][pointD_y] = sign;
		}
	}
}
void tab( int pointD_x, int pointD_y, int lkrokow, char tablica[size_x][size_y], bool file, char sign) // rysuje tablice ,na której zostan¹ naniesione punkty
{

	for (int i = 0; i<size_x; i++)
	{
		for (int j = 0; j<size_y; j++)
		{
			tablica[i][j] = '0';
		}
	}
	tablica[pointA_x][pointA_y] = '=';
	tablica[pointB_x][pointB_y] = '=';
	tablica[pointC_x][pointC_y] = '=';
	tablica[pointD_x][pointD_y] = sign;

	point(pointD_x, pointD_y, lkrokow, tablica, sign);

	ofstream to_file;
	if (file)
	{
		to_file.open("dane.txt");
	}
	for (int i = 0; i<size_x; i++)
	{
		if (i != 0)
		{
			cout << endl;
			if (file)
			{
				to_file << endl;
			}
		}
			for (int j = 0; j<size_y; j++)
			{
				cout << tablica[i][j];
				if (file)
				{
					to_file << tablica[i][j];
				}
			}
		}
		to_file.close();
}
void box(char letter, char sign, bool &stop)
{
	switch (sign)
	{
	case '=':
		cout << "bledna dana" << endl;
		stop = true;
		break;
	case '0':
		cout << "bledna dana" << endl;
		stop = true;
		break;
	default:
		cout << "wybrales znak: " << sign << endl;
		break;

	}
	switch (letter)
	{
	case 't':
		cout << "wypisales do pliku"  << endl;
		break;
	case 'n':
		cout << "nie wypisales do pliku" << endl;
		break;
	default:
		letter != 't' || letter != 't';
		cout << "bledna dana" << endl;
		stop = true;
		break;
	}
}