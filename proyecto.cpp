#include <iostream>
#include <stdlib.h>
#include <string>
#include "SerialPort.h"

using namespace std;

char outPut[MAX_DATA_LENGTH];
char *port = "\\\\.\\COM3";
char incoming[MAX_DATA_LENGTH];


int main(){

	int opcion;

        //instanciamos objeto arduino
		SerialPort arduino(port);

		//verificamos conexion
		if(arduino.isConnected()){

			cout<<"Conexion correcta!!!\n";

        //AGREGAMOS OPCIONES DE MENU SOLO DE HABER UNA CONEXION EXITOSA -------------------------------------
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

        system("pause");

	return 0;

		}else{//EN CASO DE QUE FALLE LA CONEXION -----------------------------------------------

			cout<<"Conexion incorrecta!!!!";

                        system("pause");

                        return 0;
		}
		//-------------------------------------------------------------------------------------

}

