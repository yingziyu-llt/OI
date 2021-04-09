#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct Node
{
	int nxt,date,pre;
}node[1100];
int por[1100];
bool avaliable[1100];
int main()
{
	freopen("wa.in","r",stdin);
	freopen("wa.out","w",stdout);
	int n;
	scanf("%d",&n);
	int finaln = 0;
	for(int i = 1;i <= n;i++)
	{
		int x = 0;
		scanf("%d",&x);
		node[i].date = x;
		node[i - 1].nxt = i;
		node[i].pre = i - 1;
		por[x] = i;
		avaliable[x] = true;
		finaln = x;
	}
	avaliable[finaln] = false;
	for(int i = n;i >= 1;i --)
	{
		if(avaliable[i] && (avaliable[node[node[por[i]].nxt].date] || node[por[i]].nxt == n))
		{
			int pos = por[i];
			node[node[pos].pre].nxt = node[node[pos].nxt].nxt;
			node[node[node[pos].nxt].nxt].pre = node[pos].pre;
			avaliable[node[pos].date] = false;
			avaliable[node[node[pos].nxt].date] = false;
			printf("%d %d ",node[pos].date,node[node[pos].nxt].date);
		}
	}
	return 0;
}