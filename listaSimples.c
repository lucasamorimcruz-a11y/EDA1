#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int valor;
    struct _node *next;
} _node;
typedef struct Lista {
    _node *head;
} Lista;

Lista *_Lista (){
    Lista *lista = malloc (sizeof(Lista));
    lista->head = NULL;
    return lista;
}
void inserir_elemento (Lista *lista, int elemento){
    _node *nova_cabeca = malloc(sizeof(_node));
    nova_cabeca->valor = elemento;
    nova_cabeca->next = lista->head;
    lista->head = nova_cabeca;
}

void remover_elemento(Lista *lista, int elemento){
    if (lista->head == NULL) {
        printf("Lista vazia, nao tem o que remover.\n");
        return;
    }
    _node *atual = lista->head;
    _node *anterior = NULL;
    while (atual != NULL && atual->valor != elemento) {
        anterior = atual;
        atual = atual->next;
    }
    if (atual == NULL) {
        perror ("Elemento nao esta na lista");
        return;
    }
    if (anterior == NULL) {
        lista->head = atual->next;
    }
    else {
        anterior->next = atual->next;
    }

    free(atual);
}
void procurar_elemento (Lista *lista, int elemento){
    _node *atual = malloc(sizeof(_node));
    atual = lista->head;
    int index = 1;
    while (atual->valor != elemento){
        atual = atual->next;
        index++;
    }
    if (atual == NULL){
        printf("Elemento não está na lista.\n");
    }
    printf("O elemento %i está no %i° lugar da lista.\n", elemento,index);
    return;
}
void mostrar_lista (Lista *lista){
    _node *atual = lista->head;
    int index = 1;
    if (atual == NULL){
        printf("Lista vazia\n");
    }
    while (atual != NULL){
        printf("%i ---- ELEMENTO: %i\n", index, atual->valor);
        atual = atual->next;
        index++;
    }
    while (atual != NULL){
        printf("%i  --- ELEMENTO: %i\n", index, atual->valor);
        atual = atual->next;
        index++;
    }
    return;
}
    
int main (){
    Lista *lista = _Lista();
    inserir_elemento (lista, 10);
    inserir_elemento (lista, 20);
    inserir_elemento (lista, 30);
    inserir_elemento (lista, 40);
    inserir_elemento (lista, 50);
    mostrar_lista(lista);
    procurar_elemento (lista, 50);
    remover_elemento (lista, 30);
    remover_elemento (lista, 20);
    remover_elemento (lista, 40);
    remover_elemento(lista, 50);
    remover_elemento(lista, 10);
    mostrar_lista(lista);
}