#include<stdio.h>
#include<math.h>
void input(int &b,int &c,int d[101][101])
{
	scanf("%d %d",&b,&c);
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<c;j++)
		{
			scanf("%d",&d[i][j]);
		}
	}
}

void work(int m,int n,int a[101][101],int r,int s,int b[101][101],int &mini,int &minj)
{
	int min=1000000,tmp=0;
	int i,j,p,q;
	for(i=0;i<m-r+1;i++)
	{
		
		for(j=0;j<n-s+1;j++)
		{
			tmp=0;
			for(p=0;p<r;p++)
			{
				for(q=0;q<s;q++)
				{
					tmp+=fabs(a[i+p][j+q]-b[p][q]);
				}
			}
			if(min>tmp)
			{
				mini=i;
				minj=j;
				min=tmp;
			}
		}
	}
}

void output(int mini,int minj,int r,int s,int a[101][101])
{
	int i,j;
	for(i=mini;i<r;i++)
	{
		for(j=minj;j<=s;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}

int main()
{
	int m,n,r,s,a[101][101],b[101][101],mini,minj;
	input(m,n,a);
	input(r,s,b);
	work(m,n,a,r,s,b,mini,minj);
	output(mini,minj,r,s,a);
}
