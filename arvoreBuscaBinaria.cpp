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
void mostrarTodosElementos(Arvore *&_arvore);
void mostrarArvoreEmOrdem(Arvore *&_arvore);
void mostrarArvorePreOrdem(Arvore *&_arvore);
void mostrarArvorePosOrdem(Arvore *&_arvore);
void exibirMenu();
void limpaTela();
void liberarArvore(Arvore *&_arvore);

int main()
{
    cout << "Seja muito bem vindo!" << endl;

    int escolha = -1;
    int valor;

    cout << "Qual deve ser o valor da raiz da arvore?" << '\n';
    cin >> valor;

    Arvore *_arvore = arvore(valor);

    do
    {
        exibirMenu();
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            cout << "Qual valor deve ser inserido?" << '\n';
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
            mostrarTodosElementos(_arvore);
            limpaTela();
            break;

        case 5:
            mostrarArvoreEmOrdem(_arvore);
            limpaTela();
            break;

        case 6:
            mostrarArvorePreOrdem(_arvore);
            limpaTela();
            break;

        case 7:
            mostrarArvorePosOrdem(_arvore);
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
    if (_arvore == nullptr)
    {
        _arvore = arvore(item);
        return;
    }

    if (item < _arvore->item)
    {
        inserirItem(_arvore->esquerda, item);
    }
    else if (item > _arvore->item)
    {
        inserirItem(_arvore->direita, item);
    }
    else
    {
        cout << "Item ja existe na arvore." << '\n';
    }
}

void removerItem(Arvore *&_arvore, int item)
{
    if (_arvore == nullptr)
    {
        cout << "Item nao encontrado." << '\n';
        return;
    }

    if (item < _arvore->item)
    {
        removerItem(_arvore->esquerda, item);
    }
    else if (item > _arvore->item)
    {
        removerItem(_arvore->direita, item);
    }
    else
    {
        if (_arvore->esquerda == nullptr && _arvore->direita == nullptr)
        {
            delete _arvore;
            _arvore = nullptr;
        }
        else if (_arvore->esquerda == nullptr)
        {
            Arvore *aux = _arvore;
            _arvore = _arvore->direita;
            delete aux;
        }
        else if (_arvore->direita == nullptr)
        {
            Arvore *aux = _arvore;
            _arvore = _arvore->esquerda;
            delete aux;
        }
        else
        {
            Arvore *aux = _arvore->direita;

            while (aux->esquerda != nullptr)
            {
                aux = aux->esquerda;
            }

            _arvore->item = aux->item;

            removerItem(_arvore->direita, aux->item);
        }

        cout << "Item removido." << '\n';
    }
}

void encontrarItem(Arvore *&_arvore, int item)
{
    if (_arvore == nullptr)
    {
        cout << "Item nao encontrado." << '\n';
        return;
    }

    if (_arvore->item == item)
    {
        cout << "Item encontrado." << '\n';
        return;
    }

    if (item < _arvore->item)
    {
        encontrarItem(_arvore->esquerda, item);
    }
    else
    {
        encontrarItem(_arvore->direita, item);
    }
}

void mostrarTodosElementos(Arvore *&_arvore)
{
    if (arvoreVazia(_arvore))
    {
        cout << "A arvore esta vazia." << '\n';
        return;
    }

    mostrarArvoreEmOrdem(_arvore);
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

void liberarArvore(Arvore *&_arvore)
{
    if (arvoreVazia(_arvore))
    {
        return;
    }

    liberarArvore(_arvore->esquerda);
    liberarArvore(_arvore->direita);

    delete _arvore;
    _arvore = nullptr;
}

void limpaTela()
{
    fputs("\x1b[1;1H\x1b[2J", stdout);
    fflush(stdout);
}

void exibirMenu()
{
    cout << "1 - Inserir Item na Arvore" << '\n';
    cout << "2 - Remover Item da Arvore" << '\n';
    cout << "3 - Pesquisar Item na Arvore" << '\n';
    cout << "4 - Mostrar Todos os Elementos" << '\n';
    cout << "5 - Mostrar Arvore em Ordem" << '\n';
    cout << "6 - Mostrar Arvore em Pre-Ordem" << '\n';
    cout << "7 - Mostrar Arvore em Pos-Ordem" << '\n';
    cout << "0 - Encerrar programa" << '\n';
}

