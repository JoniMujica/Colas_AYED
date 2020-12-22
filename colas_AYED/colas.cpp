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
Registro unqueue(Nodo*&, Nodo*&);
bool isDel(Nodo*&, Nodo*&);
void MostrarElementos(Nodo*&);
int main() {
	Nodo* fte = NULL;
	Nodo* fin = NULL;

	//hago este for para rellenar los datos en la cola
	Registro test;
	for (int i = 0; i < 10; i++)
	{
		test.algo = i;
		test.otro_algo = 2 * i;
		queue(fte, fin, test);
	}
	MostrarElementos(fte);
	if (isDel(fte, fin))
		cout << "se pudo eliminar" << endl;
	else
		cout << "no es posible eliminar" << endl;

	MostrarElementos(fte);
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

Registro unqueue(Nodo*& fte, Nodo*& fin) {
	Registro x;
	Nodo* p = fte;
	x = p->reg;
	fte = p->sig;
	if (fte == NULL)
		fin = NULL;
	delete p;
	return x;
}

bool isDel(Nodo*& fte, Nodo*& fin) {
	for (int i = 0; i < 2; i++)
	{
		if (fte != NULL)
			unqueue(fte, fin);
		else
			return false;
	}
	return true;
}
void MostrarElementos(Nodo*& fte) {
	Nodo* aux = fte;
	cout << "========elementos========" << endl;
	while (aux != NULL)
	{
		cout << "________elemento_____" << endl;
		cout << "elementos de la pila " << aux->reg.algo << endl; 
		cout << "elementos de la pila " << aux->reg.otro_algo << endl;
		aux = aux->sig;
	}
}