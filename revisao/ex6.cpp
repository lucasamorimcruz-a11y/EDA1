#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

typedef struct No{
    int valor;
    struct No *prox;
} No;

void func (int valor){
    No *no = new No;
    no->valor = valor;
    no->prox = nullptr;
    No *no1 = new No;
    no1->valor = valor * 2;
    no1->prox = nullptr;
    no->prox = no1;
    No *temp = no;
    cout << temp->valor << '\n';
    temp = temp->prox;
    cout << temp->valor << '\n';
    delete no;
    delete no1;
    
}
signed main() {
    int valor; cin >> valor;
    func (valor);
}