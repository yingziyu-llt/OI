#include<stdio.h>
#include<algorithm>
using namespace std;
int x[100010];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	sort(x,x+n);
	for(i=0;i<n;i++)
	{
		if(x[i]!=x[i+1])    printf("%d ",x[i]);
	}
	return 0;
}
