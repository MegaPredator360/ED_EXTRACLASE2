#include "procedimientos.h"
#include "metodosInterface.h"

class interfaz
{
public:
	void pantallaTitulo();		// Muestra una pantalla de bienvenida
	void color(int);			// Cambiar el color de la opc�on marcada en el men�
	void goToXY(int, int);			// Indicar� la posici�n del texto al mostrarse en la consola
	void menuPrincipal();		// Muestra el menu principal en el que el usuario podr� interactuar
};

