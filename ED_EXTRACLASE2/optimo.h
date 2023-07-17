#include "std.h"

class optimo {
public:
	// Se agregar los elementos al optimo
	void agregarNum(const int&);

	// Contar� la cantidad de elementos ingresados al optimo
	int cantidadNum();

	// Obtendr� el elemento en la primera posici�n del optimo
	int obtenerPrimerNum();

	// Se elimina el elemento del optimo
	void eliminarNum();

private:
	queue<int> optimo;
};