#include <bits/stdc++.h>
using namespace std;

struct node
{
    int item;
    node *esquerda;
    node *direita;
    int altura;
};

struct Arvore
{
    node *raiz;
};

int getAltura(node *no)
{
    if (no == nullptr)
        return -1;

    return no->altura;
}

int maxAltura(node *esquerda, node *direita)
{
    return max(getAltura(esquerda), getAltura(direita));
}

bool estaVazia(Arvore *arvore)
{
    return arvore->raiz == nullptr;
}

int fatorBalanceamento(node *no)
{
    if (no == nullptr)
        return 0;

    return getAltura(no->esquerda) - getAltura(no->direita);
}

node *criarNo(int item)
{
    return new node{item, nullptr, nullptr, 0};
}

Arvore *inicializar()
{
    return new Arvore{nullptr};
}

node *rotacaoDireita(node *y)
{
    node *x = y->esquerda;
    node *aux = x->direita;

    x->direita = y;
    y->esquerda = aux;

    y->altura = 1 + maxAltura(y->esquerda, y->direita);
    x->altura = 1 + maxAltura(x->esquerda, x->direita);

    return x;
}

node *rotacaoEsquerda(node *x)
{
    node *y = x->direita;
    node *aux = y->esquerda;

    y->esquerda = x;
    x->direita = aux;

    x->altura = 1 + maxAltura(x->esquerda, x->direita);
    y->altura = 1 + maxAltura(y->esquerda, y->direita);

    return y;
}

