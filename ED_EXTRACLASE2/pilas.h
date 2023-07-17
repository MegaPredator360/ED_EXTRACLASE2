#include "std.h"

class pilas {
public:
	// Se agregar los elementos a la pila
	void agregarNum(const int&);

	// Contar� la cantidad de elementos ingresados en la pila
	int cantidadNum();

	// Obtendr� el elemento en la primera posici�n de la pila
	int obtenerPrimerNum();

	// Se elimina el elemento de la pila
	void eliminarNum();

private:
	stack<int> pila;
};
