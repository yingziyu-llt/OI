#include<stdio.h>
#include<algorithm>
using namespace std;
struct aa
{
	int w,d,num;
}p[100000];
int e[15];
bool cmp(aa a,aa b)
{
	if(a.w!=b.w) return a.w > b.w;
    return a.num < b.num;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= 10;i++)
		scanf("%d",&e[i]);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&p[i].w);
		p[i].num = i;
	}
	sort(p,p+n,cmp);
	for(int i = 0;i < n;i++)
		p[i].w = e[i % 10 + 1] + p[i].w;
	sort(p,p+n,cmp);
	for(int i = 0;i < k;i++)
		printf("%d ",p[i].num + 1);
	return 0;
}
