#include <iostream>
#include <string>
using namespace std;

int pocicion(int valor)
{
    int indice = 0;
    while (valor > 0 && valor < 19)
    {
        indice = (valor - 1) / 5;
        valor = 21;
    }
    while (valor > 18 && valor < 21)
    {
        indice = 4;
        valor = 1;
    }
    return indice;
}
void validacinDatos()
{
    int valor;
    do
    {
        cout << "Ingresa un valor entre 1 y 20: ";
        cin >> valor;
    } while (valor < 1 || valor > 20);
    pocicion(valor);
}

void categoria()
{
    int valor = 0;
    validacinDatos();
    string categorias[] = {"Deficiente", "Regular", "Bueno", "Muy Bueno", "Excelente"};
    cout << "La categoria es: " << categorias[pocicion(valor)] << endl;
}

void ContinuarProceso(){
 int otro = 1;
    do
    {
        categoria();
        cout << "Desea poner otro número: 1) Sí 2) No " << endl;
        cin >> otro;
    } while (otro == 1);
}

int main()
{
    ContinuarProceso();
    return 0;
}
