#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
long long work(long long a, long long b, long long c)
{
    long long t = 1;
    while (b)
    {
        if (b % 2 != 0)
        {
            t = (a * t) % c;
            b--;
        }
        a = (a * a) % c;
        b /= 2;
    }
    return t;
}
int main()
{
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
    long long n;
    scanf("%d", &n);
    long long x = work(3, n + 1, N);
    if ((x - 1) % 2 != 0)
    {
        x = x + N;
    }
    x = (x - 1) / 2;
    printf("%d\n", x);
}