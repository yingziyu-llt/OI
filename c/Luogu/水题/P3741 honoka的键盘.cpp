#include<stdio.h>
int main()
{
	char a[110];
	int n,sum=0;
	scanf("%d",&n);
	scanf("%s",a);
	for(int i=0;i<n;i++)
	{
		if(a[i]=='V'&&a[i+1]=='K') 
		{
			a[i]='x';
			a[i+1]='x';
			sum++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]=='V'&&a[i+1]=='V'||a[i]=='K'&&a[i+1]=='K')
		{
			sum++;
			break;
		}
	}
	printf("%d",sum);
	return 0;
}
