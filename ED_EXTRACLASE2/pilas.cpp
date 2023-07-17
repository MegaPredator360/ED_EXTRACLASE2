#include "pilas.h"

void pilas::agregarNum(const int& numero) 
{
    pila.push(numero);          // Agrega el n�mero a la pila
}

int pilas::cantidadNum()
{
    return pila.size();         // Obtendr� la cantidad de valores de la pila
}

int pilas::obtenerPrimerNum()
{
    return pila.top();          // Obtendr� el primer valor de la pila
}

void pilas::eliminarNum()
{
    pila.pop();                 // Elimina el elemento en la parte superior de la pila
}