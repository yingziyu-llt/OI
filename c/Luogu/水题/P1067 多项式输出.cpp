#include<stdio.h>
struct aa
{
	int cishu,xishu;
}a[100];
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		scanf("%d",&a[i].xishu);
		a[i].cishu=n-i;
	}
	if(a[0].xishu!=1&&a[0].xishu!=-1)   printf("%dx^%d",a[0].xishu,a[0].cishu);
	else if(a[0].xishu==1) 				printf("x^%d",a[0].cishu);
	else                                printf("-x^%d",a[0].cishu);//��һ��
	for(i=1;i<n;i++)
	{
		if(a[i].xishu!=0)
		{
			if(a[i].cishu==1)
			{
				if      (a[i].xishu>1)       printf("+%dx",a[i].xishu);
				else if (a[i].xishu<-1)		 printf("%dx",a[i].xishu);
				else if (a[i].xishu==1)		 printf("+x");
				else if (a[i].xishu==-1)     printf("-x");
				break;
			}
			if      (a[i].xishu>1)       printf("+%dx^%d",a[i].xishu,a[i].cishu);
			else if (a[i].xishu<-1)		 printf("%dx^%d",a[i].xishu,a[i].cishu);
			else if (a[i].xishu==1)		 printf("+x^%d",a[i].cishu);
			else if (a[i].xishu==-1)     printf("-x^%d",a[i].cishu);
			else if (a[i].xishu==0)      ;
		}
	}//����һ���������ǳ�����
	if(a[n].xishu>0) printf("+%d",a[n].xishu);
	else if(a[n].xishu<0) printf("%d",a[n].xishu);
	return 0;
}
