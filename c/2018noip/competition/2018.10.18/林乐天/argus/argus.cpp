#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int que[100000];
struct people
{
	int qnum;
	int period;
} p[10000];
bool cmp(people a, people b)
{
	return a.qnum < b.qnum;
}
int main()
{
	freopen("argus.in","r",stdin);
	freopen("argus.out","w",stdout);
	int n = 0, k;
	char command[100];
	while (true)
	{
		scanf("%s", command);
		if (strcmp(command, "#") == 0)
			break;
		scanf("%d%d", &p[n].qnum, &p[n].period);
		n++;
	}
	sort(p, p + n, cmp);
	scanf("%d",&k);
	int i = 0;
	while(i < n)
	{
		que[i] = p[i].period;
		i++;
	}
	i = 0;
	while(i < k)
	{
		int minm = que[0];
		for(int j = 0;j < n;j++)
			if(minm > que[j])
				minm = que[j];
		for(int j = 0;j < n;j++)
		{
			que[j] -= minm;
			if(i >= k) break;
			if(que[j] == 0)
			{	
				if(i == k) break;
				printf("%d\n",p[j].qnum);
				que[j] = p[j].period;
				i++;
			}
		}
	}
	return 0;
}