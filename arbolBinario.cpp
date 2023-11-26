#include <iostream>
#include <cstdlib>
#include <ctime>

struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int v) : valor(v), izquierda(nullptr), derecha(nullptr) {}
};

class ArbolBinario {
private:
    Nodo* raiz;

    Nodo* insertarRecursivo(Nodo* nodo, int valor) {
        if (nodo == nullptr) {
            return new Nodo(valor);
        }

        if (valor < nodo->valor) {
            nodo->izquierda = insertarRecursivo(nodo->izquierda, valor);
        } else if (valor > nodo->valor) {
            nodo->derecha = insertarRecursivo(nodo->derecha, valor);
        }

        return nodo;
    }

    void inordenRecursivo(Nodo* nodo) {
        if (nodo != nullptr) {
            inordenRecursivo(nodo->izquierda);
            std::cout << nodo->valor << " ";
            inordenRecursivo(nodo->derecha);
        }
    }

    void preordenRecursivo(Nodo* nodo) {
        if (nodo != nullptr) {
            std::cout << nodo->valor << " ";
            preordenRecursivo(nodo->izquierda);
            preordenRecursivo(nodo->derecha);
        }
    }

    void postordenRecursivo(Nodo* nodo) {
        if (nodo != nullptr) {
            postordenRecursivo(nodo->izquierda);
            postordenRecursivo(nodo->derecha);
            std::cout << nodo->valor << " ";
        }
    }

public:
    ArbolBinario() : raiz(nullptr) {}

    void insertar(int valor) {
        raiz = insertarRecursivo(raiz, valor);
    }

    void inorden() {
        inordenRecursivo(raiz);
        std::cout << std::endl;
    }

    void preorden() {
        preordenRecursivo(raiz);
        std::cout << std::endl;
    }

    void postorden() {
        postordenRecursivo(raiz);
        std::cout << std::endl;
    }

    void recorridoAleatorio() {
        int tipoRecorrido = rand() % 3;

        switch (tipoRecorrido) {
            case 0:
                std::cout << "Recorrido Inorden: ";
                inorden();
                break;
            case 1:
                std::cout << "Recorrido Preorden: ";
                preorden();
                break;
            case 2:
                std::cout << "Recorrido Postorden: ";
                postorden();
                break;
        }

        std::cout << std::endl;
    }
};

int main() {
    srand(time(0));

    ArbolBinario arbol;

    arbol.insertar(5);
    arbol.insertar(3);
    arbol.insertar(7);
    arbol.insertar(2);
    arbol.insertar(4);
    arbol.insertar(6);
    arbol.insertar(8);

    std::cout << "Recorrido Aleatorio: ";
    arbol.recorridoAleatorio();

    return 0;
}
