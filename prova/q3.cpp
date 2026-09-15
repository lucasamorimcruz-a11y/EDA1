#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    char s;
    struct Node *next;
} Node;
typedef struct Pilha{
    struct Node *top;
} Pilha;
Pilha *_Pilha(){
    Pilha *_pilha = (Pilha *) malloc(sizeof(_pilha));
    _pilha->top = nullptr;
    return _pilha;
}
void empilha (Pilha *_pilha, char numero1, char operador, char numero2){
    Node *_nodeNumero1 = (Node *)malloc(sizeof(_nodeNumero1));
    _nodeNumero1->s = numero1;
    Node *_nodeOperador = (Node *)malloc(sizeof(_nodeOperador));
    _nodeOperador->s = operador;
    Node *_nodeNumero2 = (Node *) malloc (sizeof(_nodeNumero2));
    _nodeNumero2->s = numero2;
    _nodeNumero1->next = _nodeOperador;
    _nodeOperador->next = _nodeNumero2;
    _nodeNumero2->next = nullptr;
    _pilha->top->next = _nodeNumero1;
    _pilha->top = _nodeNumero2;
}
void mostrarItens (Pilha *_pilha){
    Node *aux = (Node *) malloc(sizeof(aux));
    aux = _pilha->top;
    while (aux != nullptr || aux->next != nullptr){
        cout << aux->s << '\n';
        aux = aux->next;
    } 
    return;
}
int main()
{
    cout << " ---- Questao 3 ----" << '\n';
    Pilha *_pilha  = _Pilha();
    char numero1, numero2, operador;
    while (true){
        cout << "Escolha o primeiro numero, o operador, e o segundo numero" << '\n';
        cin >> numero1 >> operador >> numero2;
        if (operador == '='){
            mostrarItens (_pilha);
            return 0;
        }
        if (operador == '/' && numero2 == 0){
            continue;
        }
        else{
            empilha (_pilha, numero1, operador, numero2);
        }
    }
}
