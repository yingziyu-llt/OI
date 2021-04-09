#include<stdio.h>
#include<algorithm>
using namespace std;
struct aa
{
	int s,h;
}apple[10000];
int main() 
{
	int n,s,a,b;
	int ans=0;
	scanf("%d%d%d%d",&n,&s,&a,&b);
	for(int i = 0;i < n ;i++)
		scanf("%d%d",&apple[i].h,&apple[i].s);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			if(apple[j].s>apple[i].s)
				swap(apple[i],apple[j]);
	for(int i = 0;s > 0;i++)
		if(apple[i].h <= a + b && (s -= apple[i].s) >= 0)
			ans++;
	printf("%d",ans);
	return 0;
}
