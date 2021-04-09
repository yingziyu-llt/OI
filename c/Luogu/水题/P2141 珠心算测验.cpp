#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int map[20010];
int main()
{
	int n,a[110],ans=0;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		map[a[i]]=1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(map[a[i]+a[j]]==1) 
			{
				ans++;
				map[a[i]+a[j]]=2;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
