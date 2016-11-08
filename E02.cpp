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

int valor_inicio(Lista *lista)
{
    Lista *actual = lista;
    return actual->valor;
}

int valor_fin(Lista *lista)
{
    Lista *actual = lista;

    while(actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    return actual->valor;
}

Lista *agrega_inicio(Lista *lista, int valor)
{
    // TODO
}

Lista *agrega_en(Lista *lista, int valor, int posicion)
{
    // TODO
}

Lista *borra_inicio(Lista *lista)
{
    // TODO
}

Lista *borra_fin(Lista *lista)
{
    Lista *actual =lista;
    Lista *anterior =NULL;

    while(actual->siguiente != NULL){
        anterior=actual;
        actual = actual->siguiente;

    }
    anterior->siguiente=NULL;
    free(actual);
    return lista;

}

Lista *borra_en(Lista *lista, int posicion)
{
    // TODO
}

Lista *borra_en_valor(Lista *lista, int valor)
{
    // TODO
}

int esta_vacia(Lista *lista)
{
    return (lista == NULL);
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
