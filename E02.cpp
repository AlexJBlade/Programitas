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

int esta_vacia(Lista *lista)
{
    return (lista == NULL);
}

Lista *agrega(Lista *lista, int valor)
{

    Lista *auxiliar = crea(valor);

    if (esta_vacia(lista))
        return auxiliar;

    Lista *actual = lista;

    while(actual->siguiente != NULL) {
         actual = actual->siguiente;
    }
    actual->siguiente = auxiliar;

    return lista;
}

int cuenta(Lista *lista)
{
    if (esta_vacia(lista))
        return 0;

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
    if (esta_vacia(lista))
        return -1;

    Lista *actual = lista;
    for(int i=0; i<posicion; i++){
        if (actual->siguiente == NULL)
            return -1;
        actual = actual->siguiente;
    }
    return actual->valor;
}

Lista *limpia(Lista *lista)
{
    if (esta_vacia(lista))
        return NULL;

    Lista *actual =lista;
    while(actual->siguiente != NULL){
        Lista *siguiente =actual->siguiente;
        free(actual);
        actual=siguiente;
    }
    free(actual);

    return NULL;
}

int valor_inicio(Lista *lista)
{
    if (esta_vacia(lista))
        return -1;

    Lista *actual = lista;
    return actual->valor;
}

int valor_fin(Lista *lista)
{
    if (esta_vacia(lista))
        return -1;

    Lista *actual = lista;

    while(actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    return actual->valor;
}

Lista *agrega_inicio(Lista *lista, int valor)
{
    Lista *anterior = crea(valor);

    if (esta_vacia(lista))
        return anterior;

    anterior->siguiente = lista;

    return anterior;
}

Lista *agrega_en(Lista *lista, int valor, int posicion)
{
    if (esta_vacia(lista))
        return crea(valor);

    if (posicion == 0)
        return agrega_inicio(lista, valor);

    Lista *auxiliar=crea(valor);
    Lista *anterior = NULL;
    Lista *actual = lista;
    for(int i=0; i<posicion; i++){
        if (actual->siguiente == NULL)
            return lista;
        anterior =actual;
        actual = actual->siguiente;
    }
    anterior->siguiente = auxiliar;
    auxiliar->siguiente = actual;
    return lista;
}

Lista *borra_inicio(Lista *lista)
{
    if (esta_vacia(lista))
        return NULL;

    Lista *anterior = lista;
    Lista *actual = lista->siguiente;

    free(anterior);

    return actual;
}

Lista *borra_fin(Lista *lista)
{
    if (esta_vacia(lista))
        return NULL;

    Lista *actual =lista;
    Lista *anterior =NULL;

    while(actual->siguiente != NULL){
        anterior=actual;
        actual = actual->siguiente;

    }
    anterior->siguiente = NULL;
    free(actual);
    return lista;

}

Lista *borra_en(Lista *lista, int posicion)
{
    if (esta_vacia(lista))
        return NULL;

    if (posicion == 0)
        return borra_inicio(lista);

    Lista *anterior = NULL;
    Lista *actual = lista;
    for(int i=0; i<posicion; i++){
        if (actual->siguiente == NULL)
            return lista;
        anterior = actual;
        actual = actual->siguiente;
    }
    anterior->siguiente = actual->siguiente;
    free(actual);
    return lista;
}

Lista *borra_en_valor(Lista *lista, int valor)
{
    Lista *actual =lista;
    Lista *anterior =NULL;

    while(actual->valor != valor){
        if (actual->siguiente == NULL)
            return lista;
        anterior = actual;
        actual = actual->siguiente;
    }
    anterior->siguiente = actual->siguiente;
    free(actual);
    return lista;
}

int main()
{
    Lista *lista = NULL;
    lista = agrega(lista, 1);
    lista = agrega(lista, 2);
    lista = agrega(lista, 4);

    printf("%d\n", valor_en(lista, 0)); // 1
    printf("%d\n", valor_en(lista, 1)); // 2
    printf("%d\n", valor_en(lista, 2)); // 4
    printf("%d\n\n", cuenta(lista)); // 3

    lista = agrega_en(lista, 3, 2);
    printf("%d\n", valor_en(lista, 0)); // 1
    printf("%d\n", valor_en(lista, 1)); // 2
    printf("%d\n", valor_en(lista, 2)); // 3
    printf("%d\n", valor_en(lista, 3)); // 4
    printf("%d\n\n", cuenta(lista)); // 4

    lista = borra_en(lista, 1);
    printf("%d\n", valor_en(lista, 0)); // 1
    printf("%d\n", valor_en(lista, 1)); // 3
    printf("%d\n", valor_en(lista, 2)); // 4
    printf("%d\n\n", cuenta(lista)); // 3

    lista = agrega_inicio(lista, 0);
    printf("%d\n", valor_en(lista, 0)); // 0
    printf("%d\n", valor_en(lista, 1)); // 1
    printf("%d\n", valor_en(lista, 2)); // 3
    printf("%d\n\n", cuenta(lista)); // 4

    lista = borra_inicio(lista);
    printf("%d\n", valor_en(lista, 0)); // 1
    printf("%d\n", valor_en(lista, 1)); // 3
    printf("%d\n", valor_en(lista, 2)); // 4
    printf("%d\n\n", cuenta(lista)); // 3

    lista = borra_en_valor(lista, 3);
    printf("%d\n", valor_en(lista, 0)); // 1
    printf("%d\n", valor_en(lista, 1)); // 4
    printf("%d\n\n", cuenta(lista)); // 2

    lista = limpia(lista);
    return 0;
}
