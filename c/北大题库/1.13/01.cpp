#include<stdio.h>
#include<string.h>
char na[32],nb[32];
long int n10;
int main()
{
	int i,a,b,L;
	scanf("%d %s %d",&a,&na,&b);
	L=strlen(na);
	if(a!=10)
	{ 
	for(i=0;i<L;i++)
	{
		if(na[i]>='0'&&na[i]<='9')     n10=na[i]-'0'+n10*a;
		if(na[i]>='a'&&na[i]<='f')     n10=na[i]-'a'+n10*a+10;
		if(na[i]>='A'&&na[i]<='F')     n10=na[i]-'A'+n10*a+10;
	}
	} 
	else  
	for(i=0;i<L;i++)
	{
		n10=na[i]-'0'+n10*10;
	}
	i=0;
	if(n10==0)
	{
		printf("0");
		return 0;
	}
	if(b!=10)
	{
	while(n10!=0)
	{
		if(n10%b>9)   nb[i]=n10%b-10+'A';
		else   nb[i]=n10%b+'0';
		n10=n10/b;
		i++;
	}
    }
    if(b==10)  printf("%d",n10);
    else
    {
	for(i=i-1;i>=0;i--)
	{
		printf("%c",nb[i]);
	}
    }
	return 0;
}

