#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const long long N = 510000;
char s[N];
struct Edge
{
	long long nxt,to;
}e[N];
long long f[N];
long long eHead[N],ecnt,fa[N],stack[N];
void addEdge(long long from,long long to)
{
	ecnt++;
	e[ecnt].to = to;
	e[ecnt].nxt = eHead[from];
	eHead[from] = ecnt;
}
long long ans;
void dfs(long long u,long long pre,long long top)
{
	long long flag = 0;
	if(s[u] == '(')
	{
		stack[++top] = u;
	}
	else
	{
		if(!top) f[u] = 0;
		else
		{
			flag = stack[top];
			f[u] = f[fa[stack[top]]] + 1;
			pre += f[u];
			--top;
		}
 	}
	ans ^= (u * pre);
	for(long long i = eHead[u];i;i = e[i].nxt)
		dfs(e[i].to,pre,top);
	if(flag) stack[++top] = flag;
}
int main()
{
	long long n;
	scanf("%lld",&n);
	scanf("%s",s + 1);
	for(long long i = 2;i <= n;i++)
	{
		long long x,y;
		scanf("%lld",&x);
		fa[i] = x;
		addEdge(x,i);
	}
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}