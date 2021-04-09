#include<stdio.h>
#include<math.h>
#define x M_PI/7
#define S sin(x)*sin(x)
#define C cos(x)*cos(x)
int main()
{
	int m;
	scanf("%d",&m);
	double max=0;
	getchar();
	for(int i=0;i<m;i++)
	{
		char c;
		double tmp=0;
		while(1)
		{
			c=getchar();
			if(c=='\n')
				break;
			if(c=='s') tmp+=S;
			if(c=='c') tmp+=C;
		}
		if(max+tmp>max) max+=tmp;
	}
	printf("%.0g",max);
	return 0;
}
