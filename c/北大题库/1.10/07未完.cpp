#include<bits/stdc++.h>
using namespace std;
double mtall[40],ftall[40];
char x[7];
int main()
{
	int i,j,n,m=0,g=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",&x);
		if(x[0]=='m')
		{
			scanf("%lf",&mtall[m]);
			m++;
		}
		else
		{
			scanf("%lf",&ftall[g]);
			g++;
		}
	}
	/*male*/
	for(i=0;i<m-1;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(mtall[i]>mtall[j])   swap(mtall[i],mtall[j]);
		}
	}
	/*female*/
	for(i=0;i<g-1;i++)
	{
		for(j=i+1;j<g;j++)
		{
			if(ftall[i]<ftall[j])   swap(ftall[i],ftall[j]);
		}
	}
	for(i=0;i<m;i++)
		printf("%.2lf ",mtall[i]);
	for(i=0;i<g;i++)
		printf("%.2lf ",ftall[i]);
	return 0;
} 

