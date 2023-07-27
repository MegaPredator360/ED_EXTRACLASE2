#include "std.h"

class colas {
public:
	// Se agregar la secuencia de números a la cola
	void agregarNum(const int&);

	// Contará la cantidad de digitos ingresados en la cola
	int cantidadNum();

	// Obtendrá el elemento en la primera posición de la cola
	int obtenerPrimerNum();

	// Se elimina la secuencia de números de la cola
	void eliminarNum();

private:
	queue<int> cola;
};

