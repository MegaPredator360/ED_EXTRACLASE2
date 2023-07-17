#include "procedimientos.h"

int* procedimientos::agregarSecuencia(string secuencia) {
	try {
		int numero = 0;

		// Se obtendr� la cantidad de numeros de la secuencia
		int cantidadDigitos = _metodosProcedimiento.cantidadNumeros(secuencia);

		// Definimos e inicializamos en array de int en forma de puntero
		int* secuenciaNueva = new int[cantidadDigitos];
		
		for (int i = 0; i < cantidadDigitos; i++) {
			// Asignar� el n�mero hasta encontrar un "espacio"
			numero = stoi(secuencia.substr(0, secuencia.find(" ")));

			// Borrar� el n�mero encontrado de la secuencia para ingresar el siguiente n�mero
			secuencia.erase(0, _metodosProcedimiento.cantidadString(to_string(numero)) + 1);

			// Ingresamos el valor en el array
			secuenciaNueva[i] = numero;
		}
		return secuenciaNueva;
	}
	catch (exception& e) {
		throw e;
	}
}

int procedimientos::pageFaultsFIFO(int* secuencia, int marcos) {
    try {
        cout << endl << "Marcos en FIFO:" << endl;

        // Para ver la cantidad de paginas actuales se hace uso de "unordered_set"
        // para poder revisar rapidamente si el digito esta presente o no
        unordered_set<int> s;

        // Se declara y se inicializa la cantidad de "page-faults"
        int page_faults = 0;

        // Se obtendr� el tama�o del array
        int t = 0;
        while (secuencia[t] >= 0) { t++; }

        for (int i = 0; i < t; i++) {
            // Revisa si el marco puede contener la cantidad de digitos
            if (s.size() < marcos) {
                // El digito se insertar� en el set, si el digito no
                // esta presente, representar� un page-fault
                if (s.find(secuencia[i]) == s.end()) {
                    // Se inserta el digito actual en el set
                    s.insert(secuencia[i]);

                    // Se incrementa el contador de "page-faults"
                    page_faults++;

                    // Se inserta la cantidad actual de digitos en la cola
                    _cola.agregarNum(secuencia[i]);
                }
            }
            // Si el set no est� completo, se realizar� el FIFO
            else {
                // Revisa si el digito esta presente en el set actual
                if (s.find(secuencia[i]) == s.end()) {
                    // Imprimir los marcos
                    for (int num : s) {
                        cout << num << " ";
                    }
                    cout << endl;

                    // Almacenar� el primer digito en la cola para ser usado para
                    // encontrar y borrar el digito del set
                    int val = _cola.obtenerPrimerNum();

                    // Borrar� el primer digito de la cola
                    _cola.eliminarNum();

                    // Se borrar� el digito del set
                    s.erase(val);

                    // Insertar� el digito actual en el set
                    s.insert(secuencia[i]);

                    // Insertar� los digitos actuales del marco en la cola
                    _cola.agregarNum(secuencia[i]);

                    // Se incrementa el contador de "page-faults"
                    page_faults++;
                }
            }
        }
        // Imprimir el ultimo marco
        for (int num : s) {
            cout << num << " ";
        }
        cout << endl;
        return page_faults;
    }
    catch (exception& e) {
        throw e;
    }
}

