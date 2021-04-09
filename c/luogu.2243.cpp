#include <cstdio>
#include <cstring>
using namespace std;

int T, Min;
int r, c;
char a[510][510];

int dx[4] = {+1, 0, +1, 0};
int dy[4] = {+1, 0, 0, +1};
int ddx[4] = {+1, -1, +1, -1};
int ddy[4] = {+1, -1, -1, +1};
char dd[4] = {'\\', '\\', '/', '/'};
// 增量 枚举 从一个点的到另外四个方向的可能
bool flag;
struct que
{
	int x, y, dx, dy;
	int cnt;
} q[1100000], p[1100000];
// q 1 符合预期 更接近 更优秀 更先搜索
// p 0 不能无成本到达 相对较远 故此放在最后搜索
int head, tail, p_head, p_tail;
int dis[610][610];

// init 预处理
inline void init()
{
	flag = false;
	Min = 0x7fffffff;
	memset(dis, 0x3f, sizeof(dis));
}

inline que gettop()
{
	// 优先取前一部分
	if (p_tail > 0)
		return p[p_tail--];
	// 前一部分没有取后一部分
	else if (head <= tail)
		return q[head++];
}

inline void bfs()
{
	head = tail = p_head = p_tail = 0;
	que ne;
	ne.dx = ne.dy = ne.cnt = ne.dx = ne.dy = 0;
	q[head] = ne;
	dis[0][0] = 0;
	while (head <= tail || p_tail > 0)
	{
		que top = gettop();
		for (int i = 0; i < 4; i++)
		{
			ne.x = top.dx + dx[i];
			ne.y = top.dy + dy[i];
			ne.dx = top.dx + ddx[i];
			ne.dy = top.dy + ddy[i];

			if (ne.dx >= 0 && ne.dy >= 0 && ne.dx <= r && ne.dy <= c && ne.x >= 1 && ne.y >= 1 && ne.x <= r && ne.y <= c)
			{
				// 边界判断
				if (a[ne.x][ne.y] == dd[i])
					ne.cnt = top.cnt;
				else
					ne.cnt = top.cnt + 1;
				// 如果符合预期（即可以靠原有电路链接到枚举到的节点）cnt 继承，否则 cnt + 1（即变化一次）
				if (ne.cnt < dis[ne.dx][ne.dy])
				{
					// 类似 spfa 更短则更新
					dis[ne.dx][ne.dy] = ne.cnt;
					if (a[ne.x][ne.y] == dd[i])
						p[++p_tail] = ne;
					else
						q[++tail] = ne;
					// 加入队列
				}
			}
		}
	}
}

inline void readin()
{
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++)
		scanf("%s", a[i] + 1);
	if ((r + c) % 2 == 1)
	{
		flag = true;
		printf("NO SOLUTION\n");
	} // 无解情况
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		init();
		readin();
		bfs();
		if (!flag)
			printf("%d\n", dis[r][c]);
	}
}
