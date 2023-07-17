#include "std.h"

class colas {
public:
	// Se agregar la secuencia de n�meros a la cola
	void agregarNum(const int&);

	// Contar� la cantidad de digitos ingresados en la cola
	int cantidadNum();

	// Obtendr� el elemento en la primera posici�n de la cola
	int obtenerPrimerNum();

	// Se elimina la secuencia de n�meros de la cola
	void eliminarNum();

private:
	queue<int> cola;
};

