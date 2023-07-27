#include "std.h"

class optimo {
public:
	// Se agregar los elementos al optimo
	void agregarNum(const int&);

	// Contará la cantidad de elementos ingresados al optimo
	int cantidadNum();

	// Obtendrá el elemento en la primera posición del optimo
	int obtenerPrimerNum();

	// Se elimina el elemento del optimo
	void eliminarNum();

private:
	queue<int> optimo;
};