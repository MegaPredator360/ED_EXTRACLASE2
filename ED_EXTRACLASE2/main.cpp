#include "interfaz.h"

int main()
{
	// Metodo para poder mostrar caracteres especiales en consola
	setlocale(LC_ALL, "");

	// Llamado a la clase de interfaz
	interfaz _interfaz;

	// Llamado al metodo de la pantalla de bienvenida
	//_interfaz.pantallaTitulo();

	// Llamado al metodo del men? principal
	_interfaz.menuPrincipal();

	return 0;
}