int procedimientos::pageFaultsLIFO(int* secuencia, int marcos)
{
    try
    {
        cout << endl << "Marcos en LIFO:" << endl;

        // Para ver la cantidad de paginas actuales se hace uso de "unordered_set"
        // para poder revisar rapidamente si el digito esta presente o no
        unordered_set<int> s;

        // Se declara y se inicializa la cantidad de "page-faults"
        int page_faults = 0;

        // Se obtendr� el tama�o del array
        int t = 0;
        while (secuencia[t] >= 0)
        {
            t++;
        }

        for (int i = 0; i < t; i++)
        {
            // Revisa si el marco puede contener la cantidad de digitos
            if (s.size() < marcos)
            {
                // El digito se insertar� en el set, si el digito no
                // esta presente, representar� un page-fault
                if (s.find(secuencia[i]) == s.end())
                {
                    // Se inserta el digito actual en el set
                    s.insert(secuencia[i]);

                    // Se incrementa el contador de "page-faults"
                    page_faults++;

                    // Se inserta la cantidad actual de digitos en la pila
                    _pila.agregarNum(secuencia[i]);
                }
            }

            // Si el set no est� completo, se realizar� el LIFO
            else
            {
                // Revisa si el digito esta presente en el set actual
                if (s.find(secuencia[i]) == s.end())
                {
                    // Imprimir los marcos
                    for (int num : s)
                    {
                        cout << num << " ";
                    }
                    cout << endl;

                    // Almacenar� el primer digito en la pila para ser usado para
                    // encontrar y borrar el digito del set
                    int val = _pila.obtenerPrimerNum();

                    // Borrar� el primer digito de la pila
                    _pila.eliminarNum();

                    // Se borrar� el digito del set
                    s.erase(val);

                    // Insertar� el digito actual en el set
                    s.insert(secuencia[i]);

                    // Insertar� los digitos actuales del marco en la pila
                    _pila.agregarNum(secuencia[i]);

                    // Se incrementa el contador de "page-faults"
                    page_faults++;
                }
            }
        }

        // Imprime el ultimo marco
        for (int num : s)
        {
            cout << num << " ";
        }
        cout << endl;

        return page_faults;
    }
    catch (exception& e)
    {
        throw e;
    }
}


int procedimientos::optimalPage(int* secuencia, int marcos) {
    try
    {
        cout << endl << "Marcos en ÓPTIMO:" << endl;

        // Para ver la cantidad de paginas actuales se hace uso de "unordered_set"
        // para poder revisar rapidamente si el digito esta presente o no
        unordered_set<int> s;

        // Se declara y se inicializa la cantidad de "page-faults"
        int page_faults = 0;

        // Se obtendr� el tama�o del array
        int t = 0;
        while (secuencia[t] >= 0)
        {
            t++;
        }

        for (int i = 0; i < t; i++)
        {
            // Revisa si el marco puede contener la cantidad de digitos
            if (s.size() < marcos)
            {
                // El digito se insertar� en el set, si el digito no
                // esta presente, representar� un page-fault
                if (s.find(secuencia[i]) == s.end())
                {
                    // Se inserta el digito actual en el set
                    s.insert(secuencia[i]);

                    // Se incrementa el contador de "page-faults"
                    page_faults++;

                    // Se inserta la cantidad actual de digitos en la cola
                    _optimo.agregarNum(secuencia[i]);
                }
            }

            // Si el set no est� completo, se realizar� el OPTIMO
            else
            {
                // Revisa si el digito esta presente en el set actual
                if (s.find(secuencia[i]) == s.end())
                {
                    // Imprimir los marcos
                    for (int num : s)
                    {
                        cout << num << " ";
                    }
                    cout << endl;

                    // Almacenar� el primer digito en la cola para ser usado para
                    // encontrar y borrar el digito del set
                    int val = _optimo.obtenerPrimerNum();

                    // Borrar� el primer digito de la cola
                    _optimo.eliminarNum();

                    // Se borrar� el digito del set
                    s.erase(val);

                    // Insertar� el digito actual en el set
                    s.insert(secuencia[i]);

                    // Insertar� los digitos actuales del marco en la cola
                    _optimo.agregarNum(secuencia[i]);

                    // Se incrementa el contador de "page-faults"
                    page_faults++;
                }
            }
        }

        // Imprimir el ultimo marco
        for (int num : s)
        {
            cout << num << " ";
        }
        cout << endl;

        return page_faults;
    }
    catch (exception& e)
    {
        throw e;
    }
}