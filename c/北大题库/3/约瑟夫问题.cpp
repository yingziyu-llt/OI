#include<bits/stdc++.h>
using namespace std;
struct node
{
	int num;
	node *next=NULL;
};
node *r=new node,*t,*head,*last;
void del(node *fir)
{
	node *n;
	n=fir->next;
	fir->next=fir->next->next;
	free(n);
}
void cre(int n)
{
	r->num=1;
	for(int i=2;i<=n;i++)
	{
		r=new node;
		r->num=i;
		r->next=NULL;
		t->next=r;
		t=r;
	}
	r->next=head;
	r=head;
}
int main()
{
	t=head=last=r;
	while(1)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==0&&b==0)  break;
		cre(a);
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<b;j++)
				r=r->next;
			if(a==1) 
			{
				printf("%d",r->num);
				del(r);
				break;
			}
 			del(r);
 			a--;
		}
		r=new node;
		t=head=last=r;
	}
		
}
