#include <bits/stdc++.h>
using namespace std;

typedef struct cola {
    int *valores;
    int capacidad;
    int cuenta;
    int cabeza;
} Cola;

void push(Cola *cola, int valor)
{
    cola->valores[(cola->cabeza+cola->cuenta)%cola->capacidad]=valor;
    cola->cuenta++;
}

void pop(Cola *cola)
{
    cola->cabeza=(cola->cabeza+1)%cola->capacidad;
    cola->cuenta--;
}

int front(Cola *cola) {
    return cola->valores[cola->cabeza];
}

int is_full(Cola *cola) {
    return cola->cuenta == cola->capacidad;
}

int count(Cola *cola) {
    return cola->cuenta;
}

Cola *crea_cola(int capacidad)
{
    Cola *cola=(Cola *)malloc(sizeof(Cola));
    cola->valores=(int *)malloc(sizeof(int)*capacidad);
    cola->capacidad=capacidad;
    cola->cuenta=0;
    cola->cabeza=0;
    return cola;
}

int main()
{
    Cola *cola = crea_cola(4);
    push(cola, 1);
    push(cola, 2);
    push(cola, 4);

    printf("%d\n", front(cola)); // 1

    pop(cola);
    printf("%d\n", front(cola)); // 2

    pop(cola);
    printf("%d\n", front(cola)); // 4
    pop(cola);

    push(cola, 5);
    push(cola, 6);
    push(cola, 7);

    printf("%d\n", front(cola)); // 5

    pop(cola);
    printf("%d\n", front(cola)); // 6

    pop(cola);
    printf("%d\n", front(cola)); // 7
}
