#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct aa
{
	int kind,count,frist;
	aa *nxt[26];
};
aa *head;
int nowc;
int findf(char a[])
{
	int len = strlen(a);
	aa *x=head;
	for(int i = 0;i < len;i++)
	{
		if(x->nxt[a[i] - 'A'] == NULL) return -1;
		else x = x->nxt[a[i] - 'A'];
	}
	nowc = x->frist;
	if(x->kind == 0) return -1;
	else             return x->count;
}
void clean(aa *c)
{
	for(int i = 0;i < 26;i++)
		c->nxt[i] = NULL;
	c->kind = 0;
	c->count = 0;
	c->frist = 0;
} 
void build(char a[])
{
	int len = strlen(a);
	aa *x;
	x = head;
	for(int i = 0;i < len;i++)
	{
		if(x->nxt[a[i] - 'A'] == NULL) 
		{
			x->nxt[a[i] - 'A'] = new aa;
			clean(x->nxt[a[i] - 'A']);
		}
		x = x->nxt[a[i] - 'A'];
	}
	x->kind = 1;
	x->count += 1;
	x->frist = max(x->frist,nowc);
}
void upper(char a[])
{
	int len = strlen(a);
	for(int i = 0;i < len;i++)
		if(a[i] >= 'a' && a[i] <= 'z')
			a[i] = a[i] - 'a' + 'A';
}
int main()
{
	char a[100];
	head = new aa;
	freopen("ta.txt","r",stdin);
	clean(head);
	scanf("%s",a);
	upper(a);
	char x[10000];
	while(~scanf("%s",x))
	{
		upper(x);
		build(x);
		nowc += strlen(x);
	}
	int c,ans;
	ans = findf(a);
	if(ans = -1) printf("-1");
	else         printf("%d %d",ans,nowc);
	return 0;
}
