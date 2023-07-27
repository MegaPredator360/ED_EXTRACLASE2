#include "pilas.h"

void pilas::agregarNum(const int& numero) 
{
    pila.push(numero);          // Agrega el número a la pila
}

int pilas::cantidadNum()
{
    return pila.size();         // Obtendrá la cantidad de valores de la pila
}

int pilas::obtenerPrimerNum()
{
    return pila.top();          // Obtendrá el primer valor de la pila
}

void pilas::eliminarNum()
{
    pila.pop();                 // Elimina el elemento en la parte superior de la pila
}

void pilas::eliminarDatos()
{
    while (!pila.empty())       // Mientras la pila no este vacia, irá eliminando cada dato
    {
        pila.pop();
    }
}
