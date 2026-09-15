#include <bits/stdc++.h>
using namespace std;

typedef struct Documento 
{
    string nomeArquivo;
    struct Documento *next;
} Documento;
typedef struct Fila {
    size_t tamanhoDaFila;
    struct Documento *primeiroDocumento;
} Fila;
Fila *_Fila (){
    Fila *_fila = (Fila *)malloc(sizeof(_fila));
    _fila->tamanhoDaFila = 0;
    _fila->primeiroDocumento = nullptr;
    return _fila;
}
bool filaVazia (Fila *fila){
    if (fila->primeiroDocumento == nullptr){
        return true;
    }
    return false;
}
void inserirDocumento (Fila *fila, string _nomeArquivo){
    if (filaVazia(fila)){
        Documento *novoDocumento = (Documento *)malloc(sizeof(Documento));
        novoDocumento->nomeArquivo = _nomeArquivo;
        novoDocumento->next = nullptr;
        fila->primeiroDocumento = novoDocumento;
    }
    else{
        Documento *novoDocumento = (Documento *)malloc(sizeof(Documento));
        novoDocumento->nomeArquivo = _nomeArquivo;
        Documento *aux = fila->primeiroDocumento;
        while (aux->next != nullptr || aux != nullptr){
            aux = aux->next;
        }
        aux->next = novoDocumento;
        novoDocumento->next = nullptr;
    }
    fila->tamanhoDaFila++;
    return;
}
void mostrarUltimoDocumento (Fila *fila)
{
    if (filaVazia(fila)){
        cout << "Fila esta vazia" << '\n';
        return;
    }
    Documento *aux = (Documento *) malloc (sizeof(aux));
    aux = fila->primeiroDocumento;
    while (aux !=nullptr ){
        aux = aux->next;
    }
    cout << aux->nomeArquivo << '\n';
    return;
}
void mostrarProximoDocumento (Fila *fila){
    if (filaVazia(fila)){
        cout << "Fila esta vazia" << '\n';
        return;
    }
    Documento *aux = (Documento *) malloc(sizeof(aux));
    aux = fila->primeiroDocumento;
    if (aux == nullptr) return;
    if (aux != nullptr){
        cout << aux->next->nomeArquivo << '\n';
    }
}
void mostrarFilaInteira (Fila *fila){
    if (filaVazia(fila)){
        cout << "Fila esta vazia" << '\n';
        return;
    }
    Documento *aux = (Documento *) malloc(sizeof(aux));
    aux = fila->primeiroDocumento;
    if (aux == nullptr) return;
    while (aux->next != nullptr || aux != nullptr){
        cout << aux->nomeArquivo << '\n';
    }
    
    return;
}
void mostrarTamanhoFila (Fila *fila){
    cout << "O tamanho da fila é de: " << fila->tamanhoDaFila << " itens!" << '\n';
    return;
}

int main(){
    cout << "Seja bem-vindo, escolha o que deseja fazer!" << '\n';
    Fila *fila = _Fila ();
    char input;
    do {
        cout << "(a) inserir um documento em impressao ( ex. 'receita.txt'" << '\n';
        cout << "(b) mostrar ultimo documento" << '\n';
        cout << "(c) mostra proximo documento para impressao" << '\n';
        cout << "(d) mostra documentos pendentes na fila de impressao" << '\n';
        cout << "(e) mostrar tamanho da fila" << '\n';
        cout << "(f) sair do programa" << '\n';
        cin >> input;
        if (input == 'a'){
            string nomeArquivo;
            cout << "Qual o nome do arquivo que deseja inserir na fila?" << '\n';
            cin >> nomeArquivo;
            inserirDocumento (fila, nomeArquivo);
        }
        if (input == 'b'){
            mostrarUltimoDocumento(fila);
        }
        if (input == 'c'){
            mostrarProximoDocumento(fila);
        }
        if (input == 'd'){
            mostrarFilaInteira(fila);
        }
        if (input == 'e'){
            mostrarTamanhoFila(fila);
        }
    } while (input != 'f');
    free (fila);
    cout << "Encerrando..." << '\n';
    return 0;
}