#include<stdio.h>
#include<algorithm>
using namespace std;
struct obj
{
	int val,t;
}act[10010];
int hash[600];
bool cmp(obj a,obj b)
{
	return a.val > b.val;
}
int main()
{
	int m,n;
	int tot = 0;
	scanf("%d%d",&m,&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&act[i].t);
	for(int i = 0;i < n;i++)
		scanf("%d",&act[i].val);
	sort(act,act + n,cmp);
	for(int i = 0;i < n;i++)
	{
		bool b = true;
		for(int j = act[i].t;j > 0;j--)
			if(hash[j] == 0)
			{
				hash[j] = 1;
				b = false;
				break;
			}
		if(b)
			tot += act[i].val;
	}
	printf("%d",m - tot);
	return 0;
} 
