#include "metodosProcedimientos.h"

int metodosProcedimientos::cantidadNumeros(string secuencia)
{
	try
	{
		int cantidad = 0;

		// Si el ultimo caracter del string no es un "espacio", se le añadirá uno
		if (secuencia.back() != ' ')
		{
			secuencia.insert(secuencia.length(), " ");
		}

		// Ira por cada caracter de la secuencia
		for (char& caracter: secuencia)
		{
			if (caracter == ' ')
			{
				cantidad = cantidad + 1;
			}
		}

		return cantidad;
	}
	catch (exception& e)
	{
		throw e;
	}
}

int metodosProcedimientos::cantidadString(string texto)
{
	int cantidad = 0;						// Cantidad de caracteres en el string
	for (int i = 0; texto[i] != '\0'; i++)	// Contará la cantidad de letras que hay en el string
	{
		cantidad++;
	}
	return cantidad;
}
