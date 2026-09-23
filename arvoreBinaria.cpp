#include <bits/stdc++.h>
using namespace std;
typedef struct Arv
{
    int item;
    Arv *esquerda;
    Arv *direita;
} Arvore;
Arvore *arvore(int itemDaRaiz);
void inserirItem(Arvore *&_arvore, int item);
void removerItem(Arvore *&_arvore, int item);
void exibirArvore(Arvore *&_arvore);
void encontrarItem(Arvore *&_arvore, int item);
void mostrarArvoreEmOrdem(Arvore *&_arvore);
void mostrarArvorePreOrdem(Arvore *&_arvore);
void mostrarArvorePosOrdem(Arvore *&_arvore);
void mostrarArvoreBFS(Arvore *&_arvore);
void mostrarArvoreDFS(Arvore *&_arvore);
void exibirMenu(Arvore *&_arvore);
int main()
{
    cout << "Seja muito bem vindo!" << endl;
    int escolha = -1;
    Arvore *_arvore = arvore();
    do
    {
        exibirMenu();
        cin >> escolha;
        switch (escolha)
        {
        case 1:
            int valor;
            cout << "Qual valor deve ser inseriodo?" << '\n';
            cin >> valor;
            inserirItem(_arvore, valor);
            break;
        case 2:
            int valor;
            cout << "Qual valor deve ser removido?" << '\n';
            cin >> valor;
            removerItem(_arvore, valor);
            break;
        case 3:
            exibirArvore(_arvore);
            break;
        case 4:
            int valor;
            cout << "Qual valor deve ser encontrado?" << '\n';
            cin >> valor;
            encontrarItem(_arvore, valor);
            break;
        case 5:
            mostrarArvoreEmOrdem(_arvore);
            break;
        case 6:
            mostrarArvorePreOrdem(_arvore);
            break;
        case 7:
            mostrarArvorePosOrdem(_arvore);
            break;
        case 8:
            mostrarArvoreBFS(_arvore);
            break;
        case 9:
            mostrarArvoreDFS(_arvore);
            break;
        case 0:
            liberarArvore(_arvore);
            cout << "Encerrando programa..." << '\n';
        }
    } while (escolha != 0);
    cout << "Encerrando...";
    return 0;
}
Arvore *arvore()
{
    Arvore *arvore = new Arvore;
    arvore->item = NULL;
    arvore->esquerda = nullptr;
    arvore->direita = nullptr;
    return arvore;
}
void inserirItem(Arvore *&_arvore, int item)
{
    // busca feita utilizando o metódo BFS para procurar árvores (ou melhor, nodos) que estão sem o filho direito ou esquerdo, assim mantendo a estrutura a mais enxuta possível.
    if (_arvore == nullptr)
    {
        _arvore = arvore(item);
    }
    queue<Arvore *> filaDeBusca;
    filaDeBusca.push(_arvore);
    while (!filaDeBusca.empty())
    {
        Arvore *_arvoreAtual = filaDeBusca.front();
        filaDeBusca.pop();
        if (_arvore->esquerda == nullptr)
        {
            Arvore *_novaArvore = arvore(item);
            _arvore->esquerda = _novaArvore;
            return;
        }
        else
        {
            filaDeBusca.push(_arvore->esquerda);
        }
        if (_arvore->direita == nullptr)
        {
            Arvore *_novaArvore = arvore(item);
            _arvore->direita = _novaArvore;
            return;
        }
        else
        {
            filaDeBusca.push(_arvore->direita);
        }
    }
}
void removerItem(Arvore *&_arvore, int item)
{
    // busca feita utilizando o metódo BFS para procurar o item a ser excluido.
    if (_arvore == nullptr)
    {
        cout << "A arvore está vazia." << '\n';
    }
    queue<Arvore *> filaDeBusca;
    // e se apagar a root?
    if (_arvore->item == item)
    {
        // caso em que árvore é a folha
        if (_arvore->direita == nullptr && _arvore->esquerda == nullptr)
        {
            delete _arvore;
            cout << "Item apagado." << '\n';
            return;
        }
        else if (_arvore->direita && _arvore->esquerda == nullptr)
        {
            Arvore *aux = _arvore;
            _arvore = _arvore->direita;
            delete aux;
            return;
        }
        else if (_arvore->esquerda && _arvore->direita == nullptr)
        {
            Arvore *aux = _arvore;
            _arvore = _arvore->esquerda;
            delete aux;
            return;
        }
        // caso em que tem ambos os lados
        else
        {
            // arrumar este else
            Arvore *removidoPai = _arvore;
            Arvore *removido = _arvore->direita;
            while (removido->esquerda != nullptr)
            {
                removidoPai = removido;
                removido = removido->esquerda;
            }
            _arvore->item = removido->item;
            removidoPai->esquerda = nullptr;

            delete removido;
            return;
        }
    }
    filaDeBusca.push(_arvore);
    while (!filaDeBusca.empty())
    {
        Arvore *aux = filaDeBusca.front();
        if (aux->item == item)
        {
        }
    }
}
void exibirArvore(Arvore *&_arvore)
{
}
void encontrarItem(Arvore *&_arvore, int item)
{
}
void mostrarArvoreEmOrdem(Arvore *&_arvore)
{
}
void mostrarArvorePreOrdem(Arvore *&_arvore)
{
}
void motrarArvorePosOrdem(Arvore *&_arvore)
{
}
void mostrarArvoreBFS(Arvore *&_arvore)
{
}
void mostrarArvoreDFS(Arvore *&_arvore)
{
}
void liberarArvore(Arvore *&_arvore)
{
}
void exibirMenu()
{
    cout << "1 - Inserir Item na Arvore" << '\n';
    cout << "2 - Remover Item da Arvore" << '\n';
    cout << "3 - Exibir Arvore inteira" << '\n';
    cout << "4 - Encontrar Item na Arvore" << '\n';
    cout << "5 - Mostrar Arvore em Ordem" << '\n';
    cout << "6 - Mostrar Arvore em Pre-Ordem" << '\n';
    cout << "7 - Mostrar Arvore em Pos-Ordem" << '\n';
    cout << "8 - Mostrar Arvore utilizando DFS" << '\n';
    cout << "9 - Mostrar Arvore utilizando BFS" << '\n';
    cout << "0 - Encerrar programa" << '\n';
}