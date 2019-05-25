#include <iostream>
#include <stdlib.h>
#include "SerialClass.h" 

using namespace std;

void estado();
void encendido();


int main()
{
	int opc;
	system("cls");
	cout << "1. Ver estado del arduino." << endl;
	cout << "2. encender o pagar." << endl;
	cout << "3. Salid. " << endl;
	cout << "ingrese la opcion que desea: ";
	cin >> opc;
	if (opc <= 3)
	{
		switch (opc)
		{
		case 1:{estado(); }break;
		case 2:{encendido(); }break;
		case 3:{exit(0); }break;

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
	Serial* Puerto = new Serial("COM8");

	// Comandos para Arduino.
	char Luz_ON[] = "Luz_ON"; // Envía "Luz_ON" al puerto serie.
	char lectura[50] = "\0"; // Guardan datos de entrada del puerto.
	
	Puerto->IsConnected();
	// Encener luz.
	cout << "Enviando: " << Luz_ON << endl; // Muestra en pantalla textos.
	Puerto->WriteData(Luz_ON, sizeof(Luz_ON)-1); // Envía al puerto el texto "Luz_ON"
}
