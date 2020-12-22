#include <iostream>
using namespace std;

struct Registro
{
	int algo;
	int otro_algo;
};
struct Nodo {
	Registro reg;
	Nodo* sig;
};

void queue(Nodo*&, Nodo*&, Registro);
int cantidadElementos(Nodo*&);
int main() {
	Nodo* fte = NULL;
	Nodo* fin = NULL;
	Registro test;
	for (int i = 0; i < 7; i++)
	{
		test.algo = i;
		test.otro_algo = 2 * i;
		queue(fte, fin, test);
	}

	int c = cantidadElementos(fte);
	cout << "cantidad de nodos: " << c << endl;
	return 0;
}
void queue(Nodo*& fte, Nodo*& fin, Registro rgt) {
	Nodo* aux = new Nodo();
	aux->reg = rgt;
	aux->sig = NULL;
	if (fte == NULL)
		fte = aux;
	else
		fin->sig = aux;
	fin = aux;
}
int cantidadElementos(Nodo*& fte) {
	Nodo* aux = fte;
	int cant = 0;
	while (aux != NULL)
	{
		aux = aux->sig;
		cant++;
	}
	return cant;
}