#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char stra[10010],strb[10010];
int a[10010],b[10010],c[10010];
int Subtraction(int a[10010],int b[10010],int lc)//�߾��ȼ���
{
	int i;
	for(i=0;i<=lc;i++)
	{
		if(a[i]<b[i])//��λ
		{
			a[i]+=10;
			a[i+1]--;
		}
		c[i]=a[i]-b[i];
	}
}
int main()
{
	//���봦��
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
	
	x=la-lb;//x:a��b����λ��֮�λ�������ʹ�
	
	if(x>0)//a>b
	{
		Subtraction(a,b,lc);//���С
		cmp=false;//false:����>0
	}
	else if(x<0)//a<b(λ��ҪС��
	{
  		Subtraction(b,a,lc);//���С
  		cmp=true;//true:����<0
	}
	else//a��bλ����ͬ
	{
		if(strcmp(stra,strb)>0)//a>b
		{
			Subtraction(a,b,lc);//���С
			cmp=false;//false:����>0
		}
		else if(strcmp(stra,strb)<0)//a<b
		{
			Subtraction(b,a,lc);//���С
			cmp=true;//true:����<0
		}
		else//a=b
		{
			printf("0");
			return 0;
		}
	}
	while(c[lc]==0&&lc>0) lc--;
	if(cmp==true) printf("-");//�������<0�����为�ţ��������
	for(i=lc;i>=0;i--)
		printf("%d",c[i]);
	return 0;
}
