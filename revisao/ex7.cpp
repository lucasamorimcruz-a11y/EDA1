#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

typedef struct No
{
    int valor;
    struct No *prox;
} No;
typedef struct Pilha
{
    No *topo;
} Pilha;
Pilha *inicializar()
{
    Pilha *p = new Pilha{nullptr};
    return p;
}
void empilhar(Pilha *pilha, int item)
{
    No *novo = new No{item, pilha->topo};
    pilha->topo = novo;
    return;
}
void desempilhar(Pilha *pilha)
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
void consultarTopo(Pilha *pilha)
{
    if (pilha->topo == nullptr)
    {
        cout << "Pilha vazia" << '\n';
        return;
    }
    cout << pilha->topo->valor << '\n';
    return;
}
bool estaVazia(Pilha *pilha)
{
    return (pilha->topo == nullptr);
}
void liberar(Pilha *pilha)
{
    if (pilha->topo == nullptr) return;
    No *at = pilha->topo;
    while (at != nullptr){
        No *prox = at->prox;
        delete at;
        at = prox;
    }
    pilha->topo = nullptr;
}
void printarMenu()
{
    cout << " 1 - inicializar " << '\n';
    cout << " 2 - empilhar " << '\n';
    cout << " 3 - desempilhar " << '\n';
    cout << " 4 - consultar topo " << '\n';
    cout << " 5 - esta vazia " << '\n';
    cout << " 6 - liberar " << '\n';
}
signed main()
{
    int op = -1;
    Pilha *p;
    do
    {
        printarMenu();
        cin >> op;
        switch (op)
        {
        case 1:
            p = inicializar();
            break;
        case 2:
            int item;
            cin >> item;
            empilhar(p, item);
            break;
        case 3:
            desempilhar(p);
            break;
        case 4:
            consultarTopo(p);
            break;
        case 5:
            if (estaVazia(p))
                cout << "Sim" << '\n';
            break;
        case 6:
            liberar(p);
            cout << "liberado" << '\n';
            break;
        default:
            break;
        }
    } while (op != -1);
}
