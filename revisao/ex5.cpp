#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

void func (int *ptr){
    *ptr *= 2;
    return;
}


signed main() {
    int x;
    cin >> x;
    func (&x);
    cout << x << '\n';

}

// int *p é um ponteiro que aponta para algo, e &x é a localização na memória de uma var
