#include<stdio.h>
#include <string.h>
char name[100][21],gb1[101],xb[100];
int qimo[100],banji[100],lw[100],qian1[100],sum;
int main()
{
	int n,i,max=-1,maxl,l;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s %d %d %c %c %d",&name[i],&qimo[i],&banji[i],&gb1[i],&xb[i],&lw[i]);
	}
	for(i=0;i<n;i++)
	{
		if(qimo[i]>80&&lw[i]>0)	    qian1[i]=qian1[i]+8000;//院士 
		if(qimo[i]>85&&banji[i]>80)	qian1[i]=qian1[i]+4000;//54
		if(qimo[i]>90)              qian1[i]=qian1[i]+2000;//成绩优秀
		if(qimo[i]>85&&xb[i]=='Y')  qian1[i]=qian1[i]+1000;//西部 
		if(banji[i]>80&&gb1[i]=='Y')qian1[i]=qian1[i]+850;//班级 
	}
	for(i=0;i<n;i++)
	{
		sum=sum+qian1[i];
		if(qian1[i]>max)
		{
			maxl=i;
			max=qian1[i];
		}
	}
	l=0;
	/*for(i=0;i<21;i++)
	{
		if(name[maxl][i]!='\0')   l++;
		else break;
	}*/
	l=strlen(name[maxl]);
	for(i=0;i<l;i++)  printf("%c",name[maxl][i]);
	printf("\n%d\n%d",qian1[maxl],sum);
	return 0;
}
