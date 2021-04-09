#include<stdio.h>
#include<algorithm>
using namespace std;
int f[100010];
int main()
{
	int t,m;
	scanf("%d%d",&t,&m);
	for(int _i=0;_i<m;_i++)
	{
		int v,c;
		scanf("%d%d",&c,&v);
		for(int i=c;i<=t;i++)
			f[i]=max(f[i-c]+v,f[i]);
	}
	printf("%d",f[t]);
	return 0;
}
