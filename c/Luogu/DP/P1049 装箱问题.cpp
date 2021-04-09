#include<stdio.h>
#include<algorithm>
using namespace std;
int f[30010];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int val;
		scanf("%d",&val);
		for(int i=n;i>=val;i--)
			f[i]=max(f[i-val]+val,f[i]);
	}
	printf("%d",n-f[n]);
	return 0;
}
