#include "procedimientos.h"

class metodosInterface
{
protected:
	procedimientos _procedimientos;

	// Variables usados
	int page_faultsFIFO;
	int page_faultsLIFO;
	int page_faultsOptimal;

	// Usado para contener el o los algoritmos más eficientes
	vector<string> algoritmosEficientes;

public:
	// Metodo para que el usuario solo pueda ingresar números
	string ingresarNumeros();

	// Metodo para ingresar una sequencia de números
	string ingresarSecuenciaNumeros();

	// Metodo para confirmacion de Si o No
	// La opción por defecto de este metodo es Si
	string confirmacionDefS();

	// Se obtendrá el número menor de los 3 page-faults
	int númeroMinimo(int, int, int);

	// Metodo para llamar a los metodos encargados de realizar los page-fault
	void pageFaults(int*, int);
};