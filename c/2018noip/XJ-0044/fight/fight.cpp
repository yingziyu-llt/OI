#include<stdio.h>
#include<math.h>
using namespace std;
struct aa
{
	long long val;
	int p;
}a[100010];
int place[100010];
int main()
{
	//freopen("fight.in","r",stdin);
	//freopen("fight.out","w",stdout);
	int n;
	long long tot = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",&place[i]);
	
	int m;
	scanf("%d",&m);
	
	int p1,s1,s2;
	scanf("%d%d%d",&p1,&s1,&s2);
	
	place[p1] += s1;
	
	for(int i = 0;i < m - 1;i++)
	{
		tot += (m - i) * place[i];	
		if(m - i > m)
			tot -= (i - m) * place[m - i];
	}  
	
	for(int i = 1;i <= m;i++)
	{
		a[i].p = i;
		a[i].val =	fabs((m - i) * s2 + tot);
	}
	
	for(int i = m + 1;i <= n;i++)
	{
		a[i].p = i;
		a[i].val = fabs((double)(i - m) * s2 + tot);
	}
	
	int ans;
	unsigned long long min = 0xffffffffffffffff;
	for(int i = 1;i <= n;i++)
	{
		if(min > a[i].val)
		{
			min = a[i].val;
			ans = a[i].p;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
