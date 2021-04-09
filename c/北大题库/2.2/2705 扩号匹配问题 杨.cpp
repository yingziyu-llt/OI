#include<stdio.h>
#include<string.h> 
char a[101],b[101];
int pd(int x)
{
	if(x==-1)
	{
		return -1;
	}
	else if(b[x]=='$')
	{
		return x;
	} 
	else
	{
		return pd(x-1);
	}
}
int main()
{
	int i;
	while(scanf("%s",a)!=EOF)
	{
		int la;
		la=strlen(a);
		memset(b,' ',sizeof(b));
		for(i=0;i<=la-1;i++)
		{
			if(a[i]=='(')
			   b[i]='$';
			else if(a[i]==')')
			{
				int w=pd(i-1);
				if(w==-1)
				{
					a[i]='?';
				}
				else 
				{
					a[w]=' ';
				}
			}
		}	
		puts(a);
		puts(b); 
		memset(a,0,sizeof(a));
	}
	return 0;
} 
