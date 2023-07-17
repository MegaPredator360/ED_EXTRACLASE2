#include "optimo.h"

void optimo::agregarNum(const int& dig) {
    optimo.push(dig);
}

int optimo::cantidadNum() {
    return optimo.size();
}

int optimo::obtenerPrimerNum() {
    return optimo.front();
}

void optimo::eliminarNum() {
    optimo.pop();
}
