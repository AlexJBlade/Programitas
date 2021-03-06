#include <bits/stdc++.h>
using namespace std;

typedef struct lista {
    int valor;
    lista *siguiente;
} Lista;

Lista *crea(int valor)
{
    Lista *lista=(Lista *) malloc(sizeof(Lista));
    lista ->valor= valor;
    lista ->siguiente=NULL;
    return lista;
}

void agrega(Lista *lista, int valor)
{
    Lista *actual = lista;
    while(actual->siguiente != NULL) {
         actual = actual->siguiente;
    }
    actual->siguiente = crea(valor);
}

int cuenta(Lista *lista)
{
    int i=1;
    Lista *actual = lista;
    while(actual->siguiente != NULL) {
         actual = actual->siguiente;
         i++;
    }
    return i;
}

int valor_en(Lista *lista, int posicion)
{
    Lista *actual = lista;
    for(int i=0; i<posicion; i++){
        if (actual->siguiente == NULL)
            return -1;
        actual = actual->siguiente;
    }
    return actual->valor;
}

void limpia(Lista *lista)
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
    Lista *lista = crea(1);
    agrega(lista, 2);
    agrega(lista, 3);
    printf("%d\n", valor_en(lista, 1)); // 2
    printf("%d\n", cuenta(lista)); // 3
    limpia(lista);
    return 0;
}
