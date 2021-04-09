#include<stdio.h>
#include<algorithm> 
using namespace std;
struct action
{
	int f,l;
}a[10010];
bool cmp(action a,action b) {return a.l < b.l;}
int main()
{
	int n;
	int now = 0;
	int ans = 0;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d%d",&a[i].f,&a[i].l);
	sort(a,a + n,cmp);
	for(int i = 0;i < n;i++)
	{
		if(now <= a[i].f)
		{
			ans++;
			now = a[i].l;
		}
	}
	printf("%d",ans);
}
