#include<stdio.h>
#include<string.h>

int a[100],max=-1,maxl;
char name[100][21];
int main()
{ 
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %s",&a[i],&name[i]);
		/*for(j=0;j<=20;j++)
		{
			scanf("%c",&name[i][j]);
			if(name[i][j]=='\n')
			{
				name[i][j]='\0';
				break;	
			}
		}  */
	}
	for(i=0;i<n;i++)
	{
		if(a[i]>max)   
		{
			maxl=i;
			max=a[i];
		}
	}
	for(i=0;i<20;i++)
	{
		if(name[maxl][i]!='\0')
		{
			printf("%c",name[maxl][i]);
		}
		else break;
	}
	return 0;
}
