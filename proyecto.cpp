#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <time.h>
#include "SerialClass.h" 
#define NOM_FILE "date.txt"

using namespace std;

void estado();
void encendido();
void fecha();
void registro();
bool encontrado;


int main()
{
	int opc;
	system("cls");
	cout << "1. Ver estado del arduino." << endl;
	cout << "2. Encender o apagar alarma." << endl;
	cout << "3. Registro de activacion" << endl;
	cout << "4. Salir. " << endl;
	cout << "ingrese la opcion que desea: ";
	cin >> opc;
	if (opc <= 4)
	{
		switch (opc)
		{
		case 1:{estado(); }break;
		case 2:{encendido(); }break;
		case 3:{registro(); }break;
		case 4:{exit(0); }break;

		}
	}
	else
	{
		cout << "La opcion ingresada no es valida." << endl;
	}
	system("pause");
	return 0;
}

void estado(){
	system("cls");
	Serial* Puerto = new Serial("COM8");
	if (Puerto->IsConnected())
	{
		cout << "Conexion correcta!!!\n";
	}
	system("pause");
	main();
}

void encendido(){
	system("cls");
	if (encontrado == false)
	{
		Serial* Arduino = new Serial("COM8");
		char palabra[] = "encendido. ";
		char palabra2[] = "Alarm ON";
		cout << "Arduino conectado" << endl;
		cout << "Enviando encendido " << endl;
		Arduino->WriteData(palabra, sizeof(palabra)-1);
		Sleep(500);
		Arduino->ReadData(palabra, sizeof(palabra)-1);
		cout << "Recibido: " << palabra << endl;
		cout << "-------------------" << endl;
		if (strstr(palabra, palabra2)!= NULL)
		{
			encontrado = true;
		}
		fecha();
	}
else
{
	cout << "La alarma ya esta activada." << endl;
}
	system("pause");
	main();
}

void fecha(){
	FILE    *file;
	time_t  tiempo;
	struct  tm  *timelocal;
	char    out_time[128], d[25];

	tiempo = time(0);
	timelocal = localtime(&tiempo);
	strftime(out_time, sizeof(out_time), "%d/%m/%y  %H:%M:%S", timelocal);

	if (((file = fopen(NOM_FILE, "a")) == NULL) || ((file = fopen(NOM_FILE, "r")) == NULL))
		file = fopen(NOM_FILE, "w");

	if ((file = fopen(NOM_FILE, "a")) == NULL)
	{
		perror(NOM_FILE);
		exit(1);
	}

	fprintf(file, "%s\n", out_time);
	fclose(file);

	if ((file = fopen(NOM_FILE, "r")) == NULL)
	{
		perror(NOM_FILE);
		exit(1);
	}

	fclose(file);
}

void registro(){
	system("cls");
	char  out_time[128], d[25];
	ifstream archivo;
	archivo.open("date.txt");
	archivo >> out_time >> d;
	cout << "Registros de activacion." << endl;
	while (!archivo.eof())
	{
		cout << "activado -> " << out_time << " " << d << endl;
		archivo >> out_time >> d;
	}
	archivo.close();
	system("pause");
	main();	

}
