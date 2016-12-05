//ConsoleApplication8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void point(int pointA_x, int pointA_y, int pointB_x, int pointB_y, int pointC_x, int pointC_y, int pointD_x, int pointD_y, int lkrokow, char tablica[48][96]);

int main()
{
	srand(time(NULL));
	const int pointA_x = 47;
	const int pointA_y = 0;
	const int pointB_x = 47;
	const int pointB_y = 95;
	const int pointC_x = 22;
	const int pointC_y = 45;


	int pointD_x, pointD_y;
	pointD_x = rand() % 48;
	pointD_y = rand() % 96;

	char tablica[48][96];

	int lkrokow;
	cout << "Podaj ilosc krokow: ";
	cin >> lkrokow;

	for (int i = 0; i<48; i++)
	{
		for (int j = 0; j<96; j++)
		{
			tablica[i][j] = '0';
		}
	}

	tablica[pointA_x][pointA_y] = '=';
	tablica[pointB_x][pointB_y] = '=';
	tablica[pointC_x][pointC_y] = '=';
	tablica[pointD_x][pointD_y] = '+';

	point(pointA_x, pointA_y, pointB_x, pointB_y, pointC_x, pointC_y, pointD_x, pointD_y, lkrokow, tablica);

	for (int i = 0; i<48; i++)
	{
		if (i != 0)
		{
			cout << endl;
		}
		for (int j = 0; j<96; j++)
		{
			cout << tablica[i][j];
		}
	}
	cin.get();
	cin.get();
	return 0;
}
void point(int pointA_x, int pointA_y, int pointB_x, int pointB_y, int pointC_x, int pointC_y, int pointD_x, int pointD_y, int lkrokow, char tablica[48][96])
{
	for (int n = 0; n < lkrokow; n++)
	{
		int kostka = (rand() % 3) + 1;

		if (kostka == 1)
		{
			pointD_x = 0.5*(pointA_x + pointD_x);
			pointD_y = 0.5*(pointA_y + pointD_y);
		}
		else
			if (kostka == 2)
			{
				pointD_x = 0.5*(pointB_x + pointD_x);
				pointD_y = 0.5*(pointB_y + pointD_y);
			}
			else
				if (kostka == 3)
				{
					pointD_x = 0.5*(pointC_x + pointD_x);
					pointD_y = 0.5*(pointC_y + pointD_y);
				}
		if (tablica[pointD_x][pointD_y] != '=')
		{
			tablica[pointD_x][pointD_y] = '+';
		}
	}
}
