#include "metodosProcedimientos.h"

int metodosProcedimientos::cantidadNumeros(string secuencia) {
	try {
		int cantidad = 0;

		// Si el ultimo caracter del string no es un "espacio", se le añadirá uno
		if (secuencia.back() != ' ') {
			secuencia.insert(secuencia.length(), " ");
		}

		// Ira por cada caracter de la secuencia
		for (char& caracter: secuencia) {
			if (caracter == ' ') {
				cantidad = cantidad + 1;
			}
		}

		return cantidad;
	}
	catch (exception& e) {
		throw e;
	}
}

int metodosProcedimientos::cantidadString(string texto) {
	int cantidad = 0;						// Cantidad de caracteres en el string
	for (int i = 0; texto[i] != '\0'; i++)	// Contará la cantidad de letras que hay en el string
	{ 
		cantidad++;
	}
	return cantidad;
}

bool metodosProcedimientos::buscarMarco(int _secuencia, vector<int>& marcos)
{
	int auxiliar = _secuencia;

	// Buscará por el marco verificando si el digito existe en el marco
	for (int i = 0; i < marcos.size(); i++)
	{
		if (marcos[i] == auxiliar)
		{
			return true;
		}
	}
	return false;
}

int metodosProcedimientos::predecirMarco(int* _secuencia, vector<int>& _marco, int _cantidadDigitos, int _posicion)
{
	// Store the index of pages which are going
	// to be used recently in future
	int res = -1, farthest = _posicion;

	for (int i = 0; i < _marco.size(); i++) 
	{
		int j;
		for (j = _posicion; j < _cantidadDigitos; j++) {
			if (_marco[i] == _secuencia[j]) {
				if (j > farthest) {
					farthest = j;
					res = i;
				}
				break;
			}
		}

		// If a page is never referenced in future,
		// return it.
		if (j == _cantidadDigitos)
			return i;
	}

	// If all of the frames were not in future,
	// return any of them, we return 0. Otherwise
	// we return res.
	return (res == -1) ? 0 : res;
}
