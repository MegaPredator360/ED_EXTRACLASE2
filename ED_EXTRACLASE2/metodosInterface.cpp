#include "metodosInterface.h"
#include <map>

string metodosInterface::ingresarNumeros()
{
	int asciiChar = 0;
	string num = "";
	do
	{
		asciiChar = _getch();						// Obtendra las teclas de formato ASCII 
		if (asciiChar >= 48 && asciiChar <= 57)		// Validaremos solo los valores que sean equivalentes a numeros
		{
			asciiChar = (asciiChar - 48);			// Los valores de ASCII para numeros 0-9 es igual a 48 hasta 57, por lo que se le resta a 48 por ser equivalente a 0
			cout << asciiChar;						// Se imprime el valor
			num = num + to_string(asciiChar);		// Convertir de Int a String para poder concatenar
		}
		else if (asciiChar == 13)					// Verificar� si la ultima tecla pulsada fue "Enter"
		{
			if (num == "")
			{
				PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);	// Reproducir� el sonido de alerta en caso de que el espacio est� vacio
			}
			else
			{
				cout << endl;						// Har� un salto de linea
				break;								// Terminar� el while
			}
		}
		else if (asciiChar == 8)					// Verificar� si la tecla "Backspace" fue pulsada
		{
			if (num == "")
			{
				PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);	// Reproducir� el sonido de alerta en caso de que el espacio est� vacio
			}
			else
			{
				cout << '\b';							// Mover� el cursor un caracter atr�s
				cout << " ";							// Remplazar� el valor por un espacio
				cout << '\b';
				num = num.substr(0, num.size() - 1);	// Borrar� el ultimo valor del string
			}
			
		}
	} while (1);

	return (num);
}

string metodosInterface::ingresarSecuenciaNumeros()
{
	int asciiChar = 0;
	string num = "";
	do
	{
		asciiChar = _getch();						// Obtendra las teclas de formato ASCII 
		if (asciiChar >= 48 && asciiChar <= 57)		// Validaremos solo los valores que sean equivalentes a numeros
		{
			asciiChar = (asciiChar - 48);			// Los valores de ASCII para numeros 0-9 es igual a 48 hasta 57, por lo que se le resta a 48 por ser equivalente a 0
			cout << asciiChar;						// Se imprime el valor
			num = num + to_string(asciiChar);		// Convertir de Int a String para poder concatenar
		}
		else if (asciiChar == 32)					// Verificar� si la tecla "espacio" fue pulsada
		{
			if (num == "")							// Verificar� si espacio no tiene digitos
			{
				PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);
			}
			else if (num.back() == ' ')				// Si el ultimo caracter es un "espacio" no ingresar� otro hasta que ingrese un nuevo digito
			{
				PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);
			}
			else
			{
				// Agregar� un espacio a la variable y a la consola
				num = num + " ";
				cout << " ";
			}
		}
		else if (asciiChar == 13)					// Verificar� si la ultima tecla pulsada fue "Enter"
		{
			if (num == "")
			{
				PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);	// Reproducir� el sonido de alerta en caso de que el espacio est� vacio
			}
			else
			{
				cout << endl;						// Har� un salto de linea
				break;								// Terminar� el while
			}
		}
		else if (asciiChar == 8 && num == "")
		{
			PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);	// Reproducir� el sonido de alerta en caso de que el espacio est� vacio
		}
		else if (asciiChar == 8)					// Har� la funcion del Backspace
		{
			cout << '\b';							// Mover� el cursor un caracter atr�s
			cout << " ";							// Remplazar� el valor por un espacio
			cout << '\b';
			num = num.substr(0, num.size() - 1);	// Borrar� el ultimo valor del string
		}
	} while (1);

	return (num);
}

string metodosInterface::confirmacionDefS()			// Utiliza la misma estructura que el de solo ingresarNumeros()
{
	int asciiChar = 0;
	string letra = "";
	do
	{
		asciiChar = _getch();
		if (asciiChar == 13 && letra == "")
		{
			letra = "S";
			break;
		}
		else if (asciiChar == 13 && letra != "")
		{
			cout << endl;
			break;
		}
		else if (asciiChar == 8 && letra == "")
		{
			PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);
		}
		else if (asciiChar == 8)
		{
			cout << '\b';
			cout << " ";
			cout << '\b';
			letra = letra.substr(0, letra.size() - 1);
		}
		else if (letra.length() >= 1)
		{
			PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);
		}
		else if (asciiChar == 83)
		{
			cout << "S";
			letra = "S";
		}
		else if (asciiChar == 115)
		{
			cout << "s";
			letra = "S";
		}
		else if (asciiChar == 78)
		{
			cout << "N";
			letra = "N";
		}
		else if (asciiChar == 110)
		{
			cout << "n";
			letra = "N";
		}
	} while (1);

	return (letra);
}

void metodosInterface::pageFaults(int* secuencia, int marcos)
{
	int page_faultsFIFO = _procedimientos.pageFaultsFIFO(secuencia, marcos);
	cout << "Page-faults: " << page_faultsFIFO << endl;

	int page_faultsLIFO = _procedimientos.pageFaultsLIFO(secuencia, marcos);
	cout << "Page-faults: " << page_faultsLIFO << endl;

	int page_faultsOptimal = _procedimientos.optimalPage(secuencia, marcos);
	cout << "Page-faults: " << page_faultsOptimal << endl;

	map<int, string> algoritmos;
	algoritmos[page_faultsFIFO] = "FIFO";
	algoritmos[page_faultsLIFO] = "LIFO";
	algoritmos[page_faultsOptimal] = "Óptimo";

	cout << endl << "El o los algoritmos mas eficientes son: ";
	for (const auto& pair : algoritmos) {
		if (pair.first == algoritmos.begin()->first) {
			cout << pair.second;
		}
		else {
			cout << ", " << pair.second;
		}
	}
	cout << endl;
}
