#include <iostream>
#include <string.h>
#include <windows.h>
#include <fstream>

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
Coordenada* acCrearNodo(int acCap_Belica, string acGeolocalizacion, string acArsenal) 
{
    Coordenada* newCoordenada = new Coordenada();
    newCoordenada->acCap_Belica = acCap_Belica;
    newCoordenada->acGeolocalizacion = acGeolocalizacion;
    newCoordenada->acArsenal = acArsenal;
    newCoordenada->derecha = nullptr;
    newCoordenada->izquierda = nullptr;
    return newCoordenada;
}

// Función para insertar un nuevo nodo en el árbol
Coordenada* insert(Coordenada* ABB, int acCap_Belica, string acGeolocalizacion, string acArsenal) 
{
    // Si el árbol está vacío, se crea un nuevo nodo
    if (ABB == nullptr) {
        return acCrearNodo(acCap_Belica, acGeolocalizacion, acArsenal);
    }
    // Si el valor es menor que el nodo actual, se inserta en el subárbol izquierdo
    if (acCap_Belica < ABB->acCap_Belica) {
        ABB->izquierda = insert(ABB->izquierda, acCap_Belica, acGeolocalizacion, acArsenal);
    }
    // Si el valor es mayor que el nodo actual, se inserta en el subárbol derecho
    else if (acCap_Belica > ABB->acCap_Belica) {
        ABB->derecha = insert(ABB->derecha, acCap_Belica, acGeolocalizacion, acArsenal);
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

// Funcion para abrir el archivo
void archivo()
{
    int acCap_Belica; 
    string acGeolocalizacion; 
    string acArsenal; 
    ifstream inputFile("files/acdatos.txt");
    if (!inputFile.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        // return 0;
    }

    Coordenada* ABB = nullptr; // Crea el árbol vacío

    // Lee los datos del archivo y los inserta en el árbol
    while (inputFile >> acCap_Belica >> acGeolocalizacion >> acArsenal) {
        ABB = insert(ABB, acCap_Belica, acGeolocalizacion, acArsenal);
    }
    inputFile.close(); // Cierra el archivo
}

// Muestra la carga desde el 0 hasta el 100 %
void caCarga()
{
    for(int i = 0; i <= 100; i++)
    {
        cout << "\r" << i << " %";
        Sleep(150);
    }
}



int main()
{
    Coordenada* ABB = nullptr; // Crea el árbol vacío
    archivo();
    verArbol(ABB,0);
    return 0;
}
