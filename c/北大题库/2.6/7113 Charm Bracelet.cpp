#include<stdio.h>
#include<algorithm>
using namespace std;
int f[12890];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(n)
	{
		int w,d;
		scanf("%d%d",&w,&d);
		for(int i=m;i>=w;i--)
			f[i]=max(f[i],f[i-w]+d);
		n--;
	}
	printf("%d",f[m]);
	return 0;
}
