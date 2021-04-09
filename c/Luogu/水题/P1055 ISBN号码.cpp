#include<stdio.h>
char a[100];
int main()
{
	int i,sum=0,ans,tmp=0,tmpa=0;
	bool is;
	scanf("%s",a);
	for(i=0;i<11;i++)
	{
		if(a[i]!='-')
		{
			tmp++;
			if(a[i]=='X') tmpa=10;
			else          tmpa=a[i]-'0';
			sum+=tmpa*tmp;
		}
	}
	if(a[12]=='X') a[12]=10+'0';
	if(sum%11+'0'==a[12])   is=true;
	else                    is=false;
	if(is)  printf("Right");
	else    
	{
		for(i=0;i<12;i++) printf("%c",a[i]);
		if(sum%11<10)     printf("%d",sum%11);
		else              printf("X");
		return 0;
	}
}
