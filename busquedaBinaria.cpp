#include <iostream>
#include <ctime>
using namespace std;
int datos;
int v[100];

int numeroDatos() {
    int ndatos;
    cout << "Cuantos datos quiere: ";
    cin >> ndatos;
    return ndatos;
}

void llenarVector(int &datos, int v[]) {
    srand(time(NULL));
    datos = numeroDatos();
    for (int i = 0; i < datos; i++) {
        v[i] = 1 + rand() % 20;
    }
}

void verVector(int datos, int v[]) {
    for (int i = 0; i < datos; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void ordenInsercion(int n, int v[]) {
    int aux;
    for (int i = 1; i < n; i++) {
        aux = v[i];
        int j = i - 1;
        while (j >= 0 && aux < v[j]) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}

int datoBuscado() {
    int datob;
    cout << "Ingrese el dato a buscar: ";
    cin >> datob;
    return datob;
}

bool busquedaBinaria(int datob, int datos, int v[], int &lugar) {
    int inf = 0; // primera posición
    int sup = datos - 1; // última posición
    int mitad;

    for (int i = 0; inf <= sup; i++) {
        mitad = (inf + sup) / 2;

        if (v[mitad] == datob) {
            lugar = mitad; 
            return true;
        }
        if (v[mitad] > datob) {
            sup = mitad - 1; 
        } else {
            inf = mitad + 1; 
        }
    }
    return false; 
}

void datoEncontrado(bool encontrado, int mitad) {
    if (encontrado) {
        cout << "El numero se encontro en la lugar: " << mitad+1 << endl;
    } else {
        cout << "El numero no se encontro" << endl;
    }
}
void vectores(){
	llenarVector(datos, v);
    cout << "Vector original: " << endl;
    verVector(datos, v);

    cout << "\nVector ordenado: " << endl;
    ordenInsercion(datos, v);
    verVector(datos, v);
}
void numExistente(){
	vectores();
	int datob = datoBuscado();
    int lugar;
    bool encontrado = busquedaBinaria(datob, datos, v, lugar);
    datoEncontrado(encontrado, lugar);
}

int main() { 
	numExistente();
    return 0;
}
