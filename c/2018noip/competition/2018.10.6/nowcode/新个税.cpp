#include <stdio.h>
#include <math.h>
using namespace std;
float f[] = {0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45};
int main()
{
    float n, x;
    float ans;
    scanf("%f", &n);
    x = n;
    if (n < 5000)
    {
        printf("%.0f", n);
        return 0;
    }
    n -= 5000;
    if (n > 0)

        if (n >= 3000.0)
            ans += 3000.0 * f[0], n -= 3000;
        else
            ans += n * f[0], n = 0;

    if (n > 0)

        if (n >= 9000)
            ans += 9000.0 * f[1], n -= 9000;
        else
            ans += n * f[1], n = 0;

    if (n > 0)
        if (n >= 13000)
            ans += 13000.0 * f[2], n -= 13000;
        else
            ans += n * f[2], n = 0;

    if (n > 0)
        if(n >= 10000)
            ans += 10000.0 * f[3],n -= 10000;
        else
            ans += n * f[3],n = 0;
    
    if(n > 0)
        if(n >= 20000)
            ans += 20000.0 * f[4],n -= 20000;
        else
            ans += n * f[4],n = 0;
    
    if(n > 0)
        if(n >= 25000)
            ans += 25000.0 * f[5],n -= 25000;
        else
            ans += n * f[5],n = 0;

    if(n > 0)
        ans += n * f[6];
    x -= ans;
    printf("%.0f",x);
    return 0;
}