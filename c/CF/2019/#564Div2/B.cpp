#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int ans = n / 2 + 1;
	printf("%d\n",ans);
	if(n % 2 == 1)
	{
		for(int i = 1;i <= ans;i++)
			printf("%d %d\n",1,i);
		for(int i = 2;i <= ans;i++)
			printf("%d %d\n",i,ans);
	}
	if(n % 2 == 0)
	{
		for(int i = 1;i < ans;i++)
			printf("%d %d\n",1,i);
		for(int i = 2;i <= ans;i++)
			printf("%d %d\n",i,ans);
	}
	return 0;
}