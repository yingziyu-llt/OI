#include<stdio.h>
#include<string.h>
char stra[1001],strb[1001];
int a[1001],b[1001],c[1005];
int main()
{
	int i,la,lb,lc,t;
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
	//���봦��
	lc=la>lb?la:lb;
	t=0;
	for(i=0;i<=lc;i++)
	{
		c[i]=a[i]+b[i]+t;
		t=c[i]/10;
		c[i]%=10;//��λ
	}
	c[++lc]=t;//���λ���Ͻ�λ
	while(c[lc]==0&&lc>0) lc--;//Ĩ��ǰ��0
	for(i=lc;i>=0;i--)
		printf("%d",c[i]);
	return 0;
}
