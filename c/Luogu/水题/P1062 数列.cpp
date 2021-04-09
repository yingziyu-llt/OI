#include <stdio.h>
#include <string.h>
#include <math.h>
int x[40];

int main()
{
    int n, jz,k,ws = 0;
    long long ans;
    scanf("%d%d", &jz, &k);
    ans = 0;
    memset(x, 0, sizeof(x));
    while (k != 0)
    {
        x[ws] = k % 2;
        k /= 2;
        ws++;
    }
    for (int i = ws; i >= 0; i--)
    {
        ans = ans * jz + x[i];
    }
    printf("%lld", ans);
    return 0;
}
