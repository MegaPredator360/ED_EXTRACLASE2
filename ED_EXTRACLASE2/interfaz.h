#include "procedimientos.h"
#include "metodosInterface.h"

class interfaz
{
public:
	void pantallaTitulo();		// Muestra una pantalla de bienvenida
	void color(int);			// Cambiar el color de la opcíon marcada en el menú
	void goToXY(int, int);			// Indicará la posición del texto al mostrarse en la consola
	void menuPrincipal();		// Muestra el menu principal en el que el usuario podrá interactuar
};

