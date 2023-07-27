#include "procedimientos.h"

int* procedimientos::agregarSecuencia(string secuencia) 
{
	try 
    {
		int numero = 0;

		// Se obtendrá la cantidad de numeros de la secuencia
		int cantidadDigitos = cantidadNumeros(secuencia);

		// Definimos e inicializamos en array de int en forma de puntero
		int* secuenciaNueva = new int[cantidadDigitos];
		
		for (int i = 0; i < cantidadDigitos; i++) 
        {
			// Asignará el número hasta encontrar un "espacio"
			numero = stoi(secuencia.substr(0, secuencia.find(" ")));

			// Borrará el número encontrado de la secuencia para ingresar el siguiente número
			secuencia.erase(0, cantidadString(to_string(numero)) + 1);

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

int procedimientos::pageFaultsFIFO(int* _secuencia, int _marcos) 
{
    try 
    {
        cout << endl << "Marcos en FIFO:" << endl;

        // Para ver la cantidad de paginas actuales se hace uso de "unordered_set"
        // para poder revisar rapidamente si el digito esta presente o no
        // Ver declaración en el .h

        // Se limpia el "unordered_set" en caso de ser usado anteriormente
        set.clear();

        // Se limipia la cola en caso de ser usado anteriormente
        _cola.eliminarDatos();
        

        // Se declara y se inicializa la cantidad de "page-faults"
        int page_faults = 0;

        // Se obtendrá la cantidad de digitos en la secuencia
        int t = 0;
        while (_secuencia[t] >= 0) 
        { 
            t++; 
        }

        for (int i = 0; i < t; i++) 
        {
            // Revisa si el marco puede contener la cantidad de digitos
            if (set.size() < _marcos) 
            {
                // El digito se insertará en el set, si el digito no
                // esta presente, representará un page-fault
                if (set.find(_secuencia[i]) == set.end()) 
                {
                    // Se inserta el digito actual en el set
                    set.insert(_secuencia[i]);

                    // Se incrementa el contador de "page-faults"
                    page_faults++;

                    // Se inserta la cantidad actual de digitos en la cola
                    _cola.agregarNum(_secuencia[i]);
                }
            }
            // Si el set no está completo, se realizará el FIFO
            else 
            {
                // Revisa si el digito esta presente en el set actual
                if (set.find(_secuencia[i]) == set.end()) 
                {

                    // Almacenará el primer digito en la cola para ser usado para
                    // encontrar y borrar el digito del set
                    int val = _cola.obtenerPrimerNum();

                    // Borrará el primer digito de la cola
                    _cola.eliminarNum();

                    // Se borrará el digito del set
                    set.erase(val);

                    // Insertará el digito actual en el set
                    set.insert(_secuencia[i]);

                    // Insertará los digitos actuales del marco en la cola
                    _cola.agregarNum(_secuencia[i]);

                    // Se incrementa el contador de "page-faults"
                    page_faults++;
                }
            }

            // Imprimir el contenido del marco
            for (int num: set) 
            {
                cout << num << " ";
            }
            cout << endl;

        }
        return page_faults;
    }
    catch (exception& e) 
    {
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
        // Ver declaración en el .h

        // Se limpia el "unordered_set" en caso de ser usado anteriormente
        set.clear();

        // Se limpia la pila en caso de ser usado anteriormente
        _pila.eliminarDatos();

        // Se declara y se inicializa la cantidad de "page-faults"
        int page_faults = 0;

        // Se obtendrá la cantidad de digitos en la secuencia
        int t = 0;
        while (secuencia[t] >= 0)
        {
            t++;
        }

        for (int i = 0; i < t; i++)
        {
            // Revisa si el marco puede contener la cantidad de digitos
            if (set.size() < marcos)
            {
                // El digito se insertará en el set, si el digito no
                // esta presente, representará un page-fault
                if (set.find(secuencia[i]) == set.end())
                {
                    // Se inserta el digito actual en el set
                    set.insert(secuencia[i]);

                    // Se incrementa el contador de "page-faults"
                    page_faults++;

                    // Se inserta la cantidad actual de digitos en la pila
                    _pila.agregarNum(secuencia[i]);
                }
            }

            // Si el set no está completo, se realizará el LIFO
            else
            {
                // Revisa si el digito esta presente en el set actual
                if (set.find(secuencia[i]) == set.end())
                {

                    // Almacenará el primer digito en la pila para ser usado para
                    // encontrar y borrar el digito del set
                    int val = _pila.obtenerPrimerNum();

                    // Borrará el primer digito de la pila
                    _pila.eliminarNum();

                    // Se borrará el digito del set
                    set.erase(val);

                    // Insertará el digito actual en el set
                    set.insert(secuencia[i]);

                    // Insertará los digitos actuales del marco en la pila
                    _pila.agregarNum(secuencia[i]);

                    // Se incrementa el contador de "page-faults"
                    page_faults++;
                }
            }

            // Imprime el contenido del marco
            for (int num: set)
            {
                cout << num << " ";
            }
            cout << endl;
        }

        return page_faults;
    }
    catch (exception& e)
    {
        throw e;
    }
}


int procedimientos::pageFaultsOptimal(int* _secuencia, int _marcos) 
{
    try
    {
        cout << endl << "Marcos en Optimo:" << endl;
        
        // Se eliminan los datos del vector en caso de ser usado anteriormente 
        _optimo.eliminarDatos();

        // Se obtendrá la cantidad de digitos en la secuencia
        int t = 0;
        while (_secuencia[t] >= 0)
        {
            t++;
        }

        // Irá por cada pagina revisando si hay un acierto o un page fault
        int acierto = 0;
        for (int i = 0; i < t; i++) {

            auxiliar = _optimo.obtenerDatos();

            // Si el digito se encontró en el marco es igual a un acierto
            if (buscarMarco(_secuencia[i], auxiliar)) 
            {
                // Se suma un acierto a si mismo para luego ser restado por la cantidad de digitos en la secuencia
                // lo que nos dará la cantidad de page-faults en la secuencia
                acierto++;

                // Se imprimen los datos del marco para ser mostrados al usuario
                for (int num : auxiliar)
                {
                    cout << num << " ";
                }
                cout << endl;

                // Ignorará el resto del contenido del for y volverá al inicio del for
                continue;
            }

            // Si el digito no se encontró en el marco es igual a un page-fault

            // Verificará si hay un espacio disponible en el marco
            if (_optimo.cantidadNum() < _marcos)
            {
                _optimo.agregarNum(_secuencia[i]);
            }
                
            // Se buscará la pagina que será remplazada
            else 
            {
                auxiliar = _optimo.obtenerDatos();

                int p = predecirMarco(_secuencia, auxiliar, t, i + 1);
                _optimo.cambiarDato(p, _secuencia[i]);
            }


            // Imprime el contenido del marco
            auxiliar = _optimo.obtenerDatos();
            for (int num: auxiliar)
            {
                cout << num << " ";
            }
            cout << endl;
        }
        return t - acierto;
    }
    catch (exception& e)
    {
        throw e;
    }
}