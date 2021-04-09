#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int sign[100];//1+ 2- 3* 4/
double number[100];
int topnum,topsgn;
int pushn(double &a,double &b)
{
	a=number[topnum];
	number[topnum--]=0;
	b=number[topnum];
	number[topnum--]=0;
}
int pushs(int &c)
{
	c=sign[topsgn];
	sign[topsgn]=0;
	topsgn--;
}
int inf(double c)
{
	number[topnum++]=c;
}
int input()
{
	char str[100]={0};
	scanf("%s",str);
	if(str[0]=='+')                  sign[++topsgn]=1;
	else if(str[0]=='-')             sign[++topsgn]=2;
	else if(str[0]=='*')             sign[++topsgn]=3;
	else if(str[0]=='/')             sign[++topsgn]=4;
	else 							 inf(atof(str));
}
int main()
{
	input();
	while(topnum!=0&&topsgn!=0)
	{
		
		if(topnum==2)
		{
			double a,b;
			int c;
			pushn(a,b);
			pushs(c);
			switch (c)
			{
				case 1:inf(a+b);break;
				case 2:inf(a-b);break;
				case 3:inf(a*b);break;
				case 4:inf(a/b);break;
			}
		}
	}
	printf("%lf\n",number[topnum]);
	return 0;
}
