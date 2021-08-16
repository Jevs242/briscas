//Jose E Velazquez Sepulveda

#include<iostream>
#include<iomanip>
#include<string>
#include<time.h>
#include<Windows.h>

#define e '\n';

using namespace std;

struct info_juego //Variables del Juegos
{
	int cartasc = 40, igual = 2, primerarepartida[40], triunfo, puntos = 0, counter, suma1 = 7, suma2 = 8, suma3 = 9, ultimas[2], ultimas2[2];
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	bool ok = true, winolose = true, jugador2, ultima = false;


}a;

struct info_jugador //Variables del Jugador
{
	int cartasj[3], jugada, pasarescogida, escogida, vertriunfo = 0, counter = 0;
	bool ok = true;
}b;

struct info_IA //Varibles del IA o Jugador 2
{
	int cartasb[3], pasarescogida, escogida, triunfo = 0, vertriunfo = 0, puntos, counter = 0;
	bool ok = true, ok2 = true, ok3 = true;

}c;

void menu();
void repartir();
void comienzo();
void triunfo2(int x[3], int y[3], int z, int v);
void triunfo3(int x[3], int y[3]);
void jugada1(int x[3], int& y, int b[3], int a);
void repartir2(int x);
void verificacionwol(int x[3], int y[3], int z, int v);
void simbolos(int x[3]);
void simbolostrunfo(int x);
void numeros(int x[3], int i);
void numerostriunfos(int x);
void verrandomrepartir(int i[40]);
void vercartas2();
void puntos(int x[3], int y[3]);
void verificacion(int& x);
void verificacionIA();
void turnow(int x[3], int y[3]);
void turnol();

int main()
{
	
	srand(time(NULL));
	menu();
	cout << "\n\n";
	system("Pause");

}

void menu() //Menu del Juego con 3 opciones Jugar con IA 
{
	
	int opc;
	cout << "                     CARTAS BRISCAS\n" << e;
	cout << "1.Jugar contra IA | 2.Jugar contra Jugador 2 | 3.Salir" << e;
	verificacion(opc);
	switch (opc)
	{
	case 1:
		a.jugador2 = false;
		repartir();
	case 2:
		a.jugador2 = true;
		repartir();
	case 3:
		exit(1);
	default:
		menu();
		break;
	}
}

void repartir() //Funcion de hacer la primera repartida de carta 
{
	system("cls");
	cout << "Barajeando cartas";
	for (int i = 0; i < 3; i++)
	{
		Sleep(750);
		cout << ".";
	}
	
	cout << "\n";
	verrandomrepartir(a.primerarepartida);
	for (int i = 0; i < 3; i++)
	{
		b.cartasj[i] = a.primerarepartida[i];
		a.counter++;
	}
	for (int i = 3; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c.cartasb[j] = a.primerarepartida[i];
			i++;
			a.counter++;
		}
	}
	for (int i = 6; i < 7; i++)
	{
		a.triunfo = a.primerarepartida[i];
		a.counter++;
	}

	a.cartasc = a.cartasc - 7;
	comienzo();
}

