#pragma once
#include <stdio.h>
#include <vector>

using namespace std;

struct Nodo
{	
	int nivel_max;
	int turno;
	
	damas * DM;
	list<Nodo*>VD;
	int Peso;
	list<pair<int, int>>TFA;
	list<pair<int, int>>TFB;
	int numTFA;
	int numTFB;
	Nodo(list<pair<int,int>>fichas_A,int numero_fichas_A, list<pair<int, int>>fichas_B,int numero_fichas_B,int Turno,int nivel_maximo)
	{

		nivel_max = nivel_maximo;
		turno = Turno;
		DM = new damas(fichas_A, numero_fichas_A, fichas_B, numero_fichas_B, turno);

		TFA = fichas_A;
		TFB = fichas_B;
		numTFA = numero_fichas_A;
		numTFB = numero_fichas_B;

		Nodo* PT;

		if (Turno == 0)
		{

			for (list< pair<int, int>>::iterator it = TFA.begin(); it != TFA.end(); it++)
			{
				PT = new Nodo(fichas_A, numero_fichas_A, fichas_B, numero_fichas_B, Turno, nivel_maximo);
				VD.push_back(PT);
			}
		}
			
	}

};
class Arbol
{
	Nodo * Padre;

	Arbol(int turno)
	{
	
		//Padre = new Nodo;
	}
};
