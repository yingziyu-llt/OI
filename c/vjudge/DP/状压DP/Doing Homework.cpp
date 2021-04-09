#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int INF = 0x3fffffff;
int n,d[20],c[20];
char names[20][100];
struct Node
{
	int sum,tim,nxt,now;
}f[1 << 16];

void print(int n)
{
	if(n != -1)
	{
		print(f[n].nxt);
		printf("%s\n",names[f[n].now]);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
			scanf("%s %d%d",names[i],&d[i],&c[i]);
		f[0] = (Node){0,0,-1,-1};
		for(int i = 1;i < 1 << n;i++)
		{
			f[i].sum = INF;
			for(int j = 0;j < n;j++)
			{
				if((1 << j ) & i)
				{
					int k = i - (1 << j),t = max(0,f[k].tim - d[j] + c[j]);
					if(f[k].sum + t <= f[i].sum)
						f[i] = (Node){f[k].sum + t,f[k].tim + c[j],k,j};
				}
			}
		}
		printf("%d",f[(1 << n) - 1].sum);
		print((1 << n) - 1);
	}
	return 0;
}