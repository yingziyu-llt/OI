#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[110000]={0},n,k,ans[110000]={0};
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		a[tmp]=1;
	}
	int j=0;
	for(int i=0;i<100000;i++)
	{
		if(a[i]==1)
		{
			j++;
			ans[j]=i;
		}
	}
	sort(ans,ans+j);
	if(k>j+1)
		printf("NO RESULT");
	else 
		printf("%d",ans[k]);
	return 0;
}
