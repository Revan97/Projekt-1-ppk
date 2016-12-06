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

void point(int pointD_x, int pointD_y, int lkrokow, char tablica[size_x][size_y]);
void tab(bool file, int pointD_x, int pointD_y, int lkrokow, char tablica[size_x][size_y]);
int main()
{
	srand(time(NULL));

	int pointD_x, pointD_y;
	pointD_x = rand() % size_x;
	pointD_y = rand() % size_y;

	char tablica[size_x][size_y];
	int lkrokow;
	bool file=true||false;
	char write = 't' || 'n';
	cout << "Podaj ilosc krokow: ";
	cin >> lkrokow;
	while (write != 't' || 'n')
	{
		cout << "Czy chcesz wypisac dane do pliku[Tak-t/Nie-n]: ";
		cin >> write;
		if (write == 't')
		{
			file = true;
			tab(file, pointD_x, pointD_y, lkrokow, tablica);
		}
		else
			if (write == 'n')
			{
				file = false;
				tab(file, pointD_x, pointD_y, lkrokow, tablica);
			}
			else
				if (write != 't' || 'n')
				{
					cout << "Wpisa³es niepoprawna znak, sprobuj ponownie. " << endl;
				}
	} 

	cin.get();
	cin.get();
	return 0;
}
void point(int pointD_x, int pointD_y, int lkrokow, char tablica[size_x][size_y]) //oblicza nowe wspó³¿êdne punktu D
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
		if (tablica[pointD_x][pointD_y] != '=') // nie pozawala na zastapienie wierzcho³ka trójk¹ta
		{
			tablica[pointD_x][pointD_y] = '+';
		}
	}
}
void tab(bool file, int pointD_x, int pointD_y, int lkrokow, char tablica[size_x][size_y]) // rysuje tablice ,na której zostan¹ naniesione punkty
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
	tablica[pointD_x][pointD_y] = '+';

	point(pointD_x, pointD_y, lkrokow, tablica);

	if (file = true)
	{
		ofstream to_file;
		to_file.open("dane.txt");
		for (int i = 0; i<size_x; i++)
		{
			if (i != 0)
			{
				cout << endl;
				to_file << endl;
			}
			for (int j = 0; j<size_y; j++)
			{
				cout << tablica[i][j];
				to_file << tablica[i][j];
			}
		}
		to_file.close();
	}
	else
		if (file = false)
		{
			for (int i = 0; i<size_x; i++)
			{
				if (i != 0)
				{
					cout << endl;
				}
				for (int j = 0; j<size_y; j++)
				{
					cout << tablica[i][j];
				}
			}
		}
}
