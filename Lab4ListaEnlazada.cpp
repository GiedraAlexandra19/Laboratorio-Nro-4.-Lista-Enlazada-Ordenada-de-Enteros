#include <iostream>
#include "LinkedList.h"
using namespace std;

void menu()
{
    cout << "******************LISTA ENLAZADA ORDENADA********************\n\n";
    cout << " 1. MOSTRAR LISTA                  " << endl;
    cout << " 2. INSERTAR VALOR                 " << endl;
    cout << " 3. REMOVER VALOR                  " << endl;
    cout << " 4. BUSCAR VALOR                   " << endl;
    cout << " 5. SALIR                          " << endl;
    cout << "\n INGRESE OPCION: ";
}

int main() {
    int data;
    LinkedList elemento;

    elemento.insert(1);
    elemento.insert(3);
    elemento.insert(5);
    elemento.insert(7);
    elemento.insert(9);
    elemento.insert(11);


    int op;     // opcion del menu

    do
    {
        menu();  cin >> op;

        switch (op)
        {
        case 1:
            cout << "\n La lista es: " << endl;
            cout << elemento;
            break;

        case 2:
            cout << "Valor: "; cin >> data;
            elemento.insert(data);
           // elemento.Ordenar(data);
            break;

        case 3:
            cout << "Valor: "; cin >> data;
            elemento.remove(data);
            break;

        case 4:
            cout << "Valor: "; cin >> data;
            elemento.buscar(data);
            break;

        }

        cout << endl << endl;

    } while (op != 5);

    return 0;
}

