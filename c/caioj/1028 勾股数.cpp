#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int A,B;
	int a[10000];
	for(int i=0;i<10000;i++)
	{
		a[i]=i*i;
	}
	scanf("%d%d",&A,&B);
	int i,j,k;
	for(i=A;i<=B;i++)
	{
		for(j=i+1;j<=B;j++)
		{
			int c=i*i+j*j;
			if(sqrt(c)>B) break;
			for(k=0;k<10000;k++)
			{
				if(c==a[k]) 
				{
					printf("%d %d %d\n",i,j,(int)sqrt(c));
					break;
				}
			}
		}
	}
	return 0;
}
