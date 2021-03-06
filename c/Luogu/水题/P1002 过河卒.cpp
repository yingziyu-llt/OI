/*
题目描述
棋盘上AA点有一个过河卒，需要走到目标BB点。卒行走的规则：可以向下、或者向右。同时在棋盘上CC点有一个对方的马，该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。

棋盘用坐标表示，AA点(0, 0)(0,0)、BB点(n, m)(n,m)(nn, mm为不超过2020的整数)，同样马的位置坐标是需要给出的。

现在要求你计算出卒从AA点能够到达BB点的路径的条数，假设马的位置是固定不动的，并不是卒走一步马走一步。

输入输出格式
输入格式：
一行四个数据，分别表示BB点坐标和马的坐标。

输出格式：
一个数据，表示所有的路径条数。

输入输出样例
输入样例#1： 复制
6 6 3 3
输出样例#1： 复制
6
说明
结果可能很大！
*/

#include <stdio.h>
#include <string.h>
long long dp[30][30];
int main()
{
    int n, m, a, b;
    memset(dp, 0, sizeof(dp));
    scanf("%d%d%d%d", &n, &m, &a, &b);
    if (a >= 2 && b >= 1)
        dp[a - 2][b - 1] = -1;
    if (a >= 2)
        dp[a - 2][b + 1] = -1;
    if (a >= 1 && b >= 2)
        dp[a - 1][b - 2] = -1;
    if (a >= 1)
        dp[a - 1][b + 2] = -1;
    if (b >= 2)
        dp[a + 1][b - 2] = -1;
    dp[a + 1][b + 2] = -1;
    if (b >= 1)
        dp[a + 2][b - 1] = -1;
    dp[a + 2][b + 1] = -1;
    dp[a][b] = -1;
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {		
			if (i == 0)
            {
                if (dp[i][j] != -1)
                    dp[i][j] = 1;
                else
                    break;
                continue;
            }
            if (dp[i][j] != -1)
            {
                
                if (i - 1 >= 0 && dp[i - 1][j] != -1)
                    dp[i][j] += dp[i - 1][j];
                if (j - 1 >= 0 && dp[i][j - 1] != -1)
                    dp[i][j] += dp[i][j - 1];
            }
        }
    }
    printf("%lld", dp[n][m]);
    return 0;
}
