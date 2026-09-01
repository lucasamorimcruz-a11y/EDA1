#include <stdlib.h>
#include <stdio.h>

typedef struct _node
{
    int valor;
    struct _node *atras;
} _node;
typedef struct _fila
{
    struct _node *frente;
    int topo;
} _fila;
_fila *Fila(int elemento){
    _fila *fila_nova = malloc(sizeof(_fila));
    fila_nova->topo = elemento;
    fila_nova->frente = malloc(sizeof(_node));
    fila_nova->frente->valor = elemento;
    fila_nova->frente->atras = NULL;
    return fila_nova;
}
void inserir(_fila *fila, int elemento)
{
    _node *aux = fila->frente;
    while (aux->atras != NULL){
        aux = aux->atras;
    }
    _node *novo_elemento = malloc(sizeof(_node));
    aux->atras  = novo_elemento;
    novo_elemento->atras = NULL;
    novo_elemento->valor = elemento;
    aux = novo_elemento;
}
void remover(_fila *fila)
{
    fila->frente = fila->frente->atras;

}
void topo(_fila *fila)
{
    printf("%i", fila->topo);
}
void mostrar_elementos(_fila *fila)
{
    _node *aux = fila->frente;
    int index = 1;
    while (aux != NULL){
        printf("%i --- ELEMENTO :  %i\n", index, aux->valor);
        index++;
        aux = aux->atras;
    }
}
int main()
{
    _fila *fila = Fila(5);
    inserir(fila, 10);
    inserir (fila, 20);
    inserir (fila, 30);
    inserir (fila, 40);
    inserir (fila, 50);
    mostrar_elementos(fila);
}