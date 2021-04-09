#include<stdio.h>
int main()
{
	int a,mon,day,now=0,i;
	char b;
	scanf("%d\n%c\n%d %d",&a,&b,&mon,&day);
	for(i=0;i<mon;i++)
	{
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)   now+=31;
		else if(i==4||i==6||i==9||i==11)					   now+=30;
		else if(i==2)
		{
			if(b=='p')    now+=28;
			else          now+=29;
		}
	}
	now+=day-1;
	now=now%7;
	if(now==1)  printf("MON");
	if(now==2)  printf("TRU");
	if(now==3)  printf("WED");
	if(now==4)  printf("THU");
	if(now==5)  printf("FIR");
	if(now==6)  printf("SAT");
	if(now==0)  printf("SUN");
	return 0;
}
