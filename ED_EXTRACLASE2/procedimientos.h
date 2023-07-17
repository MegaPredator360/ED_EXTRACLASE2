#include "colas.h"
#include "pilas.h"
#include "optimo.h"
#include "metodosProcedimientos.h"

class procedimientos
{
private:
	// Llamados a clases
	colas _cola;
	pilas _pila;
	optimo _optimo;
	metodosProcedimientos _metodosProcedimiento;

public:
	// Metodo para convertir la secuencia de un String a un array de Int
	int* agregarSecuencia(string);

	// Metodo para hacer el proceso de page-faults en colas
	int pageFaultsFIFO(int*, int);

	// Metodo para hacer el proceso de page-faults en pilas
	int pageFaultsLIFO(int*, int);

	// Metodo para hacer el proceso de page-faults en colas (optimo)
	int optimalPage(int*, int);
};

