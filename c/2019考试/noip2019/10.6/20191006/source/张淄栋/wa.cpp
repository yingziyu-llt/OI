#include <bits/stdc++.h>

using namespace std;
long long  a[1100000];
int main()
{
    freopen("wa.in", "r", stdin);
    freopen("wa.out", "w", stdout);
    long long  n;
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            cout << a[i] << " ";
        }
}