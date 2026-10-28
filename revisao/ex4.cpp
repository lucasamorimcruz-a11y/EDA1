#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

int *func()
{
    int n;
    cin >> n;
    int *pointer = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        cin >> pointer[i];
    }
    return pointer;
}

void dealloc(void *pointer)
{
    free(pointer);
}
signed main()
{
    int *ptr = func();
    int itr = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << ptr[i] << '\n';
    }
    dealloc(ptr);
}