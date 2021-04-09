#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000];
int f[1000];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	f[0]=a[0];
	f[1]=a[1]+a[0];
	for(int i=2;i<n;i++)
		f[i]=max(f[i-1],max(f[i-2]+a[i],f[i-3]+a[i]+a[i-1]));
	printf("%d",f[n-1]);
	return 0;
}
