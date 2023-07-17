#include "std.h"

class metodosInterface
{
public:
	// Metodo para que el usuario solo pueda ingresar números
	string ingresarNumeros();

	// Metodo para ingresar una sequencia de números
	string ingresarSecuenciaNumeros();

	// Metodo para confirmacion de Si o No
	// La opción por defecto de este metodo es Si
	string confirmacionDefS();
};

