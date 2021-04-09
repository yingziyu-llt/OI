#include <stdio.h>
#include <queue>
using namespace std;
int way[1000];
int dp[1000];
struct node
{
	int step, floora;
} no;
queue<node> q;
int main()
{
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++)
		scanf("%d", &way[i]);
	for (int i = 1; i <= n; i++)
		dp[i] = 2147483647;
	dp[a] = 0;
	no.floora = a;
	no.step = 0;
	q.push(no);
	while (!q.empty())
	{
		int floora = q.front().floora;
		int step = q.front().step;
		if (floora + way[floora] <= n && dp[floora + way[floora]] > step + 1)
		{
			no.floora = floora + way[floora];
			no.step = step + 1;
			dp[floora + way[floora]] = step + 1;
			q.push(no);
		}
		if (floora - way[floora] > 0 && dp[floora - way[floora]] > step + 1)
		{
			no.floora = floora - way[floora];
			no.step = step + 1;
			dp[floora - way[floora]] = step + 1;
			q.push(no);
		}
		q.pop();
	}
	printf("%d", dp[b] == 0x7fffffff ? -1 : dp[b]);
	return 0;
}
