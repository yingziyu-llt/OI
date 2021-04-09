#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1010][1010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        for(int j = 0;j <= i;j++)
            scanf("%d",&a[i][j]);
    for(int i = n - 1;i >= 0;i--)
    {
        for(int j = 0;j <= i;j++)
        {
            a[i][j] = max(a[i + 1][j],a[i + 1][j + 1]) + a[i][j];
        }
    }
    printf("%d",a[0][0]);

    return 0;
}