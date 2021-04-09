#include<stdio.h>
#include<windows.h> 
#include<string.h>
int ans[10010];
int add(int a[],int b[],int max)
{	
	int i,tmp=0;
	bool x=false;
	for(i=0;i<=max;i++)
	{
		if(i==max)
		{
			ans[i]++;if(tmp==1)x=true;
		}
		ans[i]=a[i]+b[i]+tmp;
		tmp=0;
		if(ans[i]>=10)
		{
			tmp=1;
			ans[i]=ans[i]-10;
		}
	}
	printf("答案是：");
	if(tmp) printf("%d",ans[max]);
	for(i=max-1;i>=0;i--)
	{
		printf("%d",ans[i]);
	}
	Sleep(1000*10);
	return 0;
}
int times(int a[],int b[],int max)
{
	
}
int main()
{
	
	char in1[100],in2[100],x;
	int a[100],b[100],i,temp,z,la,lb,j,max;
	for(i=0;i<100;i++)
	{
		a[i]=-1;
		b[i]=-1;
	}
	for(i=0;i<10000;i++)
	{
		ans[i]=-1;
	}
	printf("输入数字\n");
	scanf("%s",in1);
	printf("输入符号\n");
	for(; ;)
	{
	scanf("\n%c",&x);
	if(x=='+')        {z=1;break;}
	else if(x=='-')   {z=2;break;}
	else if(x=='*')   {z=3;break;}
	else              printf("符号错误(暂无法使用/)");
	}
	printf("输入数字\n");
	scanf("%s",in2);
	la=strlen(in1);
	lb=strlen(in2);
	
	temp=0;
	
 	for(i=0;i<la;i++)
	{
		a[la-i-1]=in1[i]-'0';
	}

	for(i=0;i<lb;i++)
	{
		b[lb-i-1]=in2[i]-'0';
	}
	i=(la>lb)?la:lb;max=i;
	if(z==1)//加法 
	{
		add(a,b,i);
		return 0;
	}
	if(z==2)
	{
		jianfa(a,b,i);
		return 0;
	}
	/***************/
	if(z==3)//乘法
	{
	}
}
