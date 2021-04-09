#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,count=0;
	char x[20];
	while(scanf("%s",x)!=EOF)
	{
		a=0;
		b=0;
		c=0; 
		int len=strlen(x);
		int i=0;
		int sign=0;
		if(x[len-1]=='?') continue;
		while(1)
		{
			if(x[i]=='+')
			{
				sign=1;
				break;
			}
			if(x[i]=='-')
			{
				sign=2;
				break;
			}
			a=a*10+x[i]-'0';
			i++;
		} 
		i++;
		while(1)
		{
			if(x[i]=='=') 
			{
				break;
			}
			b=b*10+x[i]-'0';
			i++;
		}
		i++;
		while(1)
		{
			if(i>=len)
			{
				break;
			}
			if(x[i]>='0'&&x[i]<='9')
			{
				c=c*10+x[i]-'0';
			}
			i++;
		}
		int ans;
		if(sign==1) ans=a+b;
		if(sign==2) ans=a-b;
		if(ans==c)  count++;
	}
	printf("%d",count);
	return 0;
}
