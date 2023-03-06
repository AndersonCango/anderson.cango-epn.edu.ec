#include <iostream>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

const string ACNOMBRE_COMPLETO = "Anderson Daniel Cango Samuisa";
const string ACCEDULA = "1756084511";

// Definición de la estructura de un nodo del árbol
struct Coordenada 
{
    int acCap_Belica; // Capacidad Belica
    string acGeolocalizacion; // Posicion
    string acArsenal; // Arsenal
    Coordenada* derecha;
    Coordenada* izquierda;
};

// Función para crear un nuevo nodo del árbol
Coordenada* acCrearArbol(Coordenada* ABB,int acCap_Belica, string acGeolocalizacion, string acArsenal) 
{
    // Si el árbol está vacío, se crea un nuevo nodo
    if (ABB == nullptr) {
        Coordenada* newCoordenada = new Coordenada();
        newCoordenada->acCap_Belica = acCap_Belica;
        newCoordenada->acGeolocalizacion = acGeolocalizacion;
        newCoordenada->acArsenal = acArsenal;
        newCoordenada->derecha = nullptr;
        newCoordenada->izquierda = nullptr;
    }
    // Si el valor es menor que el nodo actual, se inserta en el subárbol izquierdo
    if (acCap_Belica < ABB->acCap_Belica) {
        ABB->izquierda = acCrearArbol(ABB->izquierda, acCap_Belica, acGeolocalizacion, acArsenal);
    }
    // Si el valor es mayor que el nodo actual, se inserta en el subárbol derecho
    else if (acCap_Belica > ABB->acCap_Belica) {
        ABB->derecha = acCrearArbol(ABB->derecha, acCap_Belica, acGeolocalizacion, acArsenal);
    }
    // Si el valor ya existe, no se hace nada
    return ABB;
}

// Funcion para ver el arbol binario de busqueda
void verArbol(Coordenada* ABB, int n)
{
     if(ABB==NULL)
          return;
     verArbol(ABB->derecha, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< ABB->acCap_Belica << ", " << ABB->acGeolocalizacion << ", " << ABB->acArsenal << endl << endl;

     verArbol(ABB->izquierda, n+1);
}

// Animacion de carga
void MovRotacional()
{
    int ind =0;
    string c= "\\|/-|";
    for(int i=0; i<= 100; i++)
    {   
        //updateBar(i);
        if(i % 4 ==0)
            ind =0;
        cout << "\r" << c[ind++] << "  " << i << "%";
        Sleep(100);
    }
    cout << endl;
}

void datos()
{
    cout    << endl << "[+] Informacion arbol binario capacidad belica Ucrania" << endl << endl
            << "Developer-Nombre : " << ACNOMBRE_COMPLETO << endl
            << "Developer-Cedula : " << ACCEDULA << endl
            << "Capacidad Belica : " << "31" << endl
            << "Coordenada-Total : " << "7" << endl
            << "Coordenada-SecCarga : " << "1 7 5 6 0 8 4" << endl;
}

int main()
{
    Coordenada* ABB = NULL;
    ifstream archivo("files/acdatos.txt");
    if (archivo.is_open()) {
        int acCap_Belica; 
        string acGeolocalizacion; 
        string acArsenal; 
        while (archivo >> acCap_Belica >> ws && getline(archivo, acGeolocalizacion, ',') && getline(archivo, acArsenal)) {
            ABB = acCrearArbol(ABB, acCap_Belica, acGeolocalizacion, acArsenal);
        }
        archivo.close();
    }
    else {
        cout << "Error al abrir el archivo" << endl;
    }
    datos();// Procedimiento para  información con los datos del desarrollador y del árbol Binario de capacidad bélica Ucrania

    return 0;
}
