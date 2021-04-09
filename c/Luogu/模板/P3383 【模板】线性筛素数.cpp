#include<stdio.h>
#include<string.h>
bool isprime[10000010];
inline int read()
{
    char c = getchar(); register int x = 0;
    while (c > '9' || c < '0')c=getchar();
    while (c <= '9' && c >= '0') x = (x << 3) + (x << 1) + c - 48,c = getchar();
    return x;
}
int main()
{
	int n,m;
	n = read();
	m = read();
	memset(isprime,true,sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for(int i = 2;i * i <= n;i++)
	{
		if(isprime[i] == false) continue;
		for(int j = 2;i * j <= n;j++)
			isprime[i * j] = false;
	}
	for(int i = 0;i < m;i++)
	{
		int x;
		x = read();
		if(isprime[x]) printf("Yes\n");
		else		   printf("No\n");
	}
	return 0;
} 
