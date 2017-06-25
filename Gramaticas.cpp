/* Universidad de Santiago de Chile
 * Facultad de Ciencia
 * Departamento de Matemática y Ciencia de la Computación
 * Licenciatura en Ciencia de la Computación
 *
   Trabajo Ayudantia: Primera Parte

 * Nombre: Nicolas Perez Poblete, Ana Karina Alvarez Ojeda.
 * Proposito: Esta entrega trata de: desarrollar un programa en C o bien C++ que sea capazde:
1. Cargar un automata finito desde un archivo de texto.
2. Permitir al usuario ingresar un automata finito.
3. Guardar un automata finito en un archivo de texto.
4. Identificar si un automata finito es determinista (AFD) o no determinista (AFND).
5. Convertir AFND a AFD
 * Fecha: 30 de Mayo del 2014

   Ayudante: Katherine Negrete.
 *

*/


#include <iostream>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <cstring>
# include <conio.h>
#define MAX 5000

using namespace std;


//--------------------------|
void menuadios();          //
void menu();               // 
void leer_archivo();       //
void recibir_automata();   //
void tipo();               //
void NFA();                //
void DFA();                //
void gramatica();          //
void ingresar_gramatica(); //
void Leer_Automata_Pila(); //
//--------------------------|

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void NFA_Modificado() // Funcion que muestra el NFA ingresado y modificado a DFA.
{
    ifstream Archivo2;
    Archivo2.open("automata_DFA.txt");
    char EstadoI[50];
    char trans;
    char Destino[50];

    Archivo2>>EstadoI;
    if(EstadoI[0] == '[')
    {
        while(!Archivo2.eof())
        {
            Archivo2>>trans;
            Archivo2>>Destino;

            cout<<"Desde el estado:  "<<EstadoI<<"  con el string  '"<<trans<<"'  va al estado:  "<<Destino<<endl;
            Archivo2>>EstadoI;

        }
        system("pause");
    }
    else
    {
        cout<<"Aun no se ha cambiado un NFA a un DFA dentro del programa."<<endl;
        system("pause");
    }

    Archivo2.close();

}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------

int convertir_char_to_int(char caracter)  // Esta funcion se encarga de transformar un tipo char a un tipo int
{                                         // para poder trabajar con listas y numeros comodamente y cuando se necesita su
    int auxiliar =0;                         // valor numerico, se transforma a un int.
    auxiliar = caracter-48;
    return auxiliar;
} 

//------------------------------------------------------------------------------------------------------------------------------------------------------------------ 

