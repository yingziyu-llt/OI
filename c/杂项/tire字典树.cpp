#include<stdio.h>
#include<string.h>
struct l
{
	//something you need
	int n,kind;
};
struct node
{
	node *pre;
	node *nxt[128];
	l    *ed;
	int kind;
};
node *head=new node;
int cre(char a[],int n)
{
	node *r;
	r=head;
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(r->nxt[a[i]]==NULL) r->nxt[a[i]]=new node;
		r=r->nxt[a[i]];
		r->kind=1;
	}
	r->ed=new l;
	r->ed->kind=2;
	return 0;//success
}
int searchf(char a[])
{
	node *r=head;
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(r->nxt[a[i]]!=NULL) r=r->nxt[a[i]];
		else                   return -1;
	} 
	return r->ed->n;
}
int del(char a[])
{
	node *r=head;
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(r->nxt[a[i]]!=NULL) r=r->nxt[a[i]];
		else                   return 0;
	} 
	r->ed=NULL;
	return 0;
}
