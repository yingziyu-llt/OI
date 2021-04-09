#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define h1 (233317)
unsigned long long hashnum[10000];
unsigned long long hashf(char s[])
{
	int i = 0,len = strlen(s);
	unsigned long long ans = 0;
	while(i < len)
		ans = ans * h1 + s[i++];
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	char s[100000];
	unsigned long long k;
	for(int i = 0;i < n;i++)
	{
		scanf("%s",s);
		k = hashf(s);
		hashnum[i] = k;
	}
	sort(hashnum,hashnum + n);
	int tot = 0;
	for(int i = 0;i < n;i++)
	{
		if(hashnum[i] != hashnum[i + 1])
			tot++;
	}
	printf("%d",tot);
	return 0;
}