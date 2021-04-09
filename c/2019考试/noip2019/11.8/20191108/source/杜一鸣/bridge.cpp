#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define N 55
#define M 5005
using namespace std;
char s[N];
int dis[N][N];
int maxn, n, t, d;
template <typename T>
inline void read(T &res)
{
    res = 0;
    T pd = 1;
    char aa = getchar();
    while (aa < '0' || aa > '9')
    {
        if (aa == '-')
        {
            pd = -pd;
        }
        aa = getchar();
    }
    while (aa >= '0' && aa <= '9')
    {
        res = (res << 1) + (res << 3) + (aa - '0');
        aa = getchar();
    }
    res *= pd;
    return;
}
int main()
{
    freopen("bridge.in","r",stdin);
    freopen("bridge.out","w",stdout);
    read(t);
    while (t--)
    {
        maxn = 0;
        memset(dis, 0x3f, sizeof(dis));
        read(n);
        read(d);
        for (int i = 1; i <= n; i++)
        {
            dis[i][i] = 0;
            scanf("%s", s);
            for (int j = i + 1; j <= n; ++j)
            {
                if (s[j - 1] == 'Y')
                {
                    dis[i][j] = dis[j][i] = 1;
                }
            }
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    dis[j][i] = dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                maxn = max(maxn, dis[i][j]);
            }
        }
        if (maxn == 0x3f3f3f3f)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", maxn * d);
        }
    }
    return 0;
}