#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
struct node
{
	int pourcnt,step,pcnt[5];
	bool operator < (node x) const
	{
		return pourcnt < x.pourcnt;
	}
};
priority_queue <node> q;
int fromto[10][3] = {{0,1,2},{0,1,3},{0,2,3},{0,2,1},{0,2,3},{0,3,1},{0,3,2}};
int minn[210][210],dd[10010];
int main()
{
	int t;
	scanf("%d",&t);
	int pcnt[10],d;
	while(t--)
	{
		memset(minn,0x3f,sizeof(minn));
		scanf("%d%d%d%d",&pcnt[1],&pcnt[2],&pcnt[3],&d);
		node xx;
		xx.pcnt[1] = 0,xx.pcnt[2] = 0,xx.pcnt[3] = pcnt[3],xx.pourcnt = 0,xx.step = 0;
		dd[pcnt[3]] = 0;
		q.push(xx);
		for(int i = 0;i < 10010;i++)
			dd[i] = 0x7fffffff;
		while(!q.empty())
		{
			xx = q.top();
			q.pop();
			for(int i = 0;i < 6;i++)
			{
				node xxcpy = xx;
				int detla = pcnt[fromto[i][2]] - xxcpy.pcnt[fromto[i][2]];
				xxcpy.pcnt[fromto[i][1]] -= detla;
				if(xxcpy.pcnt[fromto[i][1]] < 0)
				{
					detla = xxcpy.pcnt[fromto[i][1]] + detla;
					xxcpy.pcnt[fromto[i][1]] = 0;
				}
				xxcpy.pcnt[fromto[i][2]] += detla;
				xxcpy.pourcnt += detla;
				if(minn[xxcpy.pcnt[1]][xxcpy.pcnt[2]] > xxcpy.pourcnt)
				{
					minn[xxcpy.pcnt[1]][xxcpy.pcnt[2]] = xxcpy.pourcnt;
					dd[xxcpy.pcnt[1]] = min(dd[xxcpy.pcnt[1]],xxcpy.pourcnt);
					dd[xxcpy.pcnt[2]] = min(dd[xxcpy.pcnt[2]],xxcpy.pourcnt);
					dd[xxcpy.pcnt[3]] = min(dd[xxcpy.pcnt[3]],xxcpy.pourcnt);
					q.push(xxcpy);
				}
			}
		}
		for(int i = 0;i < 10010;i++)
		{
			if(dd[max(d - i,0)] != 0x7fffffff)
			{
				printf("%d %d\n",dd[d - i],d + i);
				break;
			}
		}
	}
	return 0;
}