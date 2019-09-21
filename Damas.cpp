// Damas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
//#include <utility> 
#include <vector>
#include <list>
//#include "estructura.h"
//#include "estructura.h"
using namespace std;
struct damas
{
	list<pair<int, int>>Fichas_A;
	list<pair<int, int>>Fichas_B;

	int Numero_Fichas_A;
	int Numero_Fichas_B;

	//vector<list<pair<int, int>>> Jugadores;
	list<pair<int, int>> Jugadores[2] = { Fichas_A ,Fichas_B };

	int max_X = 7;
	int min_X = 0;
	int max_Y = 7;
	int min_Y = 0;

	int turno;//0 o 1

	damas(int maximo_X, int minimo_X, int maximo_Y, int minimo_Y)
	{
		max_X = maximo_X;
		min_X = minimo_X;
		max_Y = maximo_Y;
		min_Y = minimo_Y;

		//Jugadores.push_back(Fichas_A);
		//Jugadores.push_back(Fichas_B);

		for (int i = min_X; i <= max_X; i = i + 2)
		{
			//cout << "Built";
			Fichas_A.push_back(make_pair(min_X + i, min_Y));
			Fichas_A.push_back(make_pair(min_X + i + 1, min_Y + 1));
			Fichas_A.push_back(make_pair(min_X + i, min_Y + 2));

			Fichas_B.push_back(make_pair(min_X + i + 1, max_Y - 2));
			Fichas_B.push_back(make_pair(min_X + i, max_Y - 1));
			Fichas_B.push_back(make_pair(min_X + i + 1, max_Y));
		}
		//////
		turno = 0;//Temporal
		/////
		Numero_Fichas_A = 12;
		Numero_Fichas_B = 12;
	}
	damas(list<pair<int, int>>fichas_A, int numero_fichas_A, list<pair<int, int>>fichas_B, int numero_fichas_B, int Turno)
	{
		Fichas_A = fichas_A;
		Numero_Fichas_A = numero_fichas_A;
		Fichas_B = fichas_B;
		Numero_Fichas_B = numero_fichas_B;
		turno = Turno;

		//VISUALIZAR();
	}
	damas()
	{
		Numero_Fichas_A = 12;
		Numero_Fichas_B = 12;
	}
	

	
	int vacio(int x, int y)
	{
		//Turno CPU o PC
		list< pair<int, int>>::iterator it;
		//EXISTE alguien en x,y de A
		if (turno == 0)
		{
			for (it = Fichas_A.begin(); it != Fichas_A.end() && ((*it).first != x || (*it).second != y); it++)
			{

			}
			if (it != Fichas_A.end())
				return 1;
			//EXISTE alguien en x,y de B
			for (it = Fichas_B.begin(); it != Fichas_B.end() && ((*it).first != x || (*it).second != y); it++)
			{

			}
			if (it != Fichas_B.end())
				return -1;
		}
		else
		{
			for (it = Fichas_B.begin(); it != Fichas_B.end() && ((*it).first != x || (*it).second != y); it++)
			{
				//cout << "A";
			}
			//cout << "B" << endl;
			if (it != Fichas_B.end())
				return 1;
			//cout << "C" << endl;
			//EXISTE alguien en x,y de A
			for (it = Fichas_A.begin(); it != Fichas_A.end() && ((*it).first != x || (*it).second != y); it++)
			{

			}
			if (it != Fichas_A.end())
				return -1;
		}
		return 0;
	}
	bool mover( int Pieza_x, int Pieza_y, int x, int y)
	{
		if (x < min_X || x > max_X || y < min_Y || y > max_Y)
			return 0;
		list< pair<int, int>>::iterator it;
		if (turno == 0)
		{
			for (it = Fichas_A.begin(); it != Fichas_A.end() && ((*it).first != Pieza_x || (*it).second != Pieza_y); it++)
			{
			}
			if (it == Fichas_A.end())
				return 0;
			int VACIO = vacio(x, y);

			//cout << "TURNO: "<<turno << endl;
			//cout << (*it).first << " " << (*it).second << " : " << x << " " << y<<endl;
			//cout << "vACIO: "<<VACIO<<endl	;

			if (VACIO == 0)
			{
				//cambio de valor de Turno x,y
				(*it).first = x;
				(*it).second = y;
				return 1;
			}

			else if (VACIO == -1)
			{
				//Esta dentro del rango y esta vacio?
				//if ((x + (x - Pieza_x)) < max_X && (x + (x - Pieza_x)) > min_X && (y + (y - Pieza_y)) < max_Y && (y + (y - Pieza_y)) > min_Y && vacio(x + (x - Pieza_x), y + (y - Pieza_y)) == 0)
				if (((x + (x - Pieza_x)) > max_X || (x + (x - Pieza_x)) < min_X || (y + (y - Pieza_y)) > max_Y || (y + (y - Pieza_y)) < min_Y) || vacio(x + (x - Pieza_x), y + (y - Pieza_y)) != 0)
					return 0;

					list< pair<int, int>>::iterator enemigo;
					for (enemigo = Fichas_B.begin(); enemigo != Fichas_B.end() && ((*enemigo).first != x || (*enemigo).second != y); enemigo++)
					{

					}
					if (enemigo == Fichas_B.end())
						return 0;
					Fichas_B.erase(enemigo);
					Numero_Fichas_B--;
					//Borro enemigo
					(*it).first = x + (x - Pieza_x);
					(*it).second = y + (y - Pieza_y);
					return 1;
				
				
			}
			return 0;
		}
		else 
		{
			for (it = Fichas_B.begin(); it != Fichas_B.end() && ((*it).first != Pieza_x || (*it).second != Pieza_y); it++)
			{
			}
			if (it == Fichas_B.end())
				return 0;
			int VACIO = vacio(x, y);

			//cout << "tURNO: " <<turno << endl;
			//cout << (*it).first << " " << (*it).second << " : " << x << " " << y << endl;
			//cout << "vACIO: " << VACIO << endl;

			if (VACIO == 0)
			{
				//cambio de valor de Turno x,y
				(*it).first = x;
				(*it).second = y;
				return 1;
			}

			else if (VACIO == -1)
			{
				//Esta dentro del rango y esta vacio?
				//if ((x + (x - Pieza_x)) < max_X && (x + (x - Pieza_x)) > min_X && (y + (y - Pieza_y)) < max_Y && (y + (y - Pieza_y)) > min_Y && vacio(x + (x - Pieza_x), y + (y - Pieza_y)) == 0)
				if (((x + (x - Pieza_x)) > max_X || (x + (x - Pieza_x)) < min_X || (y + (y - Pieza_y)) > max_Y || (y + (y - Pieza_y)) < min_Y) || vacio(x + (x - Pieza_x), y + (y - Pieza_y)) != 0)
					return 0;
				
					list< pair<int, int>>::iterator enemigo;
					for (enemigo = Fichas_A.begin(); enemigo != Fichas_A.end() && ((*enemigo).first != x || (*enemigo).second != y); enemigo++)
					{

					}
					if (enemigo == Fichas_A.end())
						return 0;
					Fichas_A.erase(enemigo);
					Numero_Fichas_A--;
					//Borro enemigo
					(*it).first = x + (x - Pieza_x);
					(*it).second = y + (y - Pieza_y);
					return 1;
				
			}
			return 0;
		}
		
		
	}
	void AcDatos(damas* PT)
	{
		Fichas_A = PT->Fichas_A;
		Fichas_B = PT->Fichas_B;
		Numero_Fichas_A = PT->Numero_Fichas_A;
		Numero_Fichas_B = PT->Numero_Fichas_B;
	}

