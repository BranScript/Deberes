#include <iostream>
#include <ctime>
#include <string>
using namespace std;

// Funcion para seleccionar el nivel de dificultad
int nivel(int &victoriasMaquina)
{
    int nivel;
    
    while (true) // Bucle hasta que el usuario ingrese un valor valido
    {
        cout << "Seleccione el nivel de dificultad: " << endl;
        cout << "1) Principiante (0-0)" << endl;
        cout << "2) Intermedio (0-1)" << endl;
        cout << "3) Avanzado (0-2)" << endl;
        cin >> nivel;

        if (nivel >= 1 && nivel <= 3)
        {
            break; // Si la opcion es valida, salimos del bucle
        }
        else
        {
            cout << "Error: Solo valores del 1 al 3. Intente de nuevo.\n" << endl;
        }
    }

    // Ajustar victorias iniciales de la maquina segun el nivel elegido
    victoriasMaquina = (nivel == 2) ? 1 : (nivel == 3) ? 2 : 0;

    return nivel;
}

// Funcion para obtener la eleccion del usuario
int eleccionUsuario(int ronda)
{
    int opusuario;
    cout << "\n--- Ronda " << ronda << " ---" << endl;
    
    while (true)
    {
        cout << "Elija una opcion: " << endl;
        cout << "1) Piedra" << endl;
        cout << "2) Papel" << endl;
        cout << "3) Tijera" << endl;
        cin >> opusuario;

        if (opusuario >= 1 && opusuario <= 3)
        {
            return opusuario - 1; 
        }
        cout << "Opcion invalida. Intente de nuevo." << endl;
    }
}


int eleccionMaquina()
{
    return rand() % 3; 
}


void ganadorRonda(int opusuario, int opmaquina, int &victoriasUsuario, int &victoriasMaquina)
{
    if (opusuario == opmaquina)
    {
        cout << "Empate!" << endl;
    }
    else if ((opusuario == 0 && opmaquina == 2) || 
             (opusuario == 1 && opmaquina == 0) || 
             (opusuario == 2 && opmaquina == 1))   
    {
        cout << "Ganaste esta ronda!" << endl;
        victoriasUsuario++;
    }
    else
    {
        cout << "Perdiste esta ronda!" << endl;
        victoriasMaquina++;
    }
}


void ganadorJuego(int victoriasUsuario, int victoriasMaquina)
{
    cout << "\n=== Resultado Final ===" << endl;
    cout << "Tus victorias: " << victoriasUsuario << endl;
    cout << "Victorias de la maquina: " << victoriasMaquina << endl;

    if (victoriasUsuario > victoriasMaquina)
    {
        cout << "Ganaste!" << endl;
    }
    else if (victoriasUsuario < victoriasMaquina)
    {
        cout << "La maquina gano!" << endl;
    }
    else
    {
        cout << "El juego termino en empate!" << endl;
    }
}


void jugar()
{
    srand(time(NULL));
    
    int victoriasUsuario = 0, victoriasMaquina = 0;
    string elementojuego[] = {"Piedra", "Papel", "Tijera"};

 
    nivel(victoriasMaquina);

    cout << "--- Bienvenido al Juego ---" << endl;


    for (int ronda = 1; ronda <= 5; ronda++)
    {
        int opusuario = eleccionUsuario(ronda);
        int opmaquina = eleccionMaquina();

        cout << "Tu elegiste: " << elementojuego[opusuario] << endl;
        cout << "La maquina eligio: " << elementojuego[opmaquina] << endl;

        ganadorRonda(opusuario, opmaquina, victoriasUsuario, victoriasMaquina);
    }

    ganadorJuego(victoriasUsuario, victoriasMaquina);
}


int main()
{
    jugar();
    return 0;
}
