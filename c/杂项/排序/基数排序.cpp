#include<stdio.h>
#include<math.h>
int a[100],b[10][100],maxn,z[10],x,xx=1;
int main()
{
	int i,j,n,y,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	maxn=a[0];
	for(i=1;i<n;i++)
	{
		if(maxn<a[i])      a[i]=maxn;
	}
	y=(int)log10(maxn)+1;
	for(i=0;i<y;i++)
	{
		xx=xx*10;
		x=0;
		for(j=0;j<n;j++)/*ฝ๘ื้*/
		{ 
			switch((int)(a[j]%xx/xx*10))
			{
				case 0:
					b[0][z[0]]=a[j];
					z[0]++;
					break;
				case 1:
					b[1][z[1]]=a[j];
					z[1]++;
					break;
				case 2:
					b[2][z[2]]=a[j];
					z[2]++;
					break;
				case 3:
					b[3][z[3]]=a[j];
					z[3]++;
					break;
				case 4:
					b[4][z[4]]=a[j];
					z[4]++;
					break;
				case 5:
					b[5][z[5]]=a[j];
					z[5]++;
					break;
				case 6:
					b[6][z[6]]=a[j];
					z[6]++;
					break;
				case 7:
					b[7][z[7]]=a[j];
					z[7]++;
					break;
				case 8:
					b[8][z[8]]=a[j];
					z[8]++;
					break;
				case 9:
					b[9][z[9]]=a[j];
					z[9]++;
					break;
			}
		}
		for(j=0;i<n;j++)
		{
			
			for(k=0;k<z[j];k++)
			{
				a[x]=b[j][k];
				x++;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}
