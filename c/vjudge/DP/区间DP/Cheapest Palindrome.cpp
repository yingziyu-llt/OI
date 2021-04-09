#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n,m,q[10010],f[2100][2100];
char a[2100];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",a + 1);
	for(int i = 0;i < n;i++)
	{
		char s[10];
		scanf("%s",s);
		int x,y;
		scanf("%d%d",&x,&y);
		q[s[0] - 'a'] = min(x,y);
	}
	for(int l = 2;l <= m;l++)
	{
		for(int i = 1;i + l - 1 <= m;i++)
		{
			int j = i + l - 1;
			if(a[i] == a[j]) f[i][j] = f[i + 1][j - 1];
			else f[i][j] = min(f[i][j - 1] + q[a[j] - 'a'],f[i + 1][j] + q[a[i] - 'a']);
		}
	}
	printf("%d",f[1][m]);
	return 0;
}