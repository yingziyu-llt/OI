#include <cstdio>
#include <cmath>
using namespace std;
long long N, n = 1e9, x;
int main()
{
    freopen("box.in","r",stdin);
    freopen("box.out","w",stdout);
    scanf("%lld", &N);
    for (int i = 1; i <= sqrt(N); i++)
    {
        for (int j = i; j <= sqrt(N / i); j++)
        {
            if (!(N % i) && !(N % j) && !(N % (N / i / j)))
            {
                x = 2 * (i * j + i * (N / i / j) + j * (N / i / j));
                if (x < n) n = x;    
            }
        }
    }

    printf("%lld", n);
    return 0;
}