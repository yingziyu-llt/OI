#include <stdio.h>
int a[1000];
int main()
{
    int n;
    int tot = 0;
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        tot += a[i];
    }
    int ave = tot / n;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != ave)
        {
            a[i + 1] += a[i] - ave;
            ans++;
        }
    }
        printf("%d", ans);
        return 0;
}