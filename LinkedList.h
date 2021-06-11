#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include "Node.h"

class LinkedList;
std::ostream& operator<< (std::ostream& o, const LinkedList& elemento);

class LinkedList {
	private:
		int size;
		Node* head;
	public:
		LinkedList();
		//void Ordenar(int);
		void insert(int);
		void remove(int);
		void buscar(int);
		friend std::ostream& operator<<(std::ostream& o, const LinkedList& elemento);
		~LinkedList();
};

LinkedList::LinkedList() {
	size = 0;
	head = new Node();
}

/*
void LinkedList::Ordenar(int data) {
	Node* actual;
	Node* siguiente;
	int t;
	actual = head;

	while (actual->sgte() != NULL) {
		siguiente = actual->sgte();

		while (siguiente != NULL) {
			if (actual->dato() > siguiente->dato()) {
				t = siguiente->dato();
				siguiente->dato() = actual->dato();
				actual->dato() = t;
			}
			siguiente = siguiente->sgte();
		}
		actual = actual->sgte();
		siguiente = actual->sgte();
	}
}
*/
void LinkedList::insert(int data) {
	if (size != 0) {
		Node* aux;
		aux = head;
		for (int i = 1; i < size; i++) {
			aux = aux->sgte();
		}
		Node elemento;
		elemento.acceder(data);
		aux->fill(elemento);
		size += 1;
	}
	else {
		head->acceder(data);
		size += 1;
	}
}

void LinkedList::remove(int elemento) {
	//en caso Node *next sea privado
	if (size > 0) {
		Node *aux;
		Node *aux1;
		aux = head;
		if (aux->dato() == elemento) {
			head = head->sgte();
			size--;
		}
		else {
			for (int i = 0; i < size; i++) {
				if (i == 0) {
					aux1 = head;
				}
				if (aux->dato() != elemento) {
					if (i > 0) {
						aux1 = aux1->sgte();
					}aux = aux->sgte();
				}
				else
					break;
			}
			int i = 0;
			if (i < size - 1) {
				aux = aux->sgte();
				aux1->fill(*aux);
				size--;
			}
			else if (i == size - 1) {
				aux = NULL;
				size--;
			}
			else
				std::cout << "Valor inexistente\n";
		}
	}
	//en caso Node *next sea publico
	/*
	Node *aux = head;
    	Node*aux1 = aux->next;

    	if (pos<1 || pos>size) {
        	cout << "No existe posicion " << endl;
    	}
    	else if (pos == 1) {
        	head = aux->next;
    	}
    	else {
        	for (int i = 1; i <= pos; i++) {
            		if (i == pos) {
                		Node* node = aux1;
                		aux->next = aux1->next;
                		delete node;
                		size--;
            		}
            		aux= aux->next;
            		aux1=aux1->next;
        	}
    	}*/
}

void LinkedList::buscar(int data) {
	Node* aux;
	aux = head;
	int i = 0;
	for (i = 0; i < size; i++) {
		if (aux->dato() != data) {
			aux = aux->sgte();
		}
		else
			break;
	}
	if (i < size)
		std::cout << "El valor " << aux->dato() << " esta en la posicion " << i << "\n";
	else
		std::cout << "Valor inexistente" << "\n";

}

std::ostream& operator << (std::ostream& o, const LinkedList& elemento) {
	Node* aux;
	aux = elemento.head;
	for (int i = 0; i < elemento.size; i++) {
		if (i < elemento.size - 1) {
			o << aux->dato() << " ";
		}
		else
			o << aux->dato() << "\n";
		aux = aux->sgte();
	}
	return o;
}

LinkedList::~LinkedList() {
	delete head;
}

#endif
