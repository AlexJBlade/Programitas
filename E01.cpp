#include <bits/stdc++.h>
using namespace std;

typedef struct lista {
    int valor;
    lista *siguiente;
} Lista;

Lista *Crea(int valor)
{
    Lista *lista=(Lista *) malloc(sizeof(Lista));
    lista ->valor= valor;
    lista ->siguiente=NULL;
    return lista;
}

void Agrega(Lista *lista, int valor)
{
    Lista *actual = lista;
    while(actual->siguiente != NULL) {
         actual = actual->siguiente;
    }
    actual->siguiente = Crea(valor);
}

int Cuenta(Lista *lista)
{
    int i=1;
    Lista *actual = lista;
    while(actual->siguiente != NULL) {
         actual = actual->siguiente;
         i++;
    }
    return i;
}

int ValorEn(Lista *lista, int posicion)
{
    Lista *actual = lista;
    for(int i=0; i<posicion; i++){
        if (actual->siguiente == NULL)
            return -1;
        actual = actual->siguiente;
    }
    return actual->valor;
}

void Limpia(Lista *lista)
{
    Lista *actual =lista;
    while(actual->siguiente != NULL){
        Lista *siguiente =actual->siguiente;
        free(actual);
        actual=siguiente;
    }
    free(actual);
}

int main()
{
    Lista *lista = Crea(1);
    Agrega(lista, 2);
    Agrega(lista, 3);
    printf("%d\n", ValorEn(lista, 1)); // 2
    printf("%d\n", Cuenta(lista)); // 3
    Limpia(lista);
    return 0;
}
