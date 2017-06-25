/* Universidad de Santiago
 * Facultad de Ciencia
 * Departamento de Matemática y Ciencia de la Computación
 * Licenciatura en Ciencia de la Computación
 *
 * Nombre: Nicolas Perez Poblete.
 * Proposito:
 * Fecha:
 *
 * IDE: Code::Blocks 12.05
 * Compilador: GNU GCC Compiler

*/


#include <iostream>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#define MAX 5000

using namespace std;

void menuadios();
void menu();
void leer_archivo();
void ingreso_manual();
void recibir_automata();
void tipo();
void NFA();
void DFA();

int main()
{
	int opcion;
	
	menu();
	cin >> opcion;
	switch(opcion)
	{
		case 1:
			leer_archivo();
			break;
			
			
		case 2:
            recibir_automata();
			break;
		
	}
    menuadios();
    
    return 0;
	
}

void DFA()
{
    
    ofstream p;
    p.open("automata.txt");
    int x,i,letras,estado;
    char letrasAlf[10];
    char letra2;
    int z;
    cout<<"Ingrese la cantidad de estados que tiene el automata"<<endl;
    cin>>x;
    p<<x<<endl;
    cout<<"Ingrese la cantidad de letras que tiene el alfabeto"<<endl;
    cin>>letras;
    p << letras << endl;
    for(i=0 ; i<letras ; i++)
    {
        cout<< "Ingrese una letra del alfabeto "<<endl;
        cin>> letra2;
        p<< letra2 <<endl;
        letrasAlf[i] = letra2;
    }
    
    estado = 0;
    for(i = 0 ;i < x; i++){
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

void NFA()
{

    ofstream p;
    p.open("automata.txt");
    int x,i,letras,estado;
    char letrasAlf[10];
    char letra2;
    int z;
    cout<<"Ingrese la cantidad de estados que tiene el automata"<<endl;
    cin>>x;
    p<<x<<endl;
    cout<<"Ingrese la cantidad de letras que tiene el alfabeto"<<endl;
    cin>>letras;
    p << letras << endl;
    for(i=0 ; i<letras ; i++)
    {
        cout<< "Ingrese una letra del alfabeto "<<endl;
        cin>> letra2;
        p<< letra2 <<endl;
        letrasAlf[i] = letra2;
    }
    
    estado = 0;
    int t = 0, h=0;
    char simbolo;

    while (h != letras)
    {

        for(i = 0 ;i < x; i++)
        { 

            cout<< "Del estado "<< estado << " con la letra "<< letrasAlf[t] <<" va a los estados: "<<endl;
            p<<estado<<" "<<letrasAlf[t]<<" [ ";
            while (simbolo != ']')
            {
                cin>> simbolo;
                p<<simbolo<<" ";
            }
            if(h == letras -1)
                p<<"]";
            else
                p<<"]"<<endl;
            estado++;

        }

        t++;
        estado = 0;
        h++;

    }

    
   p.close(); 
   system("pause");

}

void ingreso_manual()
{
	cout << "hola" ;
}

void leer_archivo()
{
	char c,signo, cambio;
	char Estados[50];
	int estados,cant_letras;
	char Letras[30];
	char matriz[50][50];
    int DFA_NFA = 0;
	
	
	ifstream Archivo;
	Archivo.open("automata.txt");
	
    if (Archivo.fail())      // chequea que el archivo exista .
    {
        cout<<"\n\n\n              Archivo no existe";
        system("PAUSE");
        exit (1);       //  aborta el programa si el archivo no existe
    }	
	

    while(!Archivo.eof()) // hasta que llega al final, muestra los componentes del archivo.
    {
        Archivo >> estados;
        Archivo >> cant_letras;
        
        for (int i = 0 ; i < cant_letras ; i++)
        {
        	Archivo >> Letras[i];
        }
        
        int i,j;
        
        i=0;
        j=0;
        
        while(!Archivo.eof())
        {
        	Archivo >> Estados[i];
            cambio = Estados[i];
        	Archivo >> c;
        	Archivo >> signo;
        	if (signo == '[')
        	{
                DFA_NFA = 2;

        		while (signo != ']')
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
                DFA_NFA = 1;

				while(!Archivo.eof())
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
    if (DFA_NFA == 2)
    {

        for (int i = 0 ; i < cant_letras ; i++)
        {
            cout<< Letras[i] << " " ;
        }
        
        cout <<"cantidad de estados  "<< estados <<endl;
        cout <<"cantidad de letras  " << cant_letras<<endl;
    
        int i = 0;
        int j = 0;
        int h = 0;
    
        while(i != estados*cant_letras)
        {

            if (i == estados){
                j ++;
            }
    	   cout << Estados[i] << " con la letra "<< Letras[j] << " va al estado: "<<endl;
            while(matriz[i][h] != ']')
            {
                cout<< "---->   " << matriz[i][h] <<endl;
                h++;
            }
            h = 0;
            i++;
    	
        }
    }   
    
    
    
    for (int i = 0 ; i < cant_letras ; i++)
    {
        cout<< Letras[i] << " " ;
    }

    cout<<endl;
    cout<<endl;
    
    Archivo.close(); //cierra el archivo 3.
    system("PAUSE");
    system("cls");  // limpia la pantalla.
	
}

void recibir_automata()
{
    int opcion =0;
    cout<<"                  Ingrese el tipo de automata que ingresara:"<<endl;
    cout<<endl;
    cout<<endl;


    void tipo();

    cin>>opcion;
    switch(opcion)
    {
        case 1:
            DFA();
            system("pause");
            break;
            
            
        case 2:
            
            break;
        
    }

}

void menu()
{
    cout<<"        *******************************************************************"<<endl;
    cout<<"        *XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X      ----------------------------------------------------     X*"<<endl;  // MENU PRINCIPAL.
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X   1.- Cargar un automata desde un Archivo de Texto.           X*"<<endl;
    cout<<"        *X   2.- Ingresar Automata manualmente.                          X*"<<endl;
    cout<<"        *X   3.-                                                         X*"<<endl;
    cout<<"        *X   4.-                                                         X*"<<endl;
    cout<<"        *X   5.-                                                         X*"<<endl;
    cout<<"        *X   6.-                                                         X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*"<<endl;
    cout<<"        *******************************************************************"<<endl;

}

void menuadios()
{
    cout<<"        *******************************************************************"<<endl;
    cout<<"        *XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X      ----------------------------------------------------     X*"<<endl;  // MENU Adios
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*"<<endl;
    cout<<"        *******************************************************************"<<endl;

}

void tipo()
{

    cout<<"        *******************************************************************"<<endl;
    cout<<"        *XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X   1.- Automata ( DFA )                                        X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X   2.- Automata ( NFA )                                        X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *X                                                               X*"<<endl;
    cout<<"        *XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*"<<endl;
    cout<<"        *******************************************************************"<<endl;
}
