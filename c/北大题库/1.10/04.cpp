#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct aa
{
	int ch,ma,eng;
	int s;
	int xi;
}s[311];
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d",&s[i].ch,&s[i].ma,&s[i].eng);
		s[i].s=s[i].ch +s[i].eng +s[i].ma;
	}
	for(i=1;i<=n;i++)  s[i].xi=i;
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(s[i].s<s[j].s)
			{
				swap(s[i],s[j]);
			}
			else if(s[i].s==s[j].s&&s[i].ch<s[j].ch)
			{
				swap(s[i],s[j]);
			}
			else if(s[i].s==s[j].s&&s[i].xi>s[j].xi&&s[i].ch==s[j].ch)  swap(s[i],s[j]);
		}
	}
	for(i=1;i<=5;i++)
	{
		printf("%d %d\n",s[i].xi,s[i].s);
	}
	return 0;
}
