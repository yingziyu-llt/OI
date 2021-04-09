#include<stdio.h>
struct aa
{
	int s;
	int t;
}a,n[1000000];
int b[1000000];
int ans;
int main()
{
	int na;
	int head=1,tail=0;
	scanf("%d",&na);
	for(int _i=0;_i<na;_i++)
	{
		int x,time;
		scanf("%d %d",&time,&x);
		while(x--)
		{
			scanf("%d",&a.s);
			a.t=time;
			n[++tail].s=a.s;
			n[tail].t=a.t;
			if(b[a.s]==0) ans++;
			b[a.s]++;
		}
		while(time-n[head].t>=86400)
		{
			b[n[head].s]--;
			if(b[n[head].s]==0) ans--;
			head++;
		}
		printf("%d\n",ans);
	}
}
