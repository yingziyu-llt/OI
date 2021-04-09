#include<stdio.h>
#include<algorithm>
using namespace std;
int street[30010];
struct str
{
	int f,l,t;
}a[5010];
bool cmp(str a,str b)
{
	return a.l < b.l;
}
int main()
{
	int n,h,ans = 0;
	scanf("%d%d",&n,&h);
	for(int i = 0; i < n;i++)
	{
		scanf("%d%d%d",&a[i].f,&a[i].l,&a[i].t);
	}
	sort(a,a + n,cmp);
	for(int i = 0;i < n;i++)
	{
		int tot = 0;
		for(int j = a[i].f;j <= a[i].l;j++)
		{
			tot += street[j];
		}
		if(tot < a[i].t)
		{
			for(int j = a[i].l;j <= a[i].f;j--)
			{
				if(tot >= a[i].t) break;
				if(street[j] != 1)
				{
					street[j] = 1;
					tot ++;
					ans++;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}