#include<stdio.h>
#include<algorithm>
using namespace std;
int a[200000];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	a[n] = -1;
	int count = 0;
	for(int i = 0;i < n;i++)
	{
		if(a[i] == a[i+1]) count++;
		else
		{
			printf("%d %d\n",a[i],count);
			count = 0;	
		}
	}
	return 0;
}
