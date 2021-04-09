#include<stdio.h>
#include<algorithm>
using namespace std;
int f[100],a[100];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
			f[i]=max(f[i-1],f[i-2]+a[i]);
		printf("%d\n",f[n-1]);
	}
}
