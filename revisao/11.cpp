#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

struct No
{
    int valor;
    struct No *prox;
};
struct Fila
{
    No *inicio;
    No *fim;
};

typedef struct Pilha
{
    No *topo;
} Pilha;
Pilha *_inicializar()
{
    Pilha *p = new Pilha{nullptr};
    return p;
}
void _empilhar(Pilha *pilha, int item)
{
    No *novo = new No{item, pilha->topo};
    pilha->topo = novo;
    return;
}
void _desempilhar(Pilha *pilha)
{
    if (pilha->topo == nullptr)
    {
        cout << "A pilha está vazia" << '\n';
        return;
    }
    else
    {
        No *no = pilha->topo;
        pilha->topo = pilha->topo->prox;
        delete no;
    }
}
void _consultarTopo(Pilha *pilha)
{
    if (pilha->topo == nullptr)
    {
        cout << "Pilha vazia" << '\n';
        return;
    }
    cout << pilha->topo->valor << '\n';
    return;
}
bool _estaVazia(Pilha *pilha)
{
    return (pilha->topo == nullptr);
}
void _liberar(Pilha *pilha)
{
    if (pilha->topo == nullptr)
        return;
    No *at = pilha->topo;
    while (at != nullptr)
    {
        No *prox = at->prox;
        delete at;
        at = prox;
    }
    pilha->topo = nullptr;
}

bool estaVazia(Fila *fila)
{
    return (fila->inicio == nullptr && fila->fim == nullptr);
}
Fila *inicializar()
{
    Fila *f = new Fila{nullptr, nullptr};
    return f;
}
void enfileirar(Fila *fila, int item)
{
    if (fila->inicio == nullptr && fila->fim == nullptr)
    {
        No *no = new No{item, nullptr};
        fila->fim = no;
        fila->inicio = no;
        return;
    }
    No *no = new No{item, nullptr};
    fila->fim->prox = no;
    fila->fim = no;
    return;
}
void desnfileirar(Fila *fila)
{
    if (fila->fim == nullptr && fila->inicio == nullptr)
    {
        cout << "Fila já está vazia";
        return;
    }
    if (fila->inicio->prox == nullptr)
    {
        delete fila->inicio;
        fila->inicio = nullptr;
        fila->fim = nullptr;
        return;
    }
    No *temp = fila->inicio;
    fila->inicio = fila->inicio->prox;
    delete temp;
}
void consultarInicio(Fila *fila)
{
    if (estaVazia(fila))
    {
        return;
    }
    cout << fila->inicio->valor << '\n';
    return;
}

void liberar(Fila *fila)
{
    if (fila->fim == nullptr && fila->inicio == nullptr)
    {
        return;
    }
    No *temp = fila->inicio;
    while (temp != nullptr)
    {
        No *at = temp->prox;
        delete temp;
        temp = at;
    }
    fila->inicio = nullptr;
    fila->fim = nullptr;
}
void mostrar(Fila *fila)
{
    if (estaVazia(fila))
    {
        return;
    }
    if (fila->inicio == nullptr && fila->fim == nullptr)
    {
        cout << "ta vazio" << '\n';
        return;
    }
    No *temp = fila->inicio;
    while (temp->prox != nullptr)
    {
        cout << temp->valor << '\n';
        temp = temp->prox;
    }
    cout << temp->valor << '\n';
}
void menu()
{
    cout << " 1 - inciaizliar " << '\n';
    cout << " 2 - enfileirar " << '\n';
    cout << " 3 - desenfileirar " << '\n';
    cout << " 4 - consutolar incio" << '\n';
    cout << " 5 - ta vazia" << '\n';
    cout << " 6 - mostrar " << '\n';
    cout << " 7 - liberar " << '\n';
}
Fila *inverterFila(Fila *fila)
{
    Pilha *p = _inicializar();
    while (!(estaVazia(fila)))
    {
        _empilhar(p, fila->inicio->valor);
        desnfileirar(fila);
    }
    while (!(_estaVazia(p)))
    {
        enfileirar(fila, p->topo->valor);
        _desempilhar(p);
    }
    mostrar(fila);
    return fila;
}
signed main()
{
    int op = -1;
    Fila *f = nullptr;
    do
    {
        menu();
        cin >> op;
        switch (op)
        {
        case 1:
            f = inicializar();
            break;
        case 2:
            int item;
            cin >> item;
            enfileirar(f, item);
            break;
        case 3:
            desnfileirar(f);
            break;
        case 4:
            consultarInicio(f);
            break;
        case 5:
            if (estaVazia(f))
                cout << "S" << '\n';
            break;
        case 6:
            mostrar(f);
            break;
        case 7:
            liberar(f);
            break;
        case -1:
            return 0;
        case 8:
            f = inverterFila(f);
            break;
        }
    } while (op != -1);
}

