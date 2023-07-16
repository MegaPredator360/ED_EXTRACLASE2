#include "colas.h"

void colas::agregarNum(const int& secuencia) {
    cola.push(secuencia);
}

void colas::eliminarNum() {
    /*
    if (!cola.empty()) {//empty verifica si la cola esta vacia 
        cout << "Eliminar Numero de la Secuencia: " << cola.front() << endl;
        cola.pop();//elimina el primer elemento de la cola
    }
    else {
        cout << "No hay Numeros en la Secuencia" << endl;
    }
    */
}

void colas::mostrarNum() {
    /*
    if (!cola.empty()) {
        cout << "Cola de Espera: ";
        queue<string> aux = cola;
        while (!aux.empty()) {
            cout << " " << aux.front();
            aux.pop();
        }
        cout << endl;
    }
    else {
        cout << "No hay Numeros en la Cola." << endl;
    }
    */
}

bool colas::estaVacia() {
    return cola.empty();
}