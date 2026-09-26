#include <bits/stdc++.h>
using namespace std;
typedef struct Arv
{
    int item;
    Arv *esquerda;
    Arv *direita;
} Arvore;
Arvore *arvore(int itemDaRaiz);
bool arvoreVazia(Arvore *&_arvore);
void inserirItem(Arvore *&_arvore, int item);
void removerItem(Arvore *&_arvore, int item);
void encontrarItem(Arvore *&_arvore, int item);
void mostrarArvoreEmOrdem(Arvore *&_arvore);
void mostrarArvorePreOrdem(Arvore *&_arvore);
void mostrarArvorePosOrdem(Arvore *&_arvore);
void mostrarArvoreBFS(Arvore *&_arvore);
void mostrarArvoreDFS(Arvore *&_arvore);
void exibirMenu();
void limpaTela()
{
    fputs("\x1b[1;1H\x1b[2J", stdout);
    fflush(stdout);
}
void liberarArvore(Arvore *&arvore);
int main()
{
    cout << "Seja muito bem vindo!" << endl;
    int escolha = -1;
    int valor;
    cout << "Qual deve ser o valor da raiz da árvore?" << '\n';
    cin >> valor;
    Arvore *_arvore = arvore(valor);
    do
    {
        exibirMenu();
        cin >> escolha;
        switch (escolha)
        {
        case 1:
            cout << "Qual valor deve ser inseriodo?" << '\n';
            cin >> valor;
            inserirItem(_arvore, valor);
            limpaTela();
            break;
        case 2:
            cout << "Qual valor deve ser removido?" << '\n';
            cin >> valor;
            removerItem(_arvore, valor);
            limpaTela();
            break;
        case 3:
            cout << "Qual valor deve ser encontrado?" << '\n';
            cin >> valor;
            encontrarItem(_arvore, valor);
            limpaTela();
            break;
        case 4:
            mostrarArvoreEmOrdem(_arvore);
            limpaTela();
            break;
        case 5:
            mostrarArvorePreOrdem(_arvore);
            limpaTela();
            break;
        case 6:
            mostrarArvorePosOrdem(_arvore);
            limpaTela();
            break;
        case 7:
            mostrarArvoreBFS(_arvore);
            limpaTela();
            break;
        case 8:
            mostrarArvoreDFS(_arvore);
            limpaTela();
            break;
        case 0:
            liberarArvore(_arvore);
            cout << "Encerrando programa..." << '\n';
            return 0;
        }
    } while (escolha != 0);
    cout << "Encerrando...";
    return 0;
}
Arvore *arvore(int item)
{
    Arvore *arvore = new Arvore;
    arvore->item = item;
    arvore->esquerda = nullptr;
    arvore->direita = nullptr;
    return arvore;
}
bool arvoreVazia(Arvore *&_arvore)
{
    return _arvore == nullptr;
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
        if (_arvoreAtual->esquerda == nullptr)
        {
            Arvore *_novaArvore = arvore(item);
            _arvoreAtual->esquerda = _novaArvore;
            return;
        }
        else
        {
            filaDeBusca.push(_arvoreAtual->esquerda);
        }
        if (_arvoreAtual->direita == nullptr)
        {
            Arvore *_novaArvore = arvore(item);
            _arvoreAtual->direita = _novaArvore;
            return;
        }
        else
        {
            filaDeBusca.push(_arvoreAtual->direita);
        }
        delete _arvoreAtual;
    }
}
void removerItem(Arvore *&_arvore, int item)
{
    // busca feita utilizando o metódo BFS para procurar o item a ser excluido.
    if (arvoreVazia(_arvore))
    {
        return;
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
            Arvore *cima = _arvore;
            Arvore *curr = _arvore->direita;
            while (curr->esquerda != nullptr)
            {
                cima = curr;
                curr = curr->esquerda;
            }
            _arvore->item = curr->item;
            if (cima == _arvore)
            {
                _arvore->direita = curr->direita;
            }
            else if (curr->direita)
            {
                cima->esquerda = curr->direita;
            }
            else
            {
                cima->esquerda = nullptr;
            }
            delete curr;
        }
    }
    filaDeBusca.push(_arvore);
    while (!filaDeBusca.empty())
    {
        Arvore *_arvoreAtual = filaDeBusca.front();
        if (_arvoreAtual->direita->item == item)
        {
            _arvoreAtual->direita = _arvoreAtual->direita->direita;
        }
        else if (_arvoreAtual->esquerda->item == item)
        {
        }
    }
}

