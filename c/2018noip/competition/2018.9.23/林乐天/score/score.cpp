#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct aa
{
	int num,s;
}p[10000];
bool cmp(aa a,aa b)
{
	if(a.s == b.s) return a.num < b.num;
	return a.s > b.s;
}

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i++)
		scanf("%d%d",&p[i].num,&p[i].s);
	sort(p,p+n,cmp);
	int line = p[(int)(m* 1.5)-1].s ;
	int i = 0,tot = 0;
	while(p[i].s >= line)
	{
		tot++;
		i++;
	}
	printf("%d %d\n",line,tot);
	for(int i = 0;i < tot;i++)
		printf("%d %d\n",p[i].num,p[i].s);
	return 0;
} 