void comienzo() //Esta Funcion tiene el proceso del juego
{
	int i = 0;

	//Jugador
	do {
		system("cls");
		cout << "Repartiendo cartas";
		for (int i = 0; i < 3; i++)
		{

			Sleep(250);
			cout << ".";
		}
		
		system("CLS");
		cout << setw(26) << "TURNO" << "\n" << setw(24) << i + 1 << e;
		cout << a.cartasc;
		if (a.jugador2 == false)
		{
			
			cout << "------------------->JUGANDO<-------------------\n" << e;
			cout << "LA CARTA TRIUNFO ES : ";
			simbolostrunfo(a.triunfo);
			cout << "\n-----------------------------------------------\n" << e;
			SetConsoleTextAttribute(a.color, FOREGROUND_RED);
			cout << "TUS CARTAS" << e;
			SetConsoleTextAttribute(a.color, 7);
			simbolos(b.cartasj);
		}
		if (a.jugador2 == true)
		{

			cout << "------------------->JUGANDO<-------------------\n" << e;
			cout << "LA CARTA TRIUNFO ES : ";
			simbolostrunfo(a.triunfo);
			cout << "\n-----------------------------------------------\n" << e;
			vercartas2();
		}
		if (a.jugador2 == true)
		{
			cout << "-----------------------------------------------" << e;
			cout << "LA CARTA TRIUNFO ES : ";
			simbolostrunfo(a.triunfo);
		}
		cout << "\n-----------------------------------------------" << e;
		if (a.winolose == true)
		{
			SetConsoleTextAttribute(a.color, FOREGROUND_RED);
			cout << "Tira una carta (Ingresando el # de la Izquiera)" << e;
			SetConsoleTextAttribute(a.color, 7);
			verificacion(b.pasarescogida);
			b.escogida = b.cartasj[b.pasarescogida - 1];
			cout << "-----------------------------------------------" << e;
			SetConsoleTextAttribute(a.color, FOREGROUND_RED);
			cout << "JUGADOR 1" << e;
			SetConsoleTextAttribute(a.color, 7);
			simbolostrunfo(b.escogida);
			cout << "-----------------------------------------------" << e;

			if (a.jugador2 == true)
			{
				cout << "\n";
				cout << "-----------------------------------------------" << e;
				SetConsoleTextAttribute(a.color, FOREGROUND_BLUE);
				cout << "Tira una carta (Ingresando el # de la Izquiera)" << e;
				SetConsoleTextAttribute(a.color, 7);
				verificacion(c.pasarescogida);
				cout << "-----------------------------------------------" << e;
				SetConsoleTextAttribute(a.color, FOREGROUND_BLUE);
				cout << "JUGADOR 2" << e;
				SetConsoleTextAttribute(a.color, 7);
				cout << "-----------------------------------------------" << e;
			}
			else if (a.jugador2 == false)
			{
				cout << "\n";
				cout << "-----------------------------------------------" << e;
				SetConsoleTextAttribute(a.color, FOREGROUND_BLUE);
				cout << "IA" << e;
				SetConsoleTextAttribute(a.color, 7);
				if (a.ultima == true)
				{
					verificacionIA();
				}
				else
				{
					c.pasarescogida = rand() % 3 + 1;
				}
			}


			c.escogida = c.cartasb[c.pasarescogida - 1];
			simbolostrunfo(c.escogida);
			cout << "-----------------------------------------------" << e;
		}
		else if (a.winolose == false)
		{
			if (a.jugador2 == true)
			{
				cout << "\n";
				cout << "-----------------------------------------------" << e;
				SetConsoleTextAttribute(a.color, FOREGROUND_BLUE);
				cout << "Tira una carta (Ingresando el # de la Izquiera)" << e;
				SetConsoleTextAttribute(a.color, 7);
				verificacion(c.pasarescogida);
				cout << "-----------------------------------------------" << e;
				SetConsoleTextAttribute(a.color, FOREGROUND_BLUE);
				cout << "JUGADOR 2" << e;
				SetConsoleTextAttribute(a.color, 7);
				
			}
			else if (a.jugador2 == false)
			{
				cout << "-----------------------------------------------" << e;
				SetConsoleTextAttribute(a.color, FOREGROUND_BLUE);
				cout << "IA" << e;
				SetConsoleTextAttribute(a.color, 7);
				if (a.ultima == true)
				{
					verificacionIA();
				}
				else
				{
					c.pasarescogida = rand() % 3 + 1;
				}
			}
			c.escogida = c.cartasb[c.pasarescogida - 1];
			simbolostrunfo(c.escogida);
			cout << "-----------------------------------------------" << e;
			cout << "\n";
			cout << "-----------------------------------------------" << e;
			SetConsoleTextAttribute(a.color, FOREGROUND_RED);
			cout << "Tira una carta (Ingresando el # de la Izquiera)" << e;
			SetConsoleTextAttribute(a.color, 7);
			verificacion(b.pasarescogida);
			b.escogida = b.cartasj[b.pasarescogida - 1];
			cout << "-----------------------------------------------" << e;
			SetConsoleTextAttribute(a.color, FOREGROUND_RED);
			cout << "JUGADOR 1" << e;
			SetConsoleTextAttribute(a.color, 7);
			simbolostrunfo(b.escogida);
			cout << "-----------------------------------------------" << e;
		}
		cout << "\n";
		jugada1(c.cartasb, c.vertriunfo, b.cartasj, c.pasarescogida);
		jugada1(b.cartasj, b.vertriunfo, c.cartasb, b.pasarescogida);
		triunfo2(b.cartasj, c.cartasb, b.pasarescogida, c.pasarescogida);
		a.ok = true;
		b.ok = true;
		c.ok = true;
		c.ok2 = true;
		repartir2(i);

		cout << "\n";

		system("pause");
		i++;

	} while (i != 20);
	system("cls");
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, FOREGROUND_RED);
	cout << "|PUNTOS DEL JUGADOR 1" << e;
	c.puntos = 120 - a.puntos;
	cout << a.puntos << e;
	SetConsoleTextAttribute(color, 7); 
	cout << "\n-----------------------------------------------\n" << e;
	if (a.jugador2 == false)
	{
		SetConsoleTextAttribute(color, FOREGROUND_BLUE);
		cout << "|PUNTOS DE IA" << e;
		cout << c.puntos << e;
		SetConsoleTextAttribute(color, 7);
	}
	else if (a.jugador2 == true)
	{
		SetConsoleTextAttribute(color, FOREGROUND_BLUE);
		cout << "|PUNTOS DEL JUGADOR 2" << e;
		cout << c.puntos << "\n" << e;
		SetConsoleTextAttribute(color, 7);
	}
	cout << "\n-----------------------------------------------\n" << e;
	if (a.puntos > c.puntos)
	{
		SetConsoleTextAttribute(color, FOREGROUND_RED);
		cout << "|Ganador Jugador 1|" << e;
		SetConsoleTextAttribute(color, 7);
	}
	else
	{
		if (a.jugador2 == false)
		{
			SetConsoleTextAttribute(color, FOREGROUND_BLUE);
			cout << "|Ganador IA|" << e;
			SetConsoleTextAttribute(color, 7);
		}
		else if (a.jugador2 == true)
		{
			SetConsoleTextAttribute(color, FOREGROUND_BLUE);
			cout << "|Ganador Jugador 2|" << e;
			SetConsoleTextAttribute(color, 7);
		}
	}
	cout << "\n-----------------------------------------------\n\n" << e;
	system("pause");
	exit(1);

}

