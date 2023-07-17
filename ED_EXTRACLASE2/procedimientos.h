#include "colas.h"
#include "pilas.h"
#include "optimo.h"
#include "metodosProcedimientos.h"

class procedimientos
{
private:
	// Variables a usar durante ejecución
	int page_faultsFIFO;

	// Llamados a clases
	colas _cola;
	metodosProcedimientos _metodosProcedimiento;

public:
	// Metodo para convertir la secuencia de un String a un array de Int
	int* agregarSecuencia(string);

	// Inicializará el proceso de todos los page-faults
	void pageFaults(int*, int);

	// Metodo para hacer el proceso de page-faults en colas
	int pageFaultsFIFO(int*, int);
};

