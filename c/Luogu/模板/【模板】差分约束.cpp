#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
#define N 110000
#define K 110000
struct edge
{
	int to, val, nxt;
} e[N * 3];
int ehead[N], ecnt, n, k;
void addadge(int form, int to, int val)
{
	ecnt++;
	e[ecnt].to = to;
	e[ecnt].val = val;
	e[ecnt].nxt = ehead[form];
	ehead[form] = ecnt;
}

queue<int> q;
int dis[N];
bool vis[N];
int num[N];
bool SPFA()
{
	memset(dis, -1, sizeof(dis));
	dis[0] = 0;
	q.push(0);
	vis[0] = true;
	num[0] = 1;
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		vis[top] = false;
		for (int i = ehead[top]; i; i = e[i].nxt)
		{
			if (dis[e[i].to] < dis[top] + e[i].val)
			{
				dis[e[i].to] = dis[top] + e[i].val;
				if (!vis[e[i].to])
				{
					++num[e[i].to];
					if (num[e[i].to] >= n)
						return 0;
					q.push(e[i].to);
					vis[e[i].to] = 1;
				}
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++)
	{
		int x, y, k;
		scanf("%d%d%d", &k, &x, &y);
		if (k == 1)
			addadge(x, y, 0), addadge(y, x, 0);
		else if (k == 2)
		{
			if (x == y)
			{
				printf("-1");
				return 0;
			}
			addadge(x, y, 1);
		}
		else if (k == 3)
			addadge(y, x, 0);
		else if (k == 4)
		{
			if (x == y)
			{
				printf("-1");
				return 0;
			}
			addadge(y, x, 1);
		}
		else
			addadge(x, y, 0);
	}
	for(int i = n;i > 0;i--)
		addadge(0,i,1);
	if (!SPFA())
		printf("-1");
	else
	{
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			ans += dis[i];
		printf("%lld", ans);
	}
	return 0;
}
/*背景:
题目描述
幼儿园里有N个小朋友，lxhgww老师现在想要给这些小朋友们分配糖果，要求每个小朋友都要分到糖果。但是小朋友们也有嫉妒心，总是会提出一些要求，比如小明不希望小红分到的糖果比他的多，于是在分配糖果的时候，lxhgww需要满足小朋友们的K个要求。幼儿园的糖果总是有限的，lxhgww想知道他至少需要准备多少个糖果，才能使得每个小朋友都能够分到糖果，并且满足小朋友们所有的要求。

输入输出格式
输入格式：
输入的第一行是两个整数N，K。接下来K行，表示这些点需要满足的关系，每行3个数字，X，A，B。如果X=1， 表示第A个小朋友分到的糖果必须和第B个小朋友分到的糖果一样多；如果X=2， 表示第A个小朋友分到的糖果必须少于第B个小朋友分到的糖果；如果X=3， 表示第A个小朋友分到的糖果必须不少于第B个小朋友分到的糖果；如果X=4， 表示第A个小朋友分到的糖果必须多于第B个小朋友分到的糖果；如果X=5， 表示第A个小朋友分到的糖果必须不多于第B个小朋友分到的糖果；

输出格式：
输出一行，表示lxhgww老师至少需要准备的糖果数，如果不能满足小朋友们的所有要求，就输出-1。*/