void triunfo2(int x[3], int y[3], int z, int v) //Las reglas del juego
{
	if (b.vertriunfo == c.triunfo && c.triunfo == c.vertriunfo)
	{
		triunfo3(x, y);
		c.ok = false;
		c.ok2 = false;
	}
	if (c.triunfo == c.vertriunfo && c.triunfo != b.vertriunfo && c.ok == true)
	{
		turnol();
		c.ok = false;

	}
	else if (c.triunfo == b.vertriunfo && c.triunfo != c.vertriunfo && c.ok == true)
	{
		turnow(x, y);
		c.ok = false;
	}

	if (c.triunfo != b.vertriunfo && a.winolose == true && c.ok == true)
	{
		if (b.vertriunfo == c.vertriunfo)
		{
			verificacionwol(x, y, z, v);
		}
		else
		{
			turnow(x, y);
		}
	}
	else if (c.triunfo != b.vertriunfo && a.winolose == false && c.ok == true)
	{
		if (c.vertriunfo == b.vertriunfo)
		{
			verificacionwol(y, x, v, z);
		}
		else if (c.triunfo != b.vertriunfo && a.winolose == false && c.ok == true)
		{
			turnol();
		}
	}
}

void triunfo3(int y[3], int x[3]) //La regla del triunfo
{
	if (a.ok == true)
	{
		if (b.cartasj[b.pasarescogida - 1] == 1 || b.cartasj[b.pasarescogida - 1] == 11 || b.cartasj[b.pasarescogida - 1] == 21 || b.cartasj[b.pasarescogida - 1] == 31)
		{
			turnow(x, y);
		}
		else if (c.cartasb[c.pasarescogida - 1] == 1 || c.cartasb[c.pasarescogida - 1] == 11 || c.cartasb[c.pasarescogida - 1] == 21 || c.cartasb[c.pasarescogida - 1] == 31)
		{
			turnol();

		}
		else if (b.cartasj[b.pasarescogida - 1] == 3 && b.ok == true || b.cartasj[b.pasarescogida - 1] == 13 && b.ok == true || b.cartasj[b.pasarescogida - 1] == 23 && b.ok == true || b.cartasj[b.pasarescogida - 1] == 33 && b.ok == true)
		{
			turnow(x, y);
		}
		else if (c.cartasb[c.pasarescogida - 1] == 3 && b.ok == true || c.cartasb[c.pasarescogida - 1] == 13 && b.ok == true || c.cartasb[c.pasarescogida - 1] == 23 && b.ok == true || c.cartasb[c.pasarescogida - 1] == 33 && b.ok == true)
		{
			turnol();

		}
		else if (b.cartasj[b.pasarescogida - 1] > c.cartasb[c.pasarescogida - 1] && b.ok == true)
		{
			turnow(x, y);
		}
		else if (b.cartasj[b.pasarescogida - 1] < c.cartasb[c.pasarescogida - 1] && b.ok == true)
		{
			turnol();
		}
		a.ok = false;
	}
}

