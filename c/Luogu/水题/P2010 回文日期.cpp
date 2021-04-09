#include<stdio.h>
int ans=0,hw_date[10000];
int create(int a)
{
	int b=0;
	int temp=a;
	for(int i=0;i<=4;i++)
	{
		b=b*10+a%10;
		a/=10;
	}
	a=temp+1000*b;
	return a;
}
int isdate(int a)
{
	int month=a/100%100;
	int day=a%100;
	if(month>12)
	{
		return 0;
	}
	else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{
		if(day>31||day<=0) return 0;
	}
	else if(month==2)
	{
		if(a==92200229) return 1;
		else if(day<=28) return 1;
		else return 0;
	}
	else if(month==0) return 0;
	else
	{
		if(day>30||day<=0) return 0;
	}
	return 1;
}
int work(int a,int b)
{
	int i;
	int x=0;
	for(int j=0;j<9999;j++)
	{
		i=create(j);
		if(isdate(i)==1) 
		{
			hw_date[x]=i;
			x++;
		}
	}
	for(i=0;i<=9999;i++)
	{
		if(hw_date[i]>=a&&hw_date[i]<=b)
		{
			ans++;
		}
	}
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	work(a,b);
	printf("%d",ans);
	return 0;
}
