#include<bits/stdc++.h>
using namespace std;
char s[101][51];
int main()
{
	int i,j,x;
	i=0;
	//freopen("2.in","r",stdin);
	for(x=0;;x++)
	{
		scanf("%s",s[x]);
		if(s[x][0]=='\0')  break;
	}
	for(i=0;i<x-1;i++)
	{
		for(j=i+1;j<x;j++)
		{
			if(strcmp(s[i],s[j])>0) swap(s[i],s[j]);
		}
	}
	for(i=0;i<x;i++)
	{
		if(strcmp(s[i],s[i+1])!=0)
		{
			printf("%s",s[i]);
			if(i<x-1)
			printf("\n");
		}
		
	}
	return 0;
}
