#include<stdio.h>
#include<algorithm>
using namespace std;
int f[30010];
int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	while(m--)
	{
		int val,wei;
		scanf("%d%d",&wei,&val);
		for(int i=n;i>=wei;i--)
			f[i]=max(f[i-wei]+val*wei,f[i]);
	}
	printf("%d",f[n]);
	return 0;
}
