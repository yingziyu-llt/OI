#include<stdio.h>
#include<algorithm>
using namespace std;
struct aa
{
	int s;
	int w;
	int num;
}p[200010];
aa win[100010],lose[100010];
bool cmp(aa x,aa y)
{
	if(x.s == y.s) return x.num < y.num;
	return x.s > y.s;
}
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 0;i < n * 2;i++)
		scanf("%d",&p[i].s);
	for(int i = 0;i < n * 2; i++)
	{
		p[i].num = i + 1;
		scanf("%d",&p[i].w);
	}
	sort(p,p + n * 2,cmp);
	while(m--)
	{
		for(int i = 0;i < n * 2 ;i+=2)
		{
			if(p[i].w > p[i+1].w) 
			{
				p[i].s++;
				win[i>>1] = p[i];
				lose[i>>1] = p[i + 1];
			}
			else 
			{
				p[i + 1].s++;
				win[i>>1] = p[i + 1];
				lose[i>>1] = p[i];
			}
		}
		merge(win,win + n +1,lose,lose + n +1,p,cmp);
	}
	printf("%d",p[q-1].num);
}
