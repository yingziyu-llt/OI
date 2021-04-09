#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int w,n,p[30000]={0},ans=0;
	scanf("%d",&w);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&p[i]);
	sort(p,p+n);
	int z=0,y=n-1;
	while(z<=y)
	{
		if(p[z]+p[y]<=w)
		{
			ans++;
			z++;
			y--;
		}
		else
		{
			y--;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
} 