	void VISUALIZAR()
	{
		list< pair<int, int>>::iterator it1; 
		list< pair<int, int>>::iterator it2;
		int flag = 1;

		cout << " ";
		for (int j = min_X; j <= max_X; j++)
			cout << j;
		cout << endl;
		for (int i = min_Y; i <= max_Y; i++)
		{
			cout << i;
			//cout << "V1";
			for (int j = min_X; j <= max_X; j++)
			{
				flag = 1;
				//cout << "V2";
				for (it1 = Fichas_A.begin(); flag !=0 && it1 != Fichas_A.end(); it1++)
				{
					//cout << "V3.1";
					if ((*it1).first == j && (*it1).second == i)
					{
						flag = 0;
						cout << "R";
					}
				}
				for (it2 = Fichas_B.begin(); flag != 0 && it2 != Fichas_B.end(); it2++)
				{
					if ((*it2).first == j && (*it2).second == i)
					{
						flag = 0;
						cout << "N";
					}
				}
				if (flag == 1)
					cout << "-";
			}
			cout << endl;
		}
		cout << endl;
	}
	
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Nodo
{
	int nivel_max;
	int turno;

	damas* D;
	vector<Nodo*>VD;
	int Peso;
	int Mejor_Jugada;
	list<pair<int, int>>TFA;
	list<pair<int, int>>TFB;
	int numTFA;
	int numTFB;

	

	Nodo(list<pair<int, int>>fichas_A, int numero_fichas_A, list<pair<int, int>>fichas_B, int numero_fichas_B, int Turno, int nivel_maximo)
	{

		nivel_max = nivel_maximo;
		turno = Turno;
		D = new damas(fichas_A, numero_fichas_A, fichas_B, numero_fichas_B, turno);

		//D->VISUALIZAR();

		TFA = fichas_A;
		TFB = fichas_B;
		numTFA = numero_fichas_A;
		numTFB = numero_fichas_B;


		Nodo* PT;
		//Parada Fichas vacias o nivel maximo alcanzado
		if ((numTFA == 0 || numTFB == 0) || nivel_max==0)
		{
			Peso = numTFB-numTFA;
			return;
		}
		//Creacion de los hijos IZ Y DR por cada ficha jugable
		else if (Turno == 0)
		{

			for (list< pair<int, int>>::iterator it = TFA.begin(); it != TFA.end(); it++)
			{
				//cout <<"MOVER? "<< D->mover((*it).first, (*it).second, (*it).first + 1, (*it).second + 1)<<endl;
				//if((D->mover((*it).first,(*it).second, (*it).first + 1, (*it).second + 1)));
				if (D->mover((*it).first, (*it).second, (*it).first + 1, (*it).second + 1))
				{
					
					PT = new Nodo(D->Fichas_A, D->Numero_Fichas_A, D->Fichas_B, D->Numero_Fichas_B, 1, nivel_maximo-1);
					VD.push_back(PT);

					
				}
				D->Fichas_A = TFA;
				D->Fichas_B = TFB;
				D->Numero_Fichas_A = numTFB;
				D->Numero_Fichas_B = numTFB;
				if ((D->mover((*it).first, (*it).second, (*it).first - 1, (*it).second + 1)))
				{
					
					PT = new Nodo(D->Fichas_A, D->Numero_Fichas_A, D->Fichas_B, D->Numero_Fichas_B, 1, nivel_maximo-1);
					VD.push_back(PT);

				}
				D->Fichas_A = TFA;
				D->Fichas_B = TFB;
				D->Numero_Fichas_A = numTFA;
				D->Numero_Fichas_B = numTFB;
				
			}
		}
		else
		{
			for (list< pair<int, int>>::iterator it = TFB.begin(); it != TFB.end(); it++)
			{
				if (D->mover((*it).first, (*it).second, (*it).first - 1, (*it).second - 1) )
				{
					PT = new Nodo(D->Fichas_A, D->Numero_Fichas_A, D->Fichas_B, D->Numero_Fichas_B, 0, nivel_maximo-1);
					VD.push_back(PT);


				}
				D->Fichas_A = TFA;
				D->Fichas_B = TFB;
				D->Numero_Fichas_A = numTFA;
				D->Numero_Fichas_B = numTFB;

				if (D->mover((*it).first, (*it).second, (*it).first + 1, (*it).second - 1) )
				{
					PT = new Nodo(D->Fichas_A, D->Numero_Fichas_A, D->Fichas_B, D->Numero_Fichas_B, 0, nivel_maximo-1);
					VD.push_back(PT);

				}
				D->Fichas_A = TFA;
				D->Fichas_B = TFB;
				D->Numero_Fichas_A = numTFA;
				D->Numero_Fichas_B = numTFB;

			}
		}
		//Si no tiene Hijos calculo su peso final PC->1 US->0
		if (VD.size() == 0)
		{
			//Peso = D->Numero_Fichas_B - D->Numero_Fichas_A;
			Peso = numTFB - numTFA;
			return;
		}
		//Busco y encuentro la mejor jugada (por peso) y su posicion en el vector
		Peso = VD[0]->Peso;
		Mejor_Jugada = 0;
		
		for (int i = 1; i<VD.size(); i++)
		{
			if ((VD[i])->Peso > Peso)
			{
				Peso = VD[i]->Peso;
				Mejor_Jugada = i;
			}
			//VD[i]->D->VISUALIZAR();
			//cout <<"Hijo "<<i<<" Peso "<< VD[i]->Peso<<endl;
		}
		//cout <<"Hijo elegido:" << Mejor_Jugada << " Peso " << Peso  <<endl;
		//cout << "Nivel " << nivel_max<<endl;
	}
	damas* M_J()
	{
		return VD[Mejor_Jugada]->D;
	}
};
class Arbol
{
	Nodo* Padre;