string itoa(int n) // Transforma de variable entera a string.
{
    string rtn;
    for(rtn="";n>0;rtn.insert(rtn.begin(),n%10+'0'),n/=10);
    return rtn;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

int potencia(int b,int e){ // funcion que genera el conjunto potencia para el NFA.
    int i;
    int pot=1;
    for(i=1;i<=e;i++){
          pot=pot*b;
    }
    return pot;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main() // Funcion principal.
{

	int opcion; // variable utilizada para el menu principal del programa.
    int conclusion = 0;
    while (opcion != 7) // ciclo que termina cuando el usuario quiere sali del programa.
    {
        system("cls");
        menu(); // funcion que muestra el menu y las ocpiones que tiene el usuario para ingresar.
        cin >> opcion; // Lee la variable ingresada por el usuario.
        switch(opcion) // switch que nos da 3 opciones.
        {
            case 1:
                leer_archivo(); // funcion que es para reconocer un automata alojadoen el archivo de texto principal del programa.
                conclusion++;
                system("pause"); 
                break; // termina.
            
            
            case 2:
                recibir_automata(); // Funcion que es para ingresar un automata, se guarda en el archivo principal para luego motrarlo por pantalla.
                conclusion++;
                system("pause");
                break;

            case 3:
                if( conclusion == 0 )
                {
                    ofstream Archivo2; // Para sobre escribir Archivo2 por si tiene algo escrito el archivo del NFA modificado.
                    Archivo2.open("automata_DFA.txt"); // se abre el archivo del NFA modificado para vaciarlo.
                    Archivo2<<"";
                    Archivo2.close();// se cierra el archivo del NFA modificado.
                    NFA_Modificado();
                }
                else{
                    NFA_Modificado();
                }
                break;
                system("pause");
            case 4:
                gramatica();
                system("pause");
                break;
            case 5:
                ingresar_gramatica();
                system("pause");
                break;
            case 6:
                Leer_Automata_Pila();
                system("pause");
                break;
            case 7: // salir del programa.
                system("pause");
                break;
        
    }
    system("cls");
    menuadios(); // muestra el menu de salida cuando el programa ha finalizado.
    }
    return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------


void DFA()
{
    
    ofstream p; // offstream para escribir dentro de un archivo y sobreescribir lo que anteriormente tenia.
    p.open("automata.txt"); // se abre un archivo txt con el nombre automata por defecto.
    int x,i,letras,estado; // variables enteras.
    char letrasAlf[10]; // 
    char letra2;
    int z;
    char estado_inicial; // variable char que guarda el estado inicial del automata.
    char estados_finales; // variable que recibe el o los estados finales del automata.

    ofstream Archivo2;
    Archivo2.open("automata_DFA.txt");
    Archivo2<<"";
    Archivo2.close();

    cout<<"Ingrese la cantidad de estados que tiene el automata"<<endl;
    cin>>x; // variable que recibe la cantidad de estados totales del automata.
    p<<x<<endl; // escribe la cantidad.
    cout<<"Ingrese la cantidad de strings que tiene el alfabeto"<<endl; 
    cin>>letras; // lee la cantidad de strings.
    p << letras << endl; // guarda la cantidad de strings.
    for(i=0 ; i<letras ; i++) // ciclo para ir guardando en el archivo los strings.
    {
        cout<< "Ingrese una string del alfabeto "<<endl;
        cin>> letra2; // lee un string.
        p<< letra2 <<endl; // guarda el string
        letrasAlf[i] = letra2; 
    }

    cout <<"ingrese el estado inicial: "<<endl;
    cin >> estado_inicial; // variable que recibeel estado inicial. 
    p<<estado_inicial<<" "; // guarda en el archivo el estado inicial.

    cout<<"Ingrese el o los estados finales:            NOTA: Para finalizar el ingreso de estados finales [ Ingrese '/' ]"<<endl;
    cout<<"- "<<endl;
    cin>>estados_finales; // lee el o los estados finales del automata.
    while(estados_finales!='/') // ciclo que los va ingresando si fueran mas de uno hasta que el usuario ingrese un '/'.
    {
        p<<estados_finales<<" "; // escribe los estados finales del automata en un archivode texto.
        cout<<"- "<<endl; // mientra este esto, el usuario debe ingresar estados.
        cin>>estados_finales;
    }

    p<<"/"<<endl; // guarda un / en el archivo para indicar el final de los estados finales del automata.
    
    estado = 0;
    for(i = 0 ;i < x; i++){ // este ciclo genera el ingreso de todos los estados con todos los strings.
          for(int o = 0; o < letras ; o ++)
          {
              cout<<"del estado '"<<estado <<"' con la letra '"<< letrasAlf[o] << "' va al estado:"<<endl; 
              cin>>z;
              
              if (i+1 == x && o == letras - 1)
              {
                  p<<estado<<" "<<letrasAlf[o] <<" "<<z;
              }
              else
              {
                  p<<estado<<" "<<letrasAlf[o] <<" "<<z <<endl;
              }
          }
          estado++;               
   }
    
   p.close(); 
   system("pause");
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void NFA() // funcion que ingresa un NFA 
{
    ofstream Archivo2;
    Archivo2.open("automata_DFA.txt");
    Archivo2<<"";
    Archivo2.close();

    ofstream p; // offstream para escribir dentro de un archivo y sobreescribir lo que anteriormente tenia.
    p.open("automata.txt"); // se abre un archivo txt con el nombre automata por defecto.

    int x,i,letras,estado; // variables enteras.
    char letrasAlf[10];
    char letra2;
    int z;
    char estado_inicial; // variable char que guarda el estado inicial del automata.
    char estados_finales; // variable que recibe el o los estados finales del automata.

    cout<<"Ingrese la cantidad de estados que tiene el automata: "<<endl;
    cin>>x;// variable que recibe la cantidad de estados totales del automata.
    p<<x<<endl;
    cout<<"Ingrese la cantidad de strings que tiene el alfabeto: "<<endl;
    cin>>letras; // lee la cantidad de strings.
    p << letras << endl;// guarda la cantidad de strings.
    for(i=0 ; i<letras ; i++) // ciclo que es para guardar los strings del alfabeto hasta que el usuario ingrese un ' / '.
    {
        cout<< "Ingrese una string del alfabeto: "<<endl;
        cin>> letra2;
        p<< letra2 <<endl; // escribe los strings en el archivo.
        letrasAlf[i] = letra2;
    }

    cout <<"ingrese el estado inicial: "<<endl;
    cin >> estado_inicial; // lee el estado inicial.
    p<<estado_inicial<<" ";

    cout<<"Ingrese el o los estados finales:            NOTA: Para finalizar el ingreso de estados finales [ Ingrese '/' ]"<<endl;
    cout<<"- "<<endl;
    cin>>estados_finales;
    while(estados_finales!='/') // ciclo que lee los estados finales.
    {
        p<<estados_finales<<" ";
        cout<<"- "<<endl;
        cin>>estados_finales;

    }
    p<<"/"<<endl; 
    estado = 0;
    int t = 0, h=0;
    char simbolo;

    cout<<endl;
    cout<<"|----------------------------------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout<<"|                                                           Recordatorio.                                                                      |"<<endl;
    cout<<"|----------------------------------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout<<"| Si el estado actual va a un estado o a un conjunto de estados, para denotar que termino de ingresar los estados, ingrese un ']'              |"<<endl;
    cout<<"| Si el estado actual no tiene transicion con el string actual ingrese un 'N' o 'n' y luego un ']'                                             |"<<endl;        
    cout<<"|----------------------------------------------------------------------------------------------------------------------------------------------|"<<endl;

    while (h != letras)
    {
        for(i = 0 ;i < x; i++)
        { 
            cout<<endl;
            cout<<endl;
            cout<< "Del estado "<< estado << " con la letra "<< letrasAlf[t] <<" va a los estados: "<<endl;
            p<<estado<<" "<<letrasAlf[t]<<" [ ";
            while (simbolo != ']')
            {
                cout<<"Ingrese simbolo:          NOTA: Si finaliza el ingreso de estados, ingrese un ] ."<<endl;
                cin>> simbolo;
                if (simbolo!= ']' && simbolo!= 'N' &&  simbolo!= 'n')
                {
                    p<<simbolo<<" ";
                }
                if (simbolo != ']' && (simbolo == 'n' || simbolo == 'N'))
                {
                    p<<" ";
                }
            }
            if(h == letras -1 && estado == x-1)
                p<<"]";
            else
                p<<"]"<<endl;
            estado++;
            simbolo = '!';

        }
        t++;
        estado = 0;
        h++;
    }
    
   p.close(); 
   system("pause");

}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void leer_archivo() // Funcion mas importante del programa que lee los automatas desde el archivo de texto principal.
{
    ofstream Archivo2; // Para sobre escribir Archivo2 por si tiene algo escrito el archivo del NFA modificado.
    Archivo2.open("automata_DFA.txt"); // se abre el archivo del NFA modificado para vaciarlo.
    Archivo2<<"";
    Archivo2.close();// se cierra el archivo del NFA modificado.   archivo.open(nombre)

	char c,signo, cambio;  // 
	char Estados[50];      // Estados del automata.
	int estados,cant_letras; // cantidad de estados y cantidad de strings del automata.
	char Letras[30];   // es una variable que guarda en si los strings del automata.
	char matriz[50][50]; // Variables para el funcionamiento de la funcion.
    int DFA_NFA = 0; //  variable para reconocer si  el automata es DFA o NFA.
    char estado_inicial; //  Variable que guarda el estado inicial.
    char simbolo2;   //  
    char estados_finales[10]; //
    int cont = 0; //
    int Q = 0; //

	ifstream Archivo; // ifstream para sacar informacion del archivo.
	Archivo.open("automata.txt"); // SE ABRE EL ARCHIVO PRINCIPAL DEL PROGRAMA.
	
    if (Archivo.fail())      // chequea que el archivo exista .
    {
        cout<<"\n\n\n              Archivo no existe";
        system("PAUSE");
        exit (1);       //  aborta el programa si el archivo no existe
    }	
	
    while(!Archivo.eof()) // hasta que llega al final, muestra los componentes del archivo.
    {
        Archivo >> estados; // lee la cantidad de estados
        Archivo >> cant_letras; // lee la cantidad de letras del automata.
        
        for (int i = 0 ; i < cant_letras ; i++) // ciclo for para ingresar los strings del alfabeto.
        {
        	Archivo >> Letras[i]; // lee los strings del alfabeto.
        }
        
        int i,j;
        i=0;
        j=0;

        Archivo >> estado_inicial; // Lee el estado inicial que en este programa siempre sera uno.
        Archivo>> simbolo2; // valida el simbolo / 

        while(simbolo2 != '/') // ciclo que valida para ingresar estados finales hasta que lea un /.
        {
            estados_finales[Q] = simbolo2;
            Q++;
            Archivo>>simbolo2;
        }
                
        while(!Archivo.eof()) // mientras no se llegue al final del archivo.
        {
        	Archivo >> Estados[i]; // lee el primer estado.
            cambio = Estados[i];
        	Archivo >> c; // lee el string siguiente
        	Archivo >> signo; // lee el simbolo clave

        	if (signo == '[') // si lo que lee la funcion es un [, es porque es un NFA por lo tanto lo manda a la parte que corresponde .]
        	{
                DFA_NFA = 2; // Este valor es igual a 2 si el automata leido es un NFA.
                system("cls");
                cout<<"**********************************************************************"<<endl;
                cout<<"*   El automata reconocido desde el archivo de texto es un [ NFA ]   *"<<endl;
                cout<<"**********************************************************************"<<endl;
                cout<<endl;

        		while (signo != ']') // ciclo que mientras no lea un ] sigue ingresando estados destino en una transicion a una matriz que guarda los estados destino.
                {
        			Archivo >> signo;
        			if (signo != ']')
        			{
        				matriz[i][j] = signo;
        			}
                    else
                    {
                        matriz[i][j] = signo;
                    }
                    j++;
                }
        	    i++;
        	    j = 0;
        	}
			if (DFA_NFA != 2)
			{
                DFA_NFA = 1; // si el automata no es un NFA, esta valor es 1.

                cout<<"**********************************************************************"<<endl;
                cout<<"*   El automata reconocido desde el archivo de texto es un [ DFA ]   *"<<endl; // si lee un DFA, lo muestra por pantalla.
                cout<<"**********************************************************************"<<endl;
                cout<<endl;

                cout<<" El estado inicial es: ("<< estado_inicial<<")"<<endl;
                cout<<" El o los estados finales son: ";

                while(cont < Q)
                {
                    cout<<"("<<estados_finales[cont]<<") ";
                    cont++;
                }
                cout<<endl;
                cout<<endl;
				while(!Archivo.eof()) // mientras no llegue al final del archivo, muestra el DFA completo.
                {
                    cout << "Del estado (" <<cambio<<")  con el string '"<<c<<"' ----> ("<<signo<<") "<<endl;
                    Archivo >> cambio;
                    Archivo >> c;
                    Archivo >> signo;

                }
			}
        }
    }

    cout<<endl;
    cout<<endl;

    if (DFA_NFA == 2) // si el automata es un NFA ingresa a este if para modificarlo.
    {
        ofstream Archivo2;
        Archivo2.open("automata_DFA.txt");
        int estados22 = 0;
        int estados33 = 0;
        estados22 = estados;
        estados33 = estados;

        cout <<"Cantidad de estados:  "<< estados <<endl; // muestra la cantidad de estados.
        cout <<"Cantidad de strings:  " << cant_letras<<endl; // muestra la cantidad de strings.
        cout <<"Strings: "; //

        for (int i = 0 ; i < cant_letras ; i++)// muestra los strings del alfabeto.
        {
            cout<< Letras[i] << " " ;
        }
        cout<<endl;
        cout<<endl;
        cout<<"El estado inicial es: ("<< estado_inicial<<")"<<endl; // muestra el estado inicial.
        cout<<"El o los estados finales son: ";

        while(cont < Q)
        {
            cout<<"("<<estados_finales[cont]<<") "; // ciclo que muestra los estados finales.
            cont++;
        }
        cout<<endl;
        cout<<endl;

        int h = 0, i = 0, j = 0;
    
        while(i != estados*cant_letras) // funcion que muestra el NFA tal y como esta definido, no modificado.
        {

            if (i == estados22)
            {
                j ++;
                estados22 = estados22 + estados33;
            }

            cout<<endl;
    	    cout <<"Desde el estado ("<<Estados[i] << ")  con el string '"<< Letras[j] << "'  va al o los estados: "<<endl;
            cout<<"[ ";
            while(matriz[i][h] != ']')// funcion que muestra los estados destino que estan guardados en la matriz.
            {
                cout<<matriz[i][h]<<" ";
                h++;
            }
            cout<<"]";
            cout<<endl;
            h = 0;
            i++;
    	
        }

        cout<<endl;
        cout<<endl;
    
        Archivo.close(); //cierra el archivo 3.
        system("PAUSE");
        system("cls");  // limpia la pantalla.

        int limite, numero;
        char A[100];
        limite = estados;
    
        for(int i=0;i<limite;i++) //
        {
            if(i == 0)
            {
                A[i]= '0';  
            }
            else
            {
                char *B = new char[itoa(i).length() + 1]; // funcion que transforma a string un char para poder trabajar con el conjunto portencia.
                std::strcpy(B, itoa(i).c_str());  
                A[i]= B[0];         
            }

        }
        char Estados_Finales[50];
        cout<<" Conjunto potencia de la cantidad de estados : "<<endl; // muestra el conjunto potencia de la cantidad de estados.
        cout<<endl;

        int contador = 0;

        for(int i=0;i<potencia(2,limite);i++) // ciclo que muestra el conjunto potencia utilizando como referencia la cantidad de estados del NFA.
        {
            cout<<"(";
            for(int j=0;j<limite;j++)
            {

                if(i & (1<<j))
                {
                    cout<<A[j];
                }
            }
            cout<<")";
            cout<<endl;
        }

        int x = 0;
        int mult = 0;
        while(x < cant_letras) // utilizando el conjunto potencia, accedemos a la matriz y mostramos los estados por posicion.
        {
            int h = 0, h1 = 0, contador2 = 0; // variables enteras.

            for(int i=0;i<potencia(2,limite);i++) // se llama a la funcion del conjunto potencia.
            {
                h1=0; 
                for(int j=0;j<limite;j++)
                {   
                    if(i & (1<<j))
                    {
                        contador2++;
                        if(contador2 > 1)
                        {
                            contador++;
                            h1++;
                            Estados_Finales[h1] = A[j];
                        }
                        else
                        {
                            contador++;
                            Estados_Finales[h1] = A[j];                   
                        }
                    }
                }
                contador2 = 0;
                cout<<endl;
                cout<<endl;
                char segunda_matriz[100][100];
                char estados2[100];

                cout<<"Del estado: [ "; // desde el estado generado por la funcion del conjunto potencia.
                Archivo2<<"[";
                for(int g = 0; g < contador ; g++) // ciclo que genera los numeros del estado.
                {
                    cout<<Estados_Finales[g]<<" ";
                    Archivo2<<Estados_Finales[g];
                }
                cout<<"]   ";
                Archivo2<<"] ";
                cout<<"con el string '"<<Letras[x]<<"' va al estado ------>   [ "; // con el string especifico.
                Archivo2<<Letras[x]<<" [";
                for(int g = 0; g < contador ; g++)
                {
                    numero = convertir_char_to_int(Estados_Finales[g]); // se llama la funcion de convertir un char a un int para tener acceso a los espacio de la matriz.
                    while(matriz[numero + mult][h] != ']')
                    {
                        cout<<matriz[numero + mult][h]<<" "; // se muestran los estados de la matriz en especifico.
                        Archivo2<<matriz[numero + mult][h];
                        h++;
                    }
                    h = 0;
                }
                cout<<"]  "<<endl;
                Archivo2<<"]"<<endl;



                contador = 0;
                h = 0;
                Estados_Finales[50] = NULL;
                cout<<endl;
            }
            mult = mult + estados;
            x++;
        }

        Archivo2.close();
        system("pause"); 
        system("cls"); 
    }

    if ( DFA_NFA == 1)
    {
        system("pause");
        system("cls");
    } 
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void recibir_automata() // Funcion que se encarga de dar a elegir al usuario que tipo de automata ingresar.
{
    system("cls");
    int opcion =0;
    cout<<"|----------------------------------------------------------------------------------|"<<endl;
    cout<<"|                     Ingrese el tipo de automata a ingresar                       |"<<endl;
    cout<<"|----------------------------------------------------------------------------------|"<<endl;
    cout<<endl;
    cout<<endl;

    tipo();

    cin>>opcion;
    switch(opcion)
    {
        case 1:
            DFA(); // para ingresar un automata DFA.
            system("pause");
            break;
        case 2:
            NFA(); // para ingresar un automata NFA.
            system("pause");
            break;
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void ingresar_gramatica()
{
     system("cls");
    char nombre[50];
    int numero1;
    int numero2;
    char Simbolo;
    int contador = 0;
    cout<<"Ingrese el nombre para el archivo "<<endl;
    cin>> nombre;
    ofstream Archivo;
    Archivo.open(nombre);

    cout<<"Ingrese cantidad de gramaticas: [ A, T, etc ]"<<endl;
    cin>>numero1;

    Archivo<<numero1<<endl;
    cout<<"Ingrese cantidad de terminales: [ a, 0, 1, etc ]"<<endl;
    cin>> numero2;
    Archivo<<numero2<<endl;

    while(contador != numero1)
    {
        cout<<"Ingrese las gramaticas especificas: "<<endl;
        cin>>Simbolo;
        Archivo<<Simbolo<<endl;
        contador++;
    }
    contador = 0;
    while(contador != numero2)
    {
        cout<<"Ingrese las terminales especificas: "<<endl;
        cin>>Simbolo;
        Archivo<<Simbolo<<endl;
        contador++;
    }

    int i = 0;

    while(i != numero1)
    {
        cout<<"Ingrese simbolo: "<<endl;
        cin>>Simbolo;
        while(Simbolo != '/')
        {
            Archivo<<Simbolo<<" ";
            cout<<"Ingrese simbolo: "<<endl;
            cin>>Simbolo;
        }
        if(i == numero1 - 1)
        {
            Archivo<<" /";
            i++;
        }
        else
        {
            Archivo<<" /"<<endl;
            i++;
        }
    }
    Archivo.close();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void gramatica() // Funcion que muestra el NFA ingresado y modificado a DFA.
{
    system("cls");
    ifstream Archivo_Gramatica;
    ofstream Archivo_Automata_Pila;

    char nombre_archivo[50];
    char nombre_archivo2[50];

    cout<<"Ingrese el nombre del archivo que contiene la gramatica: "<<endl;
    cin>>nombre_archivo;
    Archivo_Gramatica.open(nombre_archivo);
    
    if (Archivo_Gramatica.fail())      // chequea que el archivo exista .
    {
        cout<<"\n\n\n              Archivo no existe";
        system("PAUSE");
        exit (1);       //  aborta el programa si el archivo no existe
    }

    int terminales = 0;
    int gramaticas = 0;

    int espacios = 0;
    char lector;
    char matriz_gramatica[50][50];
    char GramaticasL[50];
    char TerminalesL[50];
    int i = 0;
    int j = 0;
    int contador = 0;

    Archivo_Gramatica>>gramaticas;
    Archivo_Gramatica>>terminales;

    cout<<endl;
    cout<<endl;
    cout<<"El archivo contiene los siguientes datos:"<<endl;
    cout<<endl;
    cout<<"Gramaticas "<<gramaticas<<endl;
    cout<<"Terminales "<<terminales<<endl;

    while(i != gramaticas)
    {
        Archivo_Gramatica>>GramaticasL[i];
        i++;
    }
    i = 0;
    while(i != terminales)
    {
        Archivo_Gramatica>>TerminalesL[i];
        i++;
    }
    i = 0;

    while(i != gramaticas)
    {
        Archivo_Gramatica>>lector;
        while(lector != '/')
        {
            matriz_gramatica[i][j] = lector;
            j++;
            Archivo_Gramatica>>lector;
        }
        matriz_gramatica[i][j] = lector;
        i++;
        j=0;
    }
    i = 0;
    j = 0;

    while(i != gramaticas)
    {
        while(matriz_gramatica[i][j] != '/')
        {
            cout<<matriz_gramatica[i][j];
            j++;
        }
        i++;
        j=0;
        cout<<endl;
    }
    i = 0;
    j = 0;
    cout<<endl;    
    cout<<endl;
    system("pause");

    cout<<"Ingrese el nombre del archivo donde guardara el Automata de pila: "<<endl;
    cin>>nombre_archivo2;
    cout<<endl;
    cout<<endl;
    Archivo_Automata_Pila.open(nombre_archivo2);

    cout<<"El Automata de pila es el Siguiente: "<<endl;
    int esta2 = 0;
    cout<<"(qStart) --- [E,E -> $] ---> ( "<<esta2<<" ) ---- [E,E ->"<<GramaticasL[i]<<"] ---> (qLoop)"<<endl;
    Archivo_Automata_Pila<<"(qStart) --- [E,E -> $] ---> ( "<<esta2<<" ) ---- [E,E ->"<<GramaticasL[i]<<"] ---> (qLoop) |"<<endl;
    esta2++;
    while(i != terminales)
    {
        cout<<"(qLoop) --- ["<<TerminalesL[i]<<","<<TerminalesL[i]<<" -> E] ---> (qLoop) "<<endl;
        Archivo_Automata_Pila<<"(qLoop) --- ["<<TerminalesL[i]<<","<<TerminalesL[i]<<" -> E] ---> (qLoop) |"<<endl;
        i++;
    }

    i = 0;
    j = 0;
    contador = 0;

    // GramaticasL[i]
    // TerminalesL[i]

    while(i != gramaticas)
    {
        contador = 0;
        while(matriz_gramatica[i][j] != '/')
        {
            contador ++;
            j++;
        }
        contador--;
        j=0;

        while(matriz_gramatica[i][contador] != '-')
        {
            if(matriz_gramatica[i][contador + 1] == '/' && matriz_gramatica[i][contador - 1] == '|')
            {
                cout<<"(qLoop) --- [E,"<<GramaticasL[i]<<" -> "<<matriz_gramatica[i][contador]<<"] ---> (qLoop) "<<endl;
                Archivo_Automata_Pila<<"(qLoop) --- [E,"<<GramaticasL[i]<<" -> "<<matriz_gramatica[i][contador]<<"] ---> (qLoop) |"<<endl;
                contador--;
            }
            else if(matriz_gramatica[i][contador + 1] == '|' && matriz_gramatica[i][contador - 1] == '|')
            {
                cout<<"(qLoop) --- [E,"<<GramaticasL[i]<<" -> "<<matriz_gramatica[i][contador]<<"] ---> (qLoop) "<<endl;
                Archivo_Automata_Pila<<"(qLoop) --- [E,"<<GramaticasL[i]<<" -> "<<matriz_gramatica[i][contador]<<"] ---> (qLoop) |"<<endl;
                contador--;
            }
            else
            {
                if(matriz_gramatica[i][contador] != '/' && matriz_gramatica[i][contador] != '|' && matriz_gramatica[i][contador] != '-' )
                {
                    while(matriz_gramatica[i][contador - 1] != '|' && matriz_gramatica[i][contador - 1] != '-' && matriz_gramatica[i][contador] != '-')
                    {
                        if(matriz_gramatica[i][contador + 1] == '|' || matriz_gramatica[i][contador + 1] == '/')
                        {
                            cout<<"(qLoop) --- [E,"<<GramaticasL[i]<<" -> "<<matriz_gramatica[i][contador]<<"] ---> ( "<<esta2<<" ) "<<endl;
                            Archivo_Automata_Pila<<"(qLoop) --- [E,"<<GramaticasL[i]<<" -> "<<matriz_gramatica[i][contador]<<"] ---> ( "<<esta2<<" ) |"<<endl;
                            contador--;
                            if(matriz_gramatica[i][contador - 1] == '|' || matriz_gramatica[i][contador - 1] == '-')
                            {
                                cout<<"( "<<esta2<<" ) --- [E,E -> "<<matriz_gramatica[i][contador]<<"] ---> (qLoop) "<<endl;
                                Archivo_Automata_Pila<<"( "<<esta2<<" ) --- [E,E -> "<<matriz_gramatica[i][contador]<<"] ---> (qLoop) |"<<endl;
                                contador--;
                                esta2++;
                            }
                        }
                        else
                        {
                            if(matriz_gramatica[i][contador] != '|')
                            {
                                cout<<"( "<<esta2<<" ) --- [E,E -> "<<matriz_gramatica[i][contador]<<"] ---> ( "<<esta2+1<<" )"<<endl;
                                Archivo_Automata_Pila<<"( "<<esta2<<" ) --- [E,E -> "<<matriz_gramatica[i][contador]<<"] ---> ( "<<esta2+1<<" ) |"<<endl;
                                contador--;
                                esta2++;
                            }
                            else
                            {
                                contador--;
                            }
                            if(matriz_gramatica[i][contador - 1] == '|' || matriz_gramatica[i][contador - 1] == '-')
                            {
                                cout<<"( "<<esta2<<" ) --- [E,E -> "<<matriz_gramatica[i][contador]<<"] ---> (qLoop) "<<endl;
                                Archivo_Automata_Pila<<"( "<<esta2<<" ) --- [E,E -> "<<matriz_gramatica[i][contador]<<"] ---> (qLoop) |"<<endl;
                                contador--;
                                esta2++;
                            }
                        }
                    }
                }
                else
                {
                    contador--;
                }
            }
        }
        i++;

    }    
    cout<<"(qLoop) --- [E,$ -> E] ---> (Qacept) "<<endl;
    cout<<endl;
    system("pause");
    Archivo_Automata_Pila<<"(qLoop) --- [E,$ -> E] ---> (Qacept) |";
    Archivo_Gramatica.close();
    Archivo_Automata_Pila.close();

}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Leer_Automata_Pila()
{
    system("cls");
    ifstream Archivo;
    char nombre[50];
    cout<<"Ingrese el nombre del Archivo que contiene un Automata de Pila modificado: "<<endl;
    cin>> nombre;
    Archivo.open(nombre);

    if (Archivo.fail())      // chequea que el archivo exista .
    {
        cout<<"\n\n\n              Archivo no existe";
        system("PAUSE");
        exit (1);       //  aborta el programa si el archivo no existe
    }

    char Lector_automata[50];


    Archivo>>Lector_automata;
    if(Lector_automata[0] == '(')
    {
        while(!Archivo.eof())
        {
            if(Lector_automata[0] != '|'){
                cout<<Lector_automata<<" ";
                Archivo>>Lector_automata;
            }
            else
            {
                Archivo>>Lector_automata;
                cout<<endl;
            }

        }
        cout<<endl;
        system("pause");
    }
    else
    {
        cout<<"El archivo abierto no contiene un automata de pila."<<endl;
        system("pause");
    }

    Archivo.close();

}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void menu()
{
    cout<<"             ******************************************************************************************************************"<<endl;
    cout<<"             ******************************************************************************************************************"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                              Programa de Automatas                                             *"<<endl;
    cout<<"             *      -----------------------------------------------------------------------------------------------------     *"<<endl;  // MENU PRINCIPAL.
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *        1.- Cargar un automata desde un Archivo de Texto.                                                       *"<<endl;
    cout<<"             *        2.- Ingresar Automata manualmente.                                                                      *"<<endl;
    cout<<"             *        3.- Cargar un NFA Modificado.                                                                           *"<<endl;
    cout<<"             *        4.- Cargar una Gramatica desde un Archivo de Texto y transformarla a un Automata de Pila.               *"<<endl;
    cout<<"             *        5.- Ingresar manualmente una Gramatica.                                                                 *"<<endl;
    cout<<"             *        6.- Cargar un automata de pila desde un Archivo de texto.                                               *"<<endl;    
    cout<<"             *        7.- Salir del programa.                                                                                 *"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             ******************************************************************************************************************"<<endl;
    cout<<"             ******************************************************************************************************************"<<endl;

}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void menuadios()
{
    cout<<"             ******************************************************************************************************************"<<endl;
    cout<<"             ******************************************************************************************************************"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                     Programa de Automatas Finalizado                                           *"<<endl;
    cout<<"             *      -----------------------------------------------------------------------------------------------------     *"<<endl;  // MENU Adios.
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                                                                                                *"<<endl;    
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             *                                                                                                                *"<<endl;
    cout<<"             ******************************************************************************************************************"<<endl;
    cout<<"             ******************************************************************************************************************"<<endl;

}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void tipo()
{

    cout<<"        ************************************************************************************************************"<<endl;
    cout<<"        ************************************************************************************************************"<<endl;
    cout<<"        *                                                                                                          *"<<endl;
    cout<<"        *                                                                                                          *"<<endl;
    cout<<"        *    1.- Automata ( DFA )                                                                                  *"<<endl;
    cout<<"        *                                                                                                          *"<<endl;
    cout<<"        *    2.- Automata ( NFA )                                                                                  *"<<endl;
    cout<<"        *                                                                                                          *"<<endl;
    cout<<"        *                                                                                                          *"<<endl;
    cout<<"        *                                                                                                          *"<<endl;
    cout<<"        ************************************************************************************************************"<<endl;
    cout<<"        ************************************************************************************************************"<<endl;
}