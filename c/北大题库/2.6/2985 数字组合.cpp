#include<stdio.h>
#include<algorithm>
using namespace std;
int a[110];
int map[1010];
int main()
{
	int n,t;
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]); 
	map[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=t;j>=a[i];j--)
			map[j]+=map[j-a[i]];
	}
	printf("%d",map[t]);
}
