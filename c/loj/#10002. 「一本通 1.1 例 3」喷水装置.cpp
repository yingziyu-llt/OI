#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
struct line
{
	int l,r;
}s[15010];
bool li[1000010];
bool cmp(line a,line b) 
{
	return a.r < b.r;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	for(int _i = 0;_i < t;_i++)
	{
		memset(li,0,sizeof(li));
		int n,l,w;int ans = 0;
		memset(s,0,sizeof(s));
		scanf("%d%d%d",&n,&l,&w);
		for(int i = 0;i < n;i++)
		{
			int y,r;
			scanf("%d%d",&y,&r);
			if(r < (float)w / 2.0) continue; 
			double c = sqrt((double)r * (double)r - (double)w / 2.0 * (double)w / 2.0);
			s[i].l = r - c;
			s[i].r = r + c;
		}
		sort(s,s + n,cmp);
		bool x = true;
		for(int i = 1;i <= l;i++)
		{
			bool pd = false;
			for(int j = 0;j < n;j++)
			{
				if(i >= s[j].l)
				{
					ans++;
					i = s[i].r;
					pd = true;
					break;
				}
			}
			if(!pd) 
		}
		if(x)
			printf("%d\n",ans);
	}
}

