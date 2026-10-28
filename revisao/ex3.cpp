#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int a = 10;
    int b = 20;
    cout << a << " & " << b << '\n';

    trocar(&a, &b);
    cout << a << " & " << b << '\n';
}