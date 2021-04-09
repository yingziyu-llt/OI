#include<stdio.h>
#include<algorithm>
using namespace std;
int f[10000];
int main()
{
	int n,m;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)
	{
		int v,c;
		scanf("%d%d",&c,&v);
		for(int i=m;i>=c;i--)
			f[i]=max(f[i-c]+v,f[i]);
	}
	printf("%d",f[m]);
	return 0;
} 
