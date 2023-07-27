#include "metodosInterface.h"

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
		else if (asciiChar == 13)					// Verificará si la ultima tecla pulsada fue "Enter"
		{
			if (num == "")
			{
				PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);	// Reproducirá el sonido de alerta en caso de que el espacio está vacio
			}
			else
			{
				cout << endl;						// Hará un salto de linea
				break;								// Terminará el while
			}
		}
		else if (asciiChar == 8)					// Verificará si la tecla "Backspace" fue pulsada
		{
			if (num == "")
			{
				PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);	// Reproducirá el sonido de alerta en caso de que el espacio está vacio
			}
			else
			{
				cout << '\b';							// Moverá el cursor un caracter atrás
				cout << " ";							// Remplazará el valor por un espacio
				cout << '\b';
				num = num.substr(0, num.size() - 1);	// Borrará el ultimo valor del string
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
		else if (asciiChar == 32)					// Verificará si la tecla "espacio" fue pulsada
		{
			if (num == "")							// Verificará si espacio no tiene digitos
			{
				PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);
			}
			else if (num.back() == ' ')				// Si el ultimo caracter es un "espacio" no ingresará otro hasta que ingrese un nuevo digito
			{
				PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);
			}
			else
			{
				// Agregará un espacio a la variable y a la consola
				num = num + " ";
				cout << " ";
			}
		}
		else if (asciiChar == 13)					// Verificará si la ultima tecla pulsada fue "Enter"
		{
			if (num == "")
			{
				PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);	// Reproducirá el sonido de alerta en caso de que el espacio está vacio
			}
			else
			{
				cout << endl;						// Hará un salto de linea
				break;								// Terminará el while
			}
		}
		else if (asciiChar == 8 && num == "")
		{
			PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);	// Reproducirá el sonido de alerta en caso de que el espacio está vacio
		}
		else if (asciiChar == 8)					// Hará la funcion del Backspace
		{
			cout << '\b';							// Moverá el cursor un caracter atrás
			cout << " ";							// Remplazará el valor por un espacio
			cout << '\b';
			num = num.substr(0, num.size() - 1);	// Borrará el ultimo valor del string
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

int metodosInterface::númeroMinimo(int _a, int _b, int _c)
{
	int valorMinimo = _a;

	// Si _b es menor que _a, se valorMinimo pasa a contener el valor de _b
	if (_b < valorMinimo) 
	{
		valorMinimo = _b;
	}

	// Si _c es menor que _b, se valorMinimo pasa a contener el valor de _c
	if (_c < valorMinimo)
	{
		valorMinimo = _c;
	}

	return valorMinimo;
}

void metodosInterface::pageFaults(int* secuencia, int marcos)
{
	try
	{
		// Se limpiará el vector con los resultados en caso de ser usado anteriormente
		algoritmosEficientes.clear();

		page_faultsFIFO = _procedimientos.pageFaultsFIFO(secuencia, marcos);
		cout << "Page-faults: " << page_faultsFIFO << endl;

		page_faultsLIFO = _procedimientos.pageFaultsLIFO(secuencia, marcos);
		cout << "Page-faults: " << page_faultsLIFO << endl;

		page_faultsOptimal = _procedimientos.pageFaultsOptimal(secuencia, marcos);
		cout << "Page-faults: " << page_faultsOptimal << endl;

		int valorMinimo = númeroMinimo(page_faultsFIFO, page_faultsLIFO, page_faultsOptimal);

		// Se averiguará si hay más de un valor minimo de los resultados de page_fault
		if (valorMinimo == page_faultsFIFO)
		{
			algoritmosEficientes.push_back("FIFO");
		}

		if (valorMinimo == page_faultsLIFO)
		{
			algoritmosEficientes.push_back("LIFO");
		}

		if (valorMinimo == page_faultsOptimal)
		{
			algoritmosEficientes.push_back("Optimo");
		}


		// Se le dará al usuario el resultado del algoritmo
		if (algoritmosEficientes.size() == 1)
		{
			cout << endl << "El algoritmo más eficiente fue: " << algoritmosEficientes[0] << "." << endl;
		}
		else
		{
			cout << endl << "Los algoritmos más eficientes fueron: ";

			for (int i = 0; i < algoritmosEficientes.size(); ++i) 
			{
				cout << algoritmosEficientes[i] << ", ";
			}
			cout << '\b' << '\b' << "." << endl;
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}


