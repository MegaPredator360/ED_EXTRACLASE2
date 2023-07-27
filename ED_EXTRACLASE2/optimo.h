#include "std.h"

class optimo {
public:
	// Se agregar los elementos al optimo
	void agregarNum(const int&);

	// Contará la cantidad de elementos ingresados al optimo
	int cantidadNum();

	// Obtendrá el elemento en la primera posición del optimo
	int obtenerPrimerNum();

	// Se obtiene los elementos del vector
	vector<int> obtenerDatos();

	// Se cambia de digito basado en la posicion predecida
	void cambiarDato(int, int);

	// Se eliminan todos los datos del vector en caso de ser usado anteriormente
	void eliminarDatos();

private:
	vector<int> optimo;
};