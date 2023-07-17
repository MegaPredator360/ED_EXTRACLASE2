#include "std.h"

class pilas {
public:
	void agregarNum(const int&);
	void eliminarNum();
	void mostrarNum();
	bool estaVacia();

private:
	stack<int> pila;
};
