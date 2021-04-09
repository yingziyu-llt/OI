#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char stra[10010],strb[10010];
int a[10010],b[10010],c[10010];
int Subtraction(int a[10010],int b[10010],int lc)//高精度减法
{
	int i;
	for(i=0;i<=lc;i++)
	{
		if(a[i]<b[i])//借位
		{
			a[i]+=10;
			a[i+1]--;
		}
		c[i]=a[i]-b[i];
	}
}
int main()
{
	//输入处理
	bool cmp=false;
	int x,i,la,lb,t,lc;
 	scanf("%s",stra);
	scanf("%s",strb);
	la=strlen(stra);
	lb=strlen(strb);
	for(i=0;i<la;i++)
	{
		a[i]=stra[la-i-1]-'0';
	}
	for(i=0;i<lb;i++)
	{
		b[i]=strb[lb-i-1]-'0';
	}
	lc=la>lb?la:lb;/*
	                    if(la>lb) lc=la;
	                    else      lc=lb;
					*/
	
	x=la-lb;//x:a、b两数位数之差（位数大，数就大）
	
	if(x>0)//a>b
	{
		Subtraction(a,b,lc);//大减小
		cmp=false;//false:得数>0
	}
	else if(x<0)//a<b(位数要小）
	{
  		Subtraction(b,a,lc);//大减小
  		cmp=true;//true:得数<0
	}
	else//a、b位数相同
	{
		if(strcmp(stra,strb)>0)//a>b
		{
			Subtraction(a,b,lc);//大减小
			cmp=false;//false:得数>0
		}
		else if(strcmp(stra,strb)<0)//a<b
		{
			Subtraction(b,a,lc);//大减小
			cmp=true;//true:得数<0
		}
		else//a=b
		{
			printf("0");
			return 0;
		}
	}
	while(c[lc]==0&&lc>0) lc--;
	if(cmp==true) printf("-");//如果得数<0，先输负号，再输得数
	for(i=lc;i>=0;i--)
		printf("%d",c[i]);
	return 0;
}
