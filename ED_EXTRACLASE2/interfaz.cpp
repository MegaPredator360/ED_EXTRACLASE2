#include "interfaz.h"

// Mostrará una pantalla de bienvenida al inicio del programa
void interfaz::pantallaTitulo()
{
	cout << endl << endl;
	cout << "                  .----.			 _____ ____  " << endl;
	cout << "      .---------. | == |			| ____|  _ \\ " << endl;
	cout << "      |.-\"\"\"\"\"-.| |----|			|  _| | | | |" << endl;
	cout << "      ||       || | == |			| |___| |_| |" << endl;
	cout << "      ||       || |----|			|_____|____/ " << endl;
	cout << "      |'-.....-'| |::::|" << endl;
	cout << "      `\"\")---(\"\"` |___.|  _____                      ____  _ _                __   ____      _           " << endl;
	cout << "     /:::::::::::\\\" _  \" |_   _|_ _ _ __ ___  __ _  |  _ \\(_) | __ _ ___     / /  / ___|___ | | __ _ ___ " << endl;
	cout << "    /:::=======:::\\`\\`\\	   | |/ _` | '__/ _ \\/ _` | | |_) | | |/ _` / __|   / /  | |   / _ \\| |/ _` / __|" << endl;
	cout << "    `\"\"\"\"\"\"\"\"\"\"\"\"\"`  '-'   | | (_| | | |  __/ (_| | |  __/| | | (_| \\__ \\  / /   | |__| (_) | | (_| \\__ \\" << endl;
	cout << "                           |_|\\__,_|_|  \\___|\\__,_| |_|   |_|_|\\__,_|___/ /_/     \\____\\___/|_|\\__,_|___/" << endl;
	cout << endl << endl;
	cout << "						Realizado por:" << endl;
	cout << "					  Aaron Steve Alfaro Zamora" << endl;
	cout << "					 Maria Stephanie Araya Solano" << endl;
	cout << "					 Michelle José Arrieta Zamora" << endl;
	cout << "					     Keilyn Morera Vargas" << endl;
	cout << endl;
	system("pause");
}

void interfaz::color(int color)
{
	// Obtendrá el codigo de color para la consola
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void interfaz::goToXY(int x, int y)
{
	// Este tipo de dato indica las coordenadas de donde se escribirá el texto
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// Mostrará el menú principal del programa
void interfaz::menuPrincipal()
{
	// Llamado a la clase de metodos creados exclusivamente para la interface
	metodosInterface _metodosInterface;
	procedimientos _procedimientos;

	int counter = 1;				// Contador para averiguar la opción seleccionada
	int Set[] = { 7, 7, 7, 7 };		// Se coloca a todas las opciones con el color por defecto
	Set[0] = 23;					// Colocar la primera opcíon como seleccionada
	int key = 0;					// Encargada de recibir el valor de la tecla pulsada en ASCII

	while (1)
	{
		system("cls");
		
		cout << endl;
		cout << "		[]------------------------------------------[]" << endl;
		cout << "		|                Menú Principal              |" << endl;
		cout << "		[]------------------------------------------[]" << endl;
		cout << "		|                                            |" << endl;
		cout << "		|           Selecciona una opción:           |" << endl;
		cout << "		|                                            |" << endl;
		cout << "		|";

		for (int i = 0;;)
		{
			// Indica la posicion de donde se escribirá el texto
			goToXY(28, 7);
			// Inidicará el color a ingresar marcar si la opcion es seleccionada
			color(Set[0]);
			// Texto de la opción
			cout << "Realizar Procedimiento";

			cout << WHITE << "	     |" << endl;
			cout << "		|";

			goToXY(36, 8);
			color(Set[1]);
			cout << "Salir";

			cout << WHITE << "		     |" << endl;
			cout << "		|                                            |" << endl;
			cout << "		[]------------------------------------------[]" << endl;

			key = _getch();

			if (key == 72 && (counter >= 1 && counter <= 2))		// Validar si la flecha arriba es pulsada	|| 72 es el valor de la flecha arriba en ASCII
			{
				counter--;

				if (counter == 0)
				{
					counter = 2;
				}
			}
			else if (key == 80 && (counter >= 1 && counter <= 2))	// Validar si la flecha abajo es pulsada	|| 80 es el valor de la flecha abajo en ASCII
			{
				counter++;

				if (counter == 3)
				{
					counter = 1;
				}
			}
			else if (key == '\r')	// Identifica si la tecla ENTER fue pulsada
			{
				switch (counter)
				{
				case 1:
					try
					{
						// Valores para el procedimiento de la secuencia
						string secuencia;
						string confirmacion = "N";
						int cantidadMarcos = 0;

						while (confirmacion == "N")
						{
							system("cls");
							cout << endl;
							cout << "		[]--------------------------------------------[]" << endl;
							cout << "		|          Realizar procedimiento de           |" << endl;
							cout << "		|         remplazo de marcos de pagina         |" << endl;
							cout << "		[]--------------------------------------------[]" << endl;
							cout << endl;

							cout << "Ingresa la secuencia de números: " << YELLOW << "(Cada número deberá de ser separado por un espacio)" << WHITE << endl;
							secuencia = _metodosInterface.ingresarSecuenciaNumeros();

							cout << endl << "Ingresa la cantidad de marcos de pagina:" << endl;
							cantidadMarcos = stoi(_metodosInterface.ingresarNumeros());

							cout << "----------------------------------------" << endl;
							cout << "¿Los datos ingresados son correctos? [S/n]" << endl;
							confirmacion = _metodosInterface.confirmacionDefS();
						}

						_metodosInterface.pageFaults(_procedimientos.agregarSecuencia(secuencia), cantidadMarcos);

						cout << "----------------------------------------" << endl;
						cout << GREEN << "¡La secuencia de números a sido ingresada con exito!" << WHITE << endl;
						system("pause");
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				case 2:
					try
					{
						// Salir del programa
						string confirmacion;

						system("cls");
						cout << endl;
						cout << "		[]--------------------------------------------[]" << endl;
						cout << "		|              Salir del programa              |" << endl;
						cout << "		[]--------------------------------------------[]" << endl;
						cout << endl;

						cout << "¿Deseas salir del programa? [S/n]" << endl;
						confirmacion = _metodosInterface.confirmacionDefS();

						if (confirmacion == "S")
						{
							cout << "-----------------------------------" << endl;
							cout << GREEN << "¡Gracias por usar el programa!" << WHITE << endl;
							system("pause");
							exit(0);
						}
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				default:
					cout << RED << "Seleccione una opcion valida. " << WHITE << endl;
				}

				break;	// Para salir del ciclo for
			}

			// Color por defecto de todas las opciones
			Set[0] = 7;			// 7 es el color blanco
			Set[1] = 7;
			Set[2] = 7;
			Set[3] = 7;

			// Cambiar color basado en la opcion seleccionada
			switch (counter)
			{
			case 1:
				// Se indica el codigo de color con el que se usará en el texto
				// si la opción está seleccionada
				Set[0] = 23;
				break;

			case 2:
				Set[1] = 23;
				break;

			case 3:
				Set[2] = 23;
				break;

			case 4:
				Set[3] = 23;
				break;
			}
		}
	}
}
