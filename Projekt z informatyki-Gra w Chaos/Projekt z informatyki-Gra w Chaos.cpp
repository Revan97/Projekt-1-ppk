//ConsoleApplication8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void point(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy, int lkrokow, char tablica[48][96]);
//s
int main()
{
	srand(time(NULL));
	const int ax = 47;
	const int ay = 0;
	const int bx = 47;
	const int by = 95;
	const int cx = 22;
	const int cy = 45;


	int dx, dy;
	dx = rand() % 48;
	dy = rand() % 96;

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

	tablica[ax][ay] = '=';
	tablica[bx][by] = '=';
	tablica[cx][cy] = '=';
	tablica[dx][dy] = '+';

	point(ax, ay, bx, by, cx, cy, dx, dy, lkrokow, tablica);

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
void point(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy, int lkrokow, char tablica[48][96])
{
	for (int n = 0; n < lkrokow; n++)
	{
		int kostka = (rand() % 3) + 1;

		if (kostka == 1)
		{
			dx = 0.5*(ax + dx);
			dy = 0.5*(ay + dy);
		}
		else
			if (kostka == 2)
			{
				dx = 0.5*(bx + dx);
				dy = 0.5*(by + dy);
			}
			else
				if (kostka == 3)
				{
					dx = 0.5*(cx + dx);
					dy = 0.5*(cy + dy);
				}
		if (tablica[dx][dy] != '=')
		{
			tablica[dx][dy] = '+';
		}
	}
}
