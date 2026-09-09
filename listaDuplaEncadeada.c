#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node
{
    int val;
    struct _node *proximo;
    struct _node *anterior;
} _node;

typedef struct _listaDupla
{
    _node *comeco;
    _node *fim;
} _listaDupla;
_listaDupla *listaDupla()
{
    _listaDupla *l = malloc(sizeof(_listaDupla));
    if (l == NULL)
    {
        perror("Erro ao alocar memoria");
        return NULL;
    }
    l->comeco = NULL;
    l->fim = NULL;
    return l;
}
bool vazia(_listaDupla *lista)
{
    if (lista->fim == NULL && lista->comeco == NULL)
    {
        return true;
    }
    return false;
}
void inserir_comeco(int valor, _listaDupla *lista)
{
    _node *aux = malloc(sizeof(_node));
    if (aux == NULL)
        return;
    aux->val = valor;
    aux->anterior = NULL;
    aux->proximo = lista->comeco;
    if (lista->comeco != NULL)
        lista->comeco->anterior = aux;
    else
        lista->fim = aux;
    lista->comeco = aux;
}
void inserir_fim(int valor, _listaDupla *lista)
{
    _node *aux = malloc(sizeof(_node));
    if (aux == NULL)
        return;
    aux->val = valor;
    aux->proximo = NULL;
    aux->anterior = lista->fim;
    if (lista->fim != NULL)
        lista->fim->proximo = aux;
    else
        lista->comeco = aux;
    lista->fim = aux;
}
void remover(int valor, _listaDupla *lista)
{
    if (vazia(lista))
        return;
    _node *aux = lista->comeco;
    while (aux != NULL && aux->val != valor)
        aux = aux->proximo;
    if (aux == NULL)
        return;
    if (aux->anterior != NULL)
        aux->anterior->proximo = aux->proximo;
    else
        lista->comeco = aux->proximo;
    if (aux->proximo != NULL)
        aux->proximo->anterior = aux->anterior;
    else
        lista->fim = aux->anterior;
    free(aux);
}
void remover_fim(_listaDupla *lista)
{
    if (vazia(lista))
        return;
    _node *aux = lista->fim;
    lista->fim = aux->anterior;
    if (lista->fim != NULL)
        lista->fim->proximo = NULL;
    else
        lista->comeco = NULL;
    free(aux);
}
void remover_inicio(_listaDupla *lista)
{
    if (vazia(lista))
        return;
    _node *aux = lista->comeco;
    lista->comeco = aux->proximo;
    if (lista->comeco != NULL)
        lista->comeco->anterior = NULL;
    else
        lista->fim = NULL;
    free(aux);
}
void procurar_elemento(int elemento, _listaDupla *lista)
{
    if (vazia(lista))
        return;
    int index = 1;
    _node *aux = lista->comeco;
    while (aux != NULL && aux->val != elemento)
    {
        aux = aux->proximo;
        index++;
    }
    if (aux == NULL)
    {
        printf("Elemento não encontrado.\n");
        return;
    }
    printf("O elemento %i está na %i° posição\n", aux->val, index);
    return;
}
void mostrar_lista(_listaDupla *lista)
{
    if (vazia(lista))
        return;
    int index = 1;
    _node *aux = lista->comeco;
    while (aux != NULL)
    {
        printf("- INDEX: %i -- VALOR: %i\n", index, aux->val);
        aux = aux->proximo;
        index++;
    }
    return;
}
int main()
{
    _listaDupla *lista = listaDupla();
    inserir_comeco(40, lista);
    inserir_fim(50, lista);
    inserir_comeco(30, lista);
    inserir_comeco(20, lista);
    inserir_comeco(10, lista);
    mostrar_lista(lista);
    remover_fim(lista);
    remover(10, lista);
    remover(20, lista);
    mostrar_lista(lista);
}
