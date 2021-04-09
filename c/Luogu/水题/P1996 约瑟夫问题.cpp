#include<stdio.h>
struct node
{
	int n;
	node *next;
};
node *head,*p,*r;
int main()
{
	int m,n,i,j;
	scanf("%d%d",&n,&m);
	head=new node;
	head->n=1;head->next=NULL;r=head;
	for(i=2;i<=n;i++)
	{
		p=new node;
		p->n=i;
		p->next=NULL;
		r->next=p;
		r=p;
	}
	r->next=head;
	r=head;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m-2;j++)
		r=r->next;
		printf("%d ",r->next->n);
		//del
		r->next=r->next->next;
  		r=r->next;
	}
	return 0;
}
