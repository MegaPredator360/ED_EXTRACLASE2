#include "std.h"

class metodosProcedimientos
{
public:
	// Metodo que será el encargado de contar la cantidad de números que hay en la secuencia
	int cantidadNumeros(string);

	// Metodo que será el encargado de contar la cantidad de caracteres que hay en el string
	int cantidadString(string);

	// El metodo predecirá si el digito existe en el marco o no
	bool buscarMarco(int, vector<int>&);

	// El metodo encontrará el marco que no será usado en el futuro despues de darle un indice
	int predecirMarco(int*, vector<int>&, int, int);
};