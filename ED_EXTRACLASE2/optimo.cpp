#include "optimo.h"

void optimo::agregarNum(const int& dig) {
    optimo.push_back(dig);
}

int optimo::cantidadNum() {
    return optimo.size();
}

int optimo::obtenerPrimerNum() {
    return optimo.front();
}

vector<int> optimo::obtenerDatos()
{
    return optimo;
}

void optimo::cambiarDato(int _p, int _secuencia)
{
    optimo[_p] = _secuencia;
}

void optimo::eliminarDatos()
{
    optimo.clear();
}
