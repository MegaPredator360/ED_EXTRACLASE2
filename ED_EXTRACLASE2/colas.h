#include "std.h"

class colas {
public:
	void agregarNum(const int&);
	void eliminarNum();
	void mostrarNum();//Cola en espera del numero
	bool estaVacia();

private:
	queue<int> cola;
};

