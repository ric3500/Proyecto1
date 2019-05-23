#include <iostream>
#include <stdlib.h>
#include "SerialPort.h"

using namespace std;

char outPut[MAX_DATA_LENGTH];
char *port = "\\\\.\\COM3";
char incoming[MAX_DATA_LENGTH];



int main(){

	int opcion;

                //instanciamos objeto arduino-----------------------------------------------------------
		SerialPort arduino(port);

		//verificamos conexion-----------------------------------------------------------------
        if(arduino.isConnected()){

            cout<<"Conexion correcta!!!\n";

                        //AGREGAMOS OPCIONES DE MENU SOLO DE HABER UNA CONEXION EXITOSA
		do{
                    cout<<"----------------------------Menu--------------------------------"<<endl;
                    cout<<"1. opcion 1"<<endl;
                    cout<<"2. opcion 2"<<endl;
                    cout<<"3. opcion 3"<<endl;
                    cout<<"4. Salir"<<endl;


                    cin>>opcion;

                if(opcion==1){

                            char respuesta = 'n';
                            string comando;

                            while(arduino.isConnected() && respuesta == 'n'){

                                cout<<"Ingrese la funcion que desea Ejecutar (ON/OFF)"<<endl;

                                cin>>comando;

                                //AGREGAMOS UN ARRAY QUE CRECERA POR CADA VUELTA
                                char *matriz = new char[comando.size() +1];

                                copy(comando.begin(), comando.end(), matriz);

                                matriz[comando.size()]='\n';

                                arduino.writeSerialPort(matriz, MAX_DATA_LENGTH);
                                arduino.readSerialPort(outPut, MAX_DATA_LENGTH);

                                cout<<outPut;

                            delete [] matriz;

                            cout<<"Desea realizar otra funcion (Si = s/ No = n)"<<endl;
                            cin>>respuesta;

                        }

                    }else if(opcion==2){

                            cout<<"opcion 2"<<endl;

                    }else if(opcion==3){

                            cout<<"opcion 3"<<endl;

                    }else{

                        cout<<"Opcion no valida"<<endl;
                    }

		}while(opcion!=4);

        system("pause");



		}else{

			cout<<"Conexion incorrecta!!!!";

                        system("pause");


		}
		//-------------------------------------------------------------------------------------
	return 0;
}



