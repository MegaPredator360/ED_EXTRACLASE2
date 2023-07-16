#include <stack>
#include <iostream>

using namespace std;

class pilas {
public:
	void agregarNum(const int&);
	void eliminarNum();
	void mostrarNum();
	bool estaVacia();

private:
	stack<int> pila;
};
