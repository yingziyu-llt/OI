#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct aa
{
	char s[200];
	int len;
	int num;
}p[100];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%s",p[i].s);
		p[i].num = i;
		p[i].len = strlen(p[i].s);
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			if(p[i].len > p[j].len) swap(p[i],p[j]);
			else if(p[i].len == p[j].len &&strcmp(p[i].s,p[j].s) > 0) swap(p[i],p[j]);
		}
	}
	printf("%d\n%s",p[0].num+1,p[0].s);
	return 0;
}