void encontrarItem(Arvore *&_arvore, int item)
{
    if (arvoreVazia(_arvore))
    {
        return;
    }
    Arvore *_arvoreAtual = _arvore;
    queue<Arvore *> filaDeBusca;
    filaDeBusca.push(_arvoreAtual);
    int level = 0;
    while (!filaDeBusca.empty())
    {
        _arvoreAtual = filaDeBusca.front();
        filaDeBusca.pop();
        if (_arvoreAtual->item == item)
        {
        }
    }
}
void mostrarArvoreEmOrdem(Arvore *&_arvore)
{
    if (arvoreVazia(_arvore))
    {
        return;
    }
    mostrarArvoreEmOrdem(_arvore->esquerda);
    cout << _arvore->item << '\n';
    mostrarArvoreEmOrdem(_arvore->direita);
}
void mostrarArvorePreOrdem(Arvore *&_arvore)
{
    if (arvoreVazia(_arvore))
    {
        return;
    }
    cout << _arvore->item << '\n';
    mostrarArvorePreOrdem(_arvore->esquerda);
    mostrarArvorePreOrdem(_arvore->direita);
}
void mostrarArvorePosOrdem(Arvore *&_arvore)
{
    if (arvoreVazia(_arvore))
    {
        return;
    }
    mostrarArvorePosOrdem(_arvore->esquerda);
    mostrarArvorePosOrdem(_arvore->direita);
    cout << _arvore->item << '\n';
}
void mostrarArvoreBFS(Arvore *&_arvore)
{
    if (arvoreVazia(_arvore))
    {
        return;
    }
    queue<Arvore *> filaDeBusca;
    filaDeBusca.push(_arvore);
    while (!filaDeBusca.empty())
    {
        Arvore *_arvoreAtual = filaDeBusca.front();
        filaDeBusca.pop();
        if (_arvoreAtual->esquerda)
        {
            filaDeBusca.push(_arvoreAtual->esquerda);
        }
        if (_arvoreAtual->direita)
        {
            filaDeBusca.push(_arvoreAtual->direita);
        }
        cout << _arvoreAtual->item << '\n';
    }
}
void mostrarArvoreDFS(Arvore *&_arvore)
{
    mostrarArvoreEmOrdem(_arvore);
}
void liberarArvore(Arvore *&_arvore)
{
    if (arvoreVazia(_arvore))
    {
        return;
    }
    liberarArvore(_arvore->esquerda); // deleta tudo da esquerda
    liberarArvore(_arvore->direita);  // tudo da direita
    delete _arvore;                   // raiz
    _arvore = nullptr;
}

void exibirMenu()
{
    cout << "1 - Inserir Item na Arvore" << '\n';
    cout << "2 - Remover Item da Arvore" << '\n';
    cout << "3 - Encontrar Item na Arvore" << '\n';
    cout << "4 - Mostrar Arvore em Ordem" << '\n';
    cout << "5 - Mostrar Arvore em Pre-Ordem" << '\n';
    cout << "6 - Mostrar Arvore em Pos-Ordem" << '\n';
    cout << "7 - Mostrar Arvore utilizando DFS" << '\n';
    cout << "8 - Mostrar Arvore utilizando BFS" << '\n';
    cout << "0 - Encerrar programa" << '\n';
}
