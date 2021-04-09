#include<stdio.h>
#include<string.h>
int a[20],b[20],c[20][20];
int max,maxn,n;
bool isall(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]!=-1)
		{
			return false;
		}
	}
	return true;
} 
void clean()
{
	for(int i=0;i<20;i++)
	{
		if(c[maxn][i]<0) break;
		a[c[maxn][i]]=-1;
	}
}
int main()
{
	int cnt=1;
	while(~scanf("%d",&a[n])) n++;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i-1;j++)
		{
			if(a[i]<=a[j])
			{
				if(b[i]<b[j]+1) 
					b[i]=b[j]+1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(max<b[i])
		{
			max=b[i];
			maxn=i;	
		}
	}
	clean();
	cnt++;
	printf("%d\n",max+1);
	while(!isall(n))
	{
		
		for(int i=0;i<n;i++)
		{
			b[i]=1;
		}
		memset(c,-1,sizeof(c));
		for(int i=0;i<n;i++)
		{
			int x=0;
			for(int j=0;j<=i-1;j++)
			{
				if(a[i]<=a[j])
				{
					if(b[i]<b[j]+1) 
						b[i]=b[j]+1;
					c[i][x++]=j;
				}
			}
		}
		max=0,maxn=0;
		for(int i=0;i<n;i++)
		{
			if(max<b[i])
			{
				max=b[i];
				maxn=i;	
			}
		}
		clean();
		cnt++;
	}
	printf("%d",cnt);
	return 0;
}
