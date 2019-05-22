#include <iostream>
#include <stdlib.h>
#include <string>
#include "SerialPort.h"

using namespace std;

char outPut[MAX_DATA_LENGTH];
char *port = "\\\\.\\COM3";
char incoming[MAX_DATA_LENGTH];

void establecer_conexion();

int main(){

	int opcion;


		//AGREGAMOS OPCIONES DE MENU
		do{
			cout<<"----------------------------Menu--------------------------------"<<endl;
			cout<<"1. opcion 1"<<endl;
			cout<<"2. opcion 2"<<endl;
			cout<<"3. opcion 3"<<endl;
			cout<<"4. opcion 4"<<endl;
			cout<<"5. Salir"<<endl;


			cin>>opcion;

			switch(opcion){

			case 1: break;
			case 2: break;
			case 3: break;
			case 4: break;
			case 5: cout<<"Saliendo del Menu"; break;
			default: break;
			}

		}while(opcion!=5);



	return 0;
}

void establecer_conexion(){

	//instanciamos objeto arduino-----------------------------------------------------------
		SerialPort arduino(port);

		//verificamos conexion-----------------------------------------------------------------
		if(arduino.isConnected()){

			cout<<"Conexion correcta!!!";
		}else{

			cout<<"Conexion incorrecta!!!!";
		}
		//--------------------------------------------------------------------------------------

		while(arduino.isConnected()){

			string comando;
			cin>>comando;

			//AGREGAMOS UN ARRAY QUE CRECERA POR CADA VUELTA
			char *matriz = new char[comnado.size() +1];

			copy(comando.begin(), comando.end(), matriz);

			matriz[comando.size()]='\n';

			arduino.write(matriz, MAX_DATA_LENGTH);
			arduino.read(outPut, MAX_DATA_LENGTH);

			cout<<outPut;

			delete [] matriz;

		}

}
