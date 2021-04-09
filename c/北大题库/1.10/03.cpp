#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int cj[20],x[20];
char name[20][21];
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s %d",&name[i],&cj[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(cj[i]<cj[j])  
			{
				swap(cj[i],cj[j]);
				swap(name[i],name[j]);
			}
			if(cj[i]==cj[j]&&strcmp(name[i],name[j])>0)
			{
				swap(cj[i],cj[j]);
				swap(name[i],name[j]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%s %d\n",name[i],cj[i]);
	}
	
}