	Arbol(int turno)
	{

		//Padre = new Nodo;
	}
};
////////////////////////////////////////////////////////////////////////////////////
struct juego
{
	int Dificultadad;
	damas* Damas;
	Nodo* I_A;
	juego()
	{
		Damas = new damas(7, 0, 7, 0);
	}
	void tablero()
	{
		Damas->VISUALIZAR();
	}
	void elegir_turno()
	{
		cout << "Elija turno: USUARIO->0 PC->1";
		cin >> Damas->turno;
		if (Damas->turno == 0)
		{
			cout << "R empieza" << endl;
		}
		else
		{
			cout << "N empieza" << endl;
		}

	}
	void elegir_dificultad()
	{
		cout << "Elija dificultada : ";
		cin >> Dificultadad;
	}
	void IA()
	{
		I_A = new Nodo(Damas->Fichas_A, Damas->Numero_Fichas_A, Damas->Fichas_B, Damas->Numero_Fichas_A, Damas->turno, Dificultadad);
		Damas->AcDatos(I_A->M_J());
	}
	void jugar()
	{
		int x, y;
		int pos_x, pos_y;
		while (true)
		{
			Damas->VISUALIZAR();

			if (Damas->turno == 1)
			{
				cout << "Turno: Negras" << endl;
				IA();
				Damas->turno = 0;
			}
			else
			{
				cout << "Turno: Rojas" << endl;

				cout << "Ficha_X ";
				cin >> x;
				cout << "Ficha_Y ";
				cin >> y;
				cout << "Destino_X ";
				cin >> pos_x;
				cout << "Destino_Y ";
				cin >> pos_y;

				Damas->mover(x, y, pos_x, pos_y);

				Damas->turno = 1;
			}

		}
	}
	void Partida_USvsCPU()
	{
		elegir_turno();
		elegir_dificultad();
		jugar();
	}
	void Partida_CPUvsCPU()
	{
		elegir_turno();
		elegir_dificultad();

		while (true)
		{
			IA();
			tablero();
			Damas->turno = 1;
			IA();
			tablero();
			Damas->turno = 0;

		}
		
	}

};


int main()
{
	juego JG;
	//JG.tablero();
	JG.Partida_USvsCPU();
	//JG.Partida_CPUvsCPU();
	//Nodo PRUEBA (JG.Damas->Fichas_A, JG.Damas->Numero_Fichas_A, JG.Damas->Fichas_B, JG.Damas->Numero_Fichas_A,1,7);
	
	
	/*
	//cout << JG.A->vacio(7, 1);
	JG.A->mover(1, 1, 2, 2);
	JG.tablero();

	JG.A->mover(0, 2, 1, 3);
	JG.tablero();

	JG.A->turno = 1;
	JG.A->mover(3, 5, 2, 4);
	JG.tablero();
	JG.A->turno = 0;

	JG.A->mover(1, 3, 2, 4);
	JG.tablero();
	*/

	//JG.jugar();

	//Damas.mover();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
