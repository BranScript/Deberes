#include <iostream>
#include <string>
using namespace std;

string identificarCadena(char cadena[])
{
    int letras = 0;
    int numeros = 0;

    for (int i = 0; cadena[i] != '\0'; i++)
    {
        char c = cadena[i];

        if (c >= 48 && c <= 57)
        { // Números del 0 al 9
            numeros = 1;
        }
        else if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        { // Letras aA-zZ
            letras = 1;
        }
    }

    if (letras == 1 && numeros == 1)
    {
        return "ALFANUMERICA";
    }
    else if (letras == 1)
    {
        return "ALFABETICA";
    }
    else
    {
        return "NUMERICA";
    }
}
int main()
{
    char cadena[100];
    cout << "Ingrese una cadena: ";
    cin.getline(cadena, 100);
    if (cadena[0] == '\0')
    {
        cout << "La cadena no tiene elementos";
    }
    else
    {
        string resultado = identificarCadena(cadena);
        cout << "La cadena es " << resultado <<endl;
    }

    return 0;
}
