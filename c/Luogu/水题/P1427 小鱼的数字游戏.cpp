#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[100];
	int i;
	memset(a,0,sizeof(a));
	for(i=0;;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0) break;
	}	
	for(--i;i>=0;i--)
	{
		printf("%d ",a[i]);
	}
	return 0;
} 
