#include<stdio.h>
struct node
{
	int date,nxt,pre;
}n[10000];
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int num;
	int now = 0;
	scanf("%d",&num);
	for(int i = 0;i < num - 1;i++)
		n[i].nxt = i + 1;
	n[num - 1].nxt = 0;
	for(int i = 1;i < num;i++)
		n[i].pre = i - 1;
	n[0].pre = num - 1;
	for(int i = 0;i < num;i++)
	{
		n[now].date = i + 1;
		n[n[now].pre].nxt = n[now].nxt;
		n[n[now].nxt].pre = n[now].pre;
		now = n[now].nxt;
		for(int j = 0;j < i + 2;j++)
		{
			now = n[now].nxt;
		}
	}
	for(int i = 0;i < num;i++)
		printf("%d ",n[i].date);
	return 0;
}