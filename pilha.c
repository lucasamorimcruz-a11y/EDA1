#include <stdlib.h>
#include <stdio.h>

typedef struct _node
{
    int valor;
    struct _node *proximo;
} _node;

typedef struct
{
    _node *topo;
    int tamanho;
} _pilha;

_pilha *Pilha()
{
    _pilha *p = malloc(sizeof(_pilha));
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}
int vazio(_pilha *p)
{
    return p->topo == NULL;
}
void empurra(_pilha *p, int valor)
{
    _node *node = malloc(sizeof(_node));
    if (node == NULL)
    {
        perror("Erro ao alocar memoria");
        return;
    }
    node->valor = valor;
    node->proximo = p->topo;
    p->topo = node;
    p->tamanho++;
}
void excluir(_pilha *p)
{
    if (vazio(p))
    {
        printf("Pilha vazia!\n");
        return;
    }
    _node *aux = p->topo;
    p->topo = aux->proximo;
    p->tamanho--;
    free(aux);
}
void mostrar_topo(_pilha *p)
{
    if (vazio(p))
    {
        printf("Pilha vazia!\n");
        return;
    }
    printf("%i\n", p->topo->valor);
    return;
}
void mostrar(_pilha *p)
{
    _node *atual = p->topo;
    int index = 1;
    while (atual != NULL)
    {
        printf("%i: %i --- TAMANHO DA PILHA: %i\n", index, atual->valor, p->tamanho);
        atual = atual->proximo;
        index++;
    }
    return;
}
void liberar_pilha (_pilha *pilha){
    while (!vazio(pilha)){
        excluir(pilha);
    }
    free(pilha);
    printf("Pilha não existe mais!\n");
}
int main()
{
    _pilha *pilha = Pilha();
    empurra(pilha, 10);
    empurra(pilha, 20);
    empurra(pilha, 30);
    empurra(pilha, 40);
    empurra(pilha, 50);
    empurra(pilha, 60);
    empurra(pilha, 70);
    mostrar(pilha);
    excluir(pilha);
    excluir(pilha);
    mostrar(pilha);
    excluir(pilha);
    mostrar(pilha);
    excluir(pilha);
    mostrar(pilha);
    liberar_pilha(pilha);
}