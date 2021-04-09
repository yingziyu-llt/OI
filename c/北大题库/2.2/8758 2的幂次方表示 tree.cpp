#include<stdio.h>
struct node
{
	node *son[100],*father=NULL;
	int num;
};
node *a=new node;
int tob(int x,int a[64])
{
	int i=0;
	while(x!=0)
	{
		a[i]=x%2;
		x/=2;
		i++;
	}
	a[i]=-1;
}
int num(node *a)
{
	int x=0,i=0;
	for(i=0;a->son[i]!=NULL;i++)
		x++;
	return x;
}
int pd(node *a)
{
	int i=a->num;
	if(i==0||i==1)
	{
		return 0;
	}
	else
	{
		int c[64]={0};
		tob(a->num,c);
		for(int j=0;c[j]!=-1;j++)
		{
			a->son[j]=new node;
			a->son[j]->num=c[j];
		}
	}
	for(i=0;i<num(a);i++)
	{
		
	}
}