void jugada1(int x[3], int& y, int b[3], int a) //Identificar variables triunfo
{
	if (x[a - 1] <= 10)
	{
		y = 1;
	}
	else if (x[a - 1] <= 20 && x[a - 1] >= 11)
	{
		y = 2;
	}
	else if (x[a - 1] <= 30 && x[a - 1] >= 21)
	{
		y = 3;
	}
	else if (x[a - 1] <= 40 && x[a - 1] >= 31)
	{
		y = 4;
	}
}

void repartir2(int x) //Repartir las cartas de cada jugada
{
	
	if (a.cartasc == 1)
	{
		
		if (a.winolose == true)
		{
			for (int i = a.suma1; i < a.suma2; i++)
			{
				b.cartasj[b.pasarescogida - 1] = a.primerarepartida[i];
			}
			c.cartasb[c.pasarescogida - 1] = a.triunfo;
		}
		else if (a.winolose == false)
		{
			for (int i = a.suma1; i < a.suma2; i++)
			{
				c.cartasb[c.pasarescogida - 1] = a.primerarepartida[i];
			}
			b.cartasj[b.pasarescogida - 1] = a.triunfo;
		}
		a.cartasc--;
	}
	else if (x >= 16)
	{
		a.ultima = true;
		c.cartasb[c.pasarescogida - 1] = 0;
		b.cartasj[b.pasarescogida - 1] = 0;
		if (a.ultima == true)
		{
			a.ultimas[b.counter] = b.pasarescogida;
			if (a.jugador2 == true)
			{
				a.ultimas2[b.counter] = c.pasarescogida;
			}

			b.counter++;
		}
	}
	else
	{
		for (int i = a.suma1; i < a.suma2; i++)
		{

			b.cartasj[b.pasarescogida - 1] = a.primerarepartida[i];
		}
		a.suma1++;

		for (int i = a.suma2; i < a.suma3; i++)
		{
			c.cartasb[c.pasarescogida - 1] = a.primerarepartida[i];

		}
		a.suma2++;
		a.suma2++;
		a.suma3++;
		a.suma3++;
		a.cartasc = a.cartasc - 2;
	}
}

void verificacionwol(int x[3], int y[3], int z, int v)
{
	c.ok = true;

	if (b.cartasj[b.pasarescogida - 1] == 1 || b.cartasj[b.pasarescogida - 1] == 11 || b.cartasj[b.pasarescogida - 1] == 21 || b.cartasj[b.pasarescogida - 1] == 31)
	{
		turnow(x, y);

	}
	else if (c.cartasb[c.pasarescogida - 1] == 1 || c.cartasb[c.pasarescogida - 1] == 11 || c.cartasb[c.pasarescogida - 1] == 21 || c.cartasb[c.pasarescogida - 1] == 31)
	{
		turnol();

	}
	else if (b.cartasj[b.pasarescogida - 1] == 3 && b.ok == true || b.cartasj[b.pasarescogida - 1] == 13 && b.ok == true || b.cartasj[b.pasarescogida - 1] == 23 && b.ok == true || b.cartasj[b.pasarescogida - 1] == 33 && b.ok == true)
	{
		turnow(x, y);
	}
	else if (c.cartasb[c.pasarescogida - 1] == 3 && b.ok == true || c.cartasb[c.pasarescogida - 1] == 13 && b.ok == true || c.cartasb[c.pasarescogida - 1] == 23 && b.ok == true || c.cartasb[c.pasarescogida - 1] == 33 && b.ok == true)
	{
		turnol();

	}
	else if (b.cartasj[b.pasarescogida - 1] > c.cartasb[c.pasarescogida - 1] && b.ok == true)
	{
		turnow(x, y);
	}
	else if (b.cartasj[b.pasarescogida - 1] < c.cartasb[c.pasarescogida - 1] && b.ok == true)
	{
		turnol();
	}

}

