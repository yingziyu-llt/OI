#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[100000],b[10000],k,n;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		for(int j=0;j<n;j++)
			scanf("%d",&a[j]);
		for(int j=0;j<n;j++)
			scanf("%d",&b[j]);
		for(int j=0;j<n;j++) a[j]+=a[j-1];
		for(int j=0;j<n;j++) b[j]+=b[j-1];
		sort(a,a+n);
		sort(b,b+n);
		bool tf=false;
		for(int j=0;j<n;j++)
		{
			if(a[j]!=b[j])
			{
				printf("Wangzanbo Niubi\n");
				tf=true;
				break;
			}
		}
		if(tf) continue;
		printf("Ruiyang Dalao\n");
	}
	return 0;
}
