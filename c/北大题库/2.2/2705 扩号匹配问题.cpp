#include<stdio.h>
#include<string.h>
char aa[110]; 
int mem[100];
int i;
int work(int a)
{
	int tf=0;
	int count=0;
	while(aa[i]!='('&&aa[i]!=')'&&aa[i]!='\0')
	{
		i++;
	}
	count=i;
	if(aa[i]=='(')
	{
		i++;
		tf=work(++a);
	}	
	else if(aa[i]==')')
	{
		if(a==0)
		{
			mem[i]=2;
			i++;
			work(a);
		}	
		else
		{
			i++;
			return 0;
		}	
	}
	else if(aa[i]=='\0')
	{
		return 1;
	}
	if(tf==0)
	{
		count=-1;
		work(--a);
	}
	if(tf==1&&mem[i]==0&&count!=-1)
	{
		mem[count]=1;
		return 1;
	}
} 
int main()
{
	int x=0;
	while(scanf("%s",aa)!=EOF)
	{
		i=0;
		work(0);
		printf("%s\n",aa);
		for(int ii=0;ii<strlen(aa);ii++)
		{
			if(mem[ii]==0)
			printf(" ");
			else if(mem[ii]==1)
			printf("$");
			else if(mem[ii]==2)
			printf("?");
			aa[i]='\0';
			mem[i]=0;
		}
		printf("\n");
		x++;
	}
	return 0;
} 
