#include "colas.h"

void colas::agregarNum(const int& digito)
{
    cola.push(digito);
}

int colas::cantidadNum()
{
    return cola.size();
}

int colas::obtenerPrimerNum()
{
    return cola.front();
}

void colas::eliminarNum()
{
    cola.pop();
}

void colas::eliminarDatos() // Mientras la cola no este vacia, irá eliminando cada dato
{
    while (!cola.empty())
    {
        cola.pop();
    }
}
