#include<queue>
#include<stdio.h>
#include<string.h>
using namespace std;
struct node
{
	int num,timex,t;
	bool operator < (const node &a) const
	{
		if(timex == a.timex) return num > a.num;
		return timex > a.timex;
	}
}n;
priority_queue <node> q;
int main()
{
	freopen("argus.in","r",stdin);
	freopen("argus.out","w",stdout);
	char s[1000];
	int count = 0;
	while(~ scanf("%s",s))
	{
		if(strcmp(s,"#") == 0)
			break;
		memset(s,0,sizeof(s));
		scanf("%d%d",&n.num,&n.timex);
		n.t = n.timex;
		q.push(n);
	}
	scanf("%d",&count);
	for(int i = 0;i < count;i++)
	{
		printf("%d\n",q.top().num);
		n = q.top();
		q.pop();
		n.timex += n.t;
		q.push(n);
	}
	return 0;
}