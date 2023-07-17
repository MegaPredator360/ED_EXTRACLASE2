#include "procedimientos.h"

int* procedimientos::agregarSecuencia(string secuencia)
{
	try
	{
		int numero = 0;

		// Se obtendrá la cantidad de numeros de la secuencia
		int cantidadDigitos = _metodosProcedimiento.cantidadNumeros(secuencia);

		// Definimos e inicializamos en array de int en forma de puntero
		int* secuenciaNueva = new int[cantidadDigitos];
		
		for (int i = 0; i < cantidadDigitos; i++)
		{
			// Asignará el número hasta encontrar un "espacio"
			numero = stoi(secuencia.substr(0, secuencia.find(" ")));

			// Borrará el número encontrado de la secuencia para ingresar el siguiente número
			secuencia.erase(0, _metodosProcedimiento.cantidadString(to_string(numero)) + 1);

			// Ingresamos el valor en el array
			secuenciaNueva[i] = numero;
		}
		return secuenciaNueva;
	}
	catch (exception& e)
	{
		throw e;
	}
}

void procedimientos::pageFaults(int* secuencia, int marcos)
{
    page_faultsFIFO = pageFaultsFIFO(secuencia, marcos);

    cout << endl << "Page-faults en FIFO: " << page_faultsFIFO << endl;
    system("pause");
}

int procedimientos::pageFaultsFIFO(int* secuencia, int marcos)
{
    // Para ver la cantidad de paginas actuales se hace uso de "unordered_set"
    // para poder revisar rapidamente si el digito esta presente o no
    unordered_set<int> s;

    // Se declara y se inicializa la cantidad de "page-faults"
    int page_faults = 0;

    // Se obtendrá el tamaño del array
    int t = 0;
    while (secuencia[t] >= 0)
    {
        t++;
    }

    t = t - 1;

    for (int i = 0; i < t; i++)
    {
        // Revisa si el marco puede contener la cantidad de digitos
        if (s.size() < marcos)
        {
            // El digito se insertará en el set, si el digito no
            // esta presente, representará un page-fault
            if (s.find(secuencia[i]) == s.end())
            {
                // Se inserta el digito actual en el set
                s.insert(secuencia[i]);

                // Se incrementa el contador de "page-faults"
                page_faults++;

                // Se inserta la cantidad actual de digitos en la cola
                _cola.agregarNum(secuencia[i]);
            }
        }

        // Si el set no está completo, se realizará el FIFO
        else
        {
            // Revisa si el digito esta presente en el set actual
            if (s.find(secuencia[i]) == s.end())
            {
                // Almacenará el primer digito en la cola para ser usado para
                // encontrar y borrar el digito del set
                int val = _cola.obtenerPrimerNum();

                // Borrará el primer digito de la cola
                _cola.eliminarNum();

                // Se borrará el digito del set
                s.erase(val);

                // Insertará el digito actual en el set
                s.insert(secuencia[i]);

                // Insertará los digitos actuales del marco en la cola
                _cola.agregarNum(secuencia[i]);

                // Se incrementa el contador de "page-faults"
                page_faults++;
            }
        }
    }

    return page_faults;
}
