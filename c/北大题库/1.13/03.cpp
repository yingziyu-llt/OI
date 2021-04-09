#include<stdio.h>
#include<math.h>
int n8[15],x=1,n;
double ans,in;
char temp;
int main()
{
	int i;
	scanf("%lf",&in);
	for(i=0;i<15;i++)
	{
		n8[i]=(int)(in*10);
		in=in*10.000000000-(double)n8[i];
		if(in==0) {
			n8[i+1]=-1;
			break;
				  }
	}
	for(i=0;n8[i]!=-1;i++)
	{
		x=x*8;
		ans=((double)n8[i]/(double)x)+ans;
	}
	printf("%lf",ans);
	return 0;
}
