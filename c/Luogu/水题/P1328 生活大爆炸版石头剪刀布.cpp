#include<stdio.h>
int a[5][5]={{0,-1,1,1,-1},{1,0,-1,1,-1},{-1,1,0,-1,1},{-1,-1,1,0,1},{1,1,-1,-1,0}};
int scorea,scoreb,xa[210],xb[210],nowa,nowb;
int main()
{
	int i,n,na,nb;
	scanf("%d %d %d",&n,&na,&nb);
	for(i=0;i<na;i++)   scanf("%d",&xa[i]);
	for(i=0;i<nb;i++)   scanf("%d",&xb[i]);
	for(i=0;i<n;i++)
	{
		if(a[xa[nowa]][xb[nowb]]==1)         scorea++;
		else if(a[xa[nowa]][xb[nowb]]==-1)   scoreb++;
		
		nowa++;nowb++;
		if(nowa>=na)nowa=0;
		if(nowb>=nb)nowb=0;
	}
	printf("%d %d",scorea,scoreb);
}