void simbolos(int x[3]) //Añadir por cout el simbolo de la carta
{

	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << " : ";
		if (x[i] <= 10 && x[i] >= 1)
		{
			SetConsoleTextAttribute(a.color, 6);
			cout << "MONEDA DE ORO" << " ^ ";
			numeros(x, i);
			SetConsoleTextAttribute(a.color, 7);
		}
		else if (x[i] <= 20 && x[i] >= 11)
		{
			SetConsoleTextAttribute(a.color, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "COPA" << " ^ ";
			numeros(x, i);
			SetConsoleTextAttribute(a.color, 7);
		}
		else if (x[i] <= 30 && x[i] >= 21)
		{
			SetConsoleTextAttribute(a.color, 3);
			cout << "ESPADA" << " ^ ";
			numeros(x, i);
			SetConsoleTextAttribute(a.color, 7);
		}
		else if (x[i] <= 40 && x[i] >= 31)
		{
			SetConsoleTextAttribute(a.color, 2);
			cout << "BASTON" << " ^ ";
			numeros(x, i);
			SetConsoleTextAttribute(a.color, 7);
		}
		else if (x[i] == 0)
		{
			cout << "" << e;
		}

	}
}

void simbolostrunfo(int x) //Añadir por cout el simbolo de la carta del triunfo
{

	if (c.triunfo == 0)
	{
		if (x <= 10)
		{
			SetConsoleTextAttribute(a.color, 6);
			cout << "MONEDA DE ORO" << " ^ ";
			c.triunfo = 1;
			numerostriunfos(x);
			SetConsoleTextAttribute(a.color, 7);

		}
		else if (x <= 20 && x >= 11)
		{
			SetConsoleTextAttribute(a.color, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "COPA" << " ^ ";
			c.triunfo = 2;
			numerostriunfos(x);
			SetConsoleTextAttribute(a.color, 7);
		}
		else if (x <= 30 && x >= 21)
		{
			SetConsoleTextAttribute(a.color, 3);
			cout << "ESPADA" << " ^ ";
			c.triunfo = 3;
			numerostriunfos(x);
			SetConsoleTextAttribute(a.color, 7);
		}
		else if (x <= 40 && x >= 31)
		{
			SetConsoleTextAttribute(a.color, 2);
			cout << "BASTON" << " ^ ";
			c.triunfo = 4;
			numerostriunfos(x);
			SetConsoleTextAttribute(a.color, 7);
		}
	}
	else
	{
		if (x <= 10)
		{
			SetConsoleTextAttribute(a.color, 6);
			cout << "MONEDA DE ORO" << " ^ ";
			numerostriunfos(x);
			SetConsoleTextAttribute(a.color, 7);

		}
		else if (x <= 20 && x >= 11)
		{
			SetConsoleTextAttribute(a.color, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "COPA" << " ^ ";
			numerostriunfos(x);
			SetConsoleTextAttribute(a.color, 7);
		}
		else if (x <= 30 && x >= 21)
		{
			SetConsoleTextAttribute(a.color, 3);
			cout << "ESPADA" << " ^ ";
			numerostriunfos(x);
			SetConsoleTextAttribute(a.color, 7);
		}
		else if (x <= 40 && x >= 31)
		{
			SetConsoleTextAttribute(a.color, 2);
			cout << "BASTON" << " ^ ";
			numerostriunfos(x);
			SetConsoleTextAttribute(a.color, 7);
		}
	}


}

void numerostriunfos(int x)//Añadir por cout el numero de la carta del triunfo
{
	if (x == 1 || x == 11 || x == 21 || x == 31)
	{
		cout << "1" << e;
	}
	else if (x == 3 || x == 13 || x == 23 || x == 33)
	{
		cout << "3" << e;
	}
	else if (x == 2 || x == 12 || x == 22 || x == 32)
	{
		cout << "2" << e;
	}
	else if (x == 4 || x == 14 || x == 24 || x == 34)
	{
		cout << "4" << e;
	}
	else if (x == 5 || x == 15 || x == 25 || x == 35)
	{
		cout << "5" << e;
	}
	else if (x == 6 || x == 16 || x == 26 || x == 36)
	{
		cout << "6" << e;
	}
	else if (x == 7 || x == 17 || x == 27 || x == 37)
	{
		cout << "7" << e;
	}
	else if (x == 8 || x == 18 || x == 28 || x == 38)
	{
		cout << "10" << e;
	}
	else if (x == 9 || x == 19 || x == 29 || x == 39)
	{
		cout << "11" << e;
	}
	else if (x == 10 || x == 20 || x == 30 || x == 40)
	{
		cout << "12" << e;
	}


}

void numeros(int x[3], int i) //Añadir por cout el numero de la carta
{
	if (x[i] == 1 || x[i] == 11 || x[i] == 21 || x[i] == 31)
	{
		cout << "1" << e;
	}
	else if (x[i] == 2 || x[i] == 12 || x[i] == 22 || x[i] == 32)
	{
		cout << "2" << e;
	}
	else if (x[i] == 3 || x[i] == 13 || x[i] == 23 || x[i] == 33)
	{
		cout << "3" << e;
	}
	else if (x[i] == 4 || x[i] == 14 || x[i] == 24 || x[i] == 34)
	{
		cout << "4" << e;
	}
	else if (x[i] == 5 || x[i] == 15 || x[i] == 25 || x[i] == 35)
	{
		cout << "5" << e;
	}
	else if (x[i] == 6 || x[i] == 16 || x[i] == 26 || x[i] == 36)
	{
		cout << "6" << e;
	}
	else if (x[i] == 7 || x[i] == 17 || x[i] == 27 || x[i] == 37)
	{
		cout << "7" << e;
	}
	else if (x[i] == 8 || x[i] == 18 || x[i] == 28 || x[i] == 38)
	{
		cout << "10" << e;
	}
	else if (x[i] == 9 || x[i] == 19 || x[i] == 29 || x[i] == 39)
	{
		cout << "11" << e;
	}
	else if (x[i] == 10 || x[i] == 20 || x[i] == 30 || x[i] == 40)
	{
		cout << "12" << e;
	}
	else if (x[i] == 0)
	{
		cout << "" << e;
	}
}

void verrandomrepartir(int x[40]) //la funcion de barajear las cartas al principio
{
	for (int i = 0; i < 40; i++)
	{
		do
		{
			x[i] = rand() % 40 + 1;
			for (int j = 0; j + 1 < 40; j++)
			{
				if (i != j)
				{
					if (x[i] == x[j])
					{
						a.igual = 1;
						break;
					}
					else
					{
						a.igual = 2;
					}
				}
			}
		} while (a.igual != 2);
	}
}

void vercartas2() //Esta funcion es para cuando hay 2 jugadores 
{
	SetConsoleTextAttribute(a.color, FOREGROUND_BLUE);
	cout << "CARTAS DEL JUGADOR 1" << e;
	SetConsoleTextAttribute(a.color, 7);
	simbolos(b.cartasj);
	cout << "\n-----------------------------------------------\n" << e;
	system("pause");
	system("cls");
	cout << "------------------->JUGANDO<-------------------\n" << e;
	cout << "LA CARTA TRIUNFO ES : ";
	simbolostrunfo(a.triunfo);
	cout << "\n-----------------------------------------------\n" << e;
	SetConsoleTextAttribute(a.color, FOREGROUND_BLUE);
	cout << "CARTAS DEL JUGADOR 2" << e;
	SetConsoleTextAttribute(a.color, 7);
	simbolos(c.cartasb);
	cout << "\n-----------------------------------------------\n" << e;
	system("Pause");
	system("cls");
}

void puntos(int x[3], int y[3]) //Dar los puntos en cada turno ganados
{
	if (x[b.pasarescogida - 1] == 1 || x[b.pasarescogida - 1] == 11 || x[b.pasarescogida - 1] == 21 || x[b.pasarescogida - 1] == 31)
	{
		a.puntos = a.puntos + 11;
	}
	else if (x[b.pasarescogida - 1] == 3 || x[b.pasarescogida - 1] == 13 || x[b.pasarescogida - 1] == 23 || x[b.pasarescogida - 1] == 33)
	{
		a.puntos = a.puntos + 10;
	}
	else if (x[b.pasarescogida - 1] == 8 || x[b.pasarescogida - 1] == 18 || x[b.pasarescogida - 1] == 28 || x[b.pasarescogida - 1] == 38)
	{
		a.puntos = a.puntos + 2;
	}
	else if (x[b.pasarescogida - 1] == 9 || x[b.pasarescogida - 1] == 19 || x[b.pasarescogida - 1] == 29 || x[b.pasarescogida - 1] == 39)
	{
		a.puntos = a.puntos + 3;
	}
	else if (x[b.pasarescogida - 1] == 10 || x[b.pasarescogida - 1] == 20 || x[b.pasarescogida - 1] == 30 || x[b.pasarescogida - 1] == 40)
	{
		a.puntos = a.puntos + 4;
	}


	if (y[c.pasarescogida - 1] == 1 || y[c.pasarescogida - 1] == 11 || y[c.pasarescogida - 1] == 21 || y[c.pasarescogida - 1] == 31)
	{
		a.puntos = a.puntos + 11;
	}
	else if (y[c.pasarescogida - 1] == 3 || y[c.pasarescogida - 1] == 13 || y[c.pasarescogida - 1] == 23 || y[c.pasarescogida - 1] == 33)
	{
		a.puntos = a.puntos + 10;
	}
	else if (y[c.pasarescogida - 1] == 8 || y[c.pasarescogida - 1] == 18 || y[c.pasarescogida - 1] == 28 || y[c.pasarescogida - 1] == 38)
	{
		a.puntos = a.puntos + 2;
	}
	else if (y[c.pasarescogida - 1] == 9 || y[c.pasarescogida - 1] == 19 || y[c.pasarescogida - 1] == 29 || y[c.pasarescogida - 1] == 39)
	{
		a.puntos = a.puntos + 3;
	}
	else if (y[c.pasarescogida - 1] == 10 || y[c.pasarescogida - 1] == 20 || y[c.pasarescogida - 1] == 30 || y[c.pasarescogida - 1] == 40)
	{
		a.puntos = a.puntos + 4;
	}
}

void verificacion(int& x)//Verificacion de 3 opciones y de la verificacion de no repetir las cartas en la ultima jugada
{
	while (true)
	{
		cin >> x;
		
		if (!cin.good())
		{
			cout << "Solo numeros : ";
			#undef max //Quitar definicion de max() por que la libreria windows.h le crea una definicion
			cin.clear();//Borrar datos del cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//Ignora los espacios
		}
		else if (x == 0)
		{
			cout << "Opciones del 1 al 3" << e;
			cin.clear();//Borrar datos del cin
		}
		else if (x > 3)
		{
			cout << "Solo hay 3 opciones" << e;
			cin.clear();//Borrar datos del cin

		}
		else if (a.ultimas[1] == x && a.ultima == true || a.ultimas[0] == x && a.ultima == true || a.ultimas2[0] == x && a.ultima == true || a.ultimas2[1] == x && a.ultima == true)
		{

			cout << "Ya utilisaste la carta de esa posicion" << e;
			cin.clear();//Borrar datos del cin
			if (a.ultimas2[0] == x && a.ultima == true || a.ultimas2[1] == x && a.ultima == true)
			{
				
			}
		}
		else
			break;
	}

}

void verificacionIA()
{
		do
		{
			c.ok3 = false;
			c.pasarescogida = rand() % 3 + 1;
			if (c.cartasb[c.pasarescogida - 1] == 0)
			{
				c.ok3 = true;
			}

		} while (c.ok3 != false);
}

void turnow(int x[3], int y[3])
{
	cout << "-----------------------------------------------" << e;
	SetConsoleTextAttribute(a.color, FOREGROUND_RED);
	if (a.jugador2 == true)
	{
		cout << "TURNO GANADO POR JUGADOR 1" << e;
	}
	else if (a.jugador2 == false)
	{
		cout << "TURNO GANADO" << e;
	}
	puntos(x, y);
	a.winolose = true;
	b.ok = false;
	SetConsoleTextAttribute(a.color, 7);
	cout << "-----------------------------------------------" << e;
}

void turnol()
{
	cout << "-----------------------------------------------" << e;
	SetConsoleTextAttribute(a.color, FOREGROUND_BLUE);
	if (a.jugador2 == true)
	{
		cout << "TURNO GANADO POR JUGADOR 2" << e;
	}
	else if (a.jugador2 == false)
	{
		cout << "TURNO PERDIDO" << e;
	}
	a.winolose = false;
	b.ok = false;
	SetConsoleTextAttribute(a.color, 7);
	cout << "-----------------------------------------------" << e;
}