node *inserir(node *raiz, int item)
{
    if (raiz == nullptr)
        return criarNo(item);

    if (item < raiz->item)
        raiz->esquerda = inserir(raiz->esquerda, item);
    else if (item > raiz->item)
        raiz->direita = inserir(raiz->direita, item);
    else
        return raiz;

    raiz->altura = 1 + maxAltura(raiz->esquerda, raiz->direita);

    int fb = fatorBalanceamento(raiz);

    if (fb > 1 && item < raiz->esquerda->item)
        return rotacaoDireita(raiz);

    if (fb < -1 && item > raiz->direita->item)
        return rotacaoEsquerda(raiz);

    if (fb > 1 && item > raiz->esquerda->item)
    {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }
    if (fb < -1 && item < raiz->direita->item)
    {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

void adicionar(Arvore *arvore, int item)
{
    arvore->raiz = inserir(arvore->raiz, item);
}
node *menorValor(node *raiz)
{
    node *atual = raiz;

    while (atual->esquerda != nullptr)
        atual = atual->esquerda;

    return atual;
}

node *excluirNo(node *raiz, int item)
{
    if (raiz == nullptr)
        return nullptr;

    if (item < raiz->item)
    {
        raiz->esquerda = excluirNo(raiz->esquerda, item);
    }
    else if (item > raiz->item)
    {
        raiz->direita = excluirNo(raiz->direita, item);
    }
    else
    {
        if (raiz->esquerda == nullptr &&
            raiz->direita == nullptr)
        {
            delete raiz;
            return nullptr;
        }

        if (raiz->esquerda == nullptr ||
            raiz->direita == nullptr)
        {
            node *filho;

            if (raiz->esquerda != nullptr)
                filho = raiz->esquerda;
            else
                filho = raiz->direita;

            delete raiz;
            return filho;
        }

        node *sucessor = menorValor(raiz->direita);
        raiz->item = sucessor->item;

        raiz->direita = excluirNo(raiz->direita, sucessor->item);
    }
    raiz->altura = 1 + max(getAltura(raiz->esquerda), getAltura(raiz->direita));

    int fb = fatorBalanceamento(raiz);
    if (fb > 1)
    {
        if (fatorBalanceamento(raiz->esquerda) >= 0)
            return rotacaoDireita(raiz);

        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }
    if (fb < -1)
    {
        if (fatorBalanceamento(raiz->direita) <= 0)
            return rotacaoEsquerda(raiz);
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

node *pesquisarValor(Arvore *arvore, int item)
{
    node *atual = arvore->raiz;

    while (atual != nullptr)
    {
        if (atual->item == item)
            return atual;

        if (item < atual->item)
            atual = atual->esquerda;
        else
            atual = atual->direita;
    }

    return nullptr;
}

void excluir(Arvore *arvore, int item)
{
    if (estaVazia(arvore))
    {
        cout << "Arvore esta vazia" << '\n';
        return;
    }
    if (pesquisarValor(arvore, item) == nullptr)
    {
        cout << "Valor nao encontrado" << '\n';
        return;
    }
    arvore->raiz = excluirNo(arvore->raiz, item);
    cout << "Valor excluido com sucesso!" << '\n';
}

void imprimirEmOrdem(node *raiz)
{
    if (raiz == nullptr)
        return;

    imprimirEmOrdem(raiz->esquerda);
    cout << raiz->item << '\n';
    imprimirEmOrdem(raiz->direita);
}

void imprimirPreOrdem(node *raiz)
{
    if (raiz == nullptr)
        return;

    cout << raiz->item << '\n';
    imprimirPreOrdem(raiz->esquerda);
    imprimirPreOrdem(raiz->direita);
}

void imprimirPosOrdem(node *raiz)
{
    if (raiz == nullptr)
        return;

    imprimirPosOrdem(raiz->esquerda);
    imprimirPosOrdem(raiz->direita);
    cout << raiz->item << '\n';
}

void imprimirPorNivel(Arvore *arvore)
{
    if (estaVazia(arvore))
        return;

    queue<node *> nivel;
    nivel.push(arvore->raiz);

    while (!nivel.empty())
    {
        node *atual = nivel.front();
        nivel.pop();

        cout << atual->item << '\n';

        if (atual->esquerda != nullptr)
            nivel.push(atual->esquerda);

        if (atual->direita != nullptr)
            nivel.push(atual->direita);
    }
}

void liberarNos(node *raiz)
{
    if (raiz == nullptr)
        return;

    liberarNos(raiz->esquerda);
    liberarNos(raiz->direita);
    delete raiz;
}

void liberarArvore(Arvore *arvore)
{
    liberarNos(arvore->raiz);
    delete arvore;
}

void exibirMenu()
{
    cout << "Insira um dos números a seguir" << '\n';
    cout << "1 - Inserir item na arvore" << '\n';
    cout << "2 - Excluir item da arvore" << '\n';
    cout << "3 - Pesquisar valor" << '\n';
    cout << "4 - Imprimir em ordem" << '\n';
    cout << "5 - Imprimir em pós ordem" << '\n';
    cout << "6 - Imprimir em pré ordem" << '\n';
    cout << "7 - Imprimir em por nível" << '\n';
    cout << "0 - Encerrar o programa " << '\n';
    return;
}
int main()
{
    int escolha = -1;
    Arvore *arvore = inicializar();
    int item;
    do
    {
        exibirMenu();
        cin >> escolha;
        switch (escolha)
        {
        case 0:
            break;
        case 1:
            cout << "Qual item deve ser inserido?" << '\n';
            cin >> item;
            adicionar(arvore, item);
            break;
        case 2:
            cout << "Qual item deve ser excluido da arvore" << '\n';
            cin >> item;
            excluir(arvore, item);
            break;
        case 3:
            cout << "Qual valor deve ser procurado na arvore?" << '\n';
            cin >> item;
            if (pesquisarValor(arvore, item) != nullptr)
                cout << "Valor encontrado" << '\n';
            else
                cout << "Valor nao encontrado" << '\n';
            break;
        case 4:
            imprimirEmOrdem(arvore->raiz);
            break;
        case 5:
            imprimirPosOrdem(arvore->raiz);
            break;
        case 6:
            imprimirPreOrdem(arvore->raiz);
            break;
        case 7:
            imprimirPorNivel(arvore);
            break;
        default:
            cout << "Opção inválida" << '\n';
            break;
        }
    } while (escolha != 0);
    liberarArvore(arvore);
    cout << "Encerrando o programa" << '\n';
    return 0;
}