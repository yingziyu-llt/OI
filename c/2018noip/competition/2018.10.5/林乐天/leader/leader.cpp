#include <stdio.h>
#include<algorithm>
using namespace std;
struct s
{
	int count,num;
}a[10010];
bool cmp(s a,s b)
{
	return a.count > b.count;
}
int main()
{
	freopen("leader.in","r",stdin);
	freopen("leader.out","w",stdout);
	int m,s,count = 0,n;
	scanf("%d%d",&n,&m);
	for(int i = 0;i < m;i++)
	{
		bool x = false;
		scanf("%d",&s);
		for(int j = 1;j <= count;j++)
			if(a[j].num == s)
			{
				a[j].count++;
				x = true;
				break;
			}
		if(!x)
		{
			a[++count].count = 1;  
			a[count].num = s;
		}
	}
	sort(a + 1,a + count + 1,cmp);
	if(a[1].count > m / 2)
		printf("%d",a[1].num);
	else
		printf("-1");
	return 0;
}
