#include <bits/stdc++.h>
using namespace std;

typedef struct lista {
    int valor;
    lista *siguiente;
} Lista;

typedef struct cola
{
    Lista *cabeza;
    Lista *rabo;
} Cola;

Lista *crea(int valor)
{
    Lista *lista=(Lista *) malloc(sizeof(Lista));
    lista ->valor= valor;
    lista ->siguiente=NULL;
    return lista;
}


void push(Cola *cola, int valor)
{
    if (cola->cabeza == NULL) {
        cola->cabeza = cola->rabo = crea(valor);
    } else {
        cola->rabo->siguiente= crea(valor);
        cola->rabo= cola->rabo->siguiente;
    }
}

void pop(Cola *cola)
{
    if(cola->cabeza==NULL)
        return;

    if(cola->cabeza==cola->rabo)
    {
        free(cola->cabeza);
        return;
    }

    Lista *auxiliar= cola->cabeza;
    cola->cabeza= cola->cabeza->siguiente;
    free(auxiliar);
}

int front(Cola *cola) {
    if(cola->cabeza==NULL)
        return -1;
    return cola->cabeza->valor;
}

Cola *crea_cola()
{
    Cola *cola = (Cola *)malloc(sizeof(Cola));
    cola->cabeza = cola->rabo = NULL;
    return cola;
}

int main()
{
    Cola *cola = crea_cola();
    push(cola, 1);
    push(cola, 2);
    push(cola, 4);

    printf("%d\n", front(cola)); // 1

    pop(cola);
    printf("%d\n", front(cola)); // 2

    pop(cola);
    printf("%d\n", front(cola)); // 4
}
