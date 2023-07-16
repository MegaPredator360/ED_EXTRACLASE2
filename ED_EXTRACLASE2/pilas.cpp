#include "pilas.h"

void pilas::agregarNum(const int& numero) {
    pila.push(numero); // Agrega el número a la pila
}

void pilas::eliminarNum() {
    if (!pila.empty()) { // Verifica si la pila no está vacía
        cout << "Eliminar Numero de la Secuencia: " << pila.top() << endl; // Muestra el elemento en la parte superior de la pila
        pila.pop(); // Elimina el elemento en la parte superior de la pila
    }
    else {
        cout << "No hay Numeros en la Secuencia" << endl;
    }
}

void pilas::mostrarNum() {
    if (!pila.empty()) { // Verifica si la pila no está vacía
        cout << "Cola de Espera: ";
        stack<int> aux = pila;
        while (!aux.empty()) {
            cout << " " << aux.top(); // Muestra el elemento en la parte superior de la pila
            aux.pop(); // Elimina el elemento en la parte superior de la pila auxiliar
        }
        cout << endl;
    }
    else {
        cout << "No hay Numeros en la Pila." << endl;
    }
}

bool pilas::estaVacia() {
    return pila.empty();  // Verifica si la pila está vacía
}