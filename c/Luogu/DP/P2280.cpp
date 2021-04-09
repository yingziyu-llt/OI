#include<stdio.h>
#include<string.h>

#include<algorithm>
using namespace std;

int tot[5050][5050];

void read(int &n)
{
    char c='+';int x=0;bool flag=0;
    while(c<'0'||c>'9'){c=getchar();if(c=='-')flag=1;}
    while(c>='0'&&c<='9')
    {x=x*10+c-48;c=getchar();}
    flag==1?n=-x:n=x;
}

int main()
{
	int n,r;
	read(n);read(r);
	for(int i = 0;i < n;i++)
	{
		int x, y, val;
		read(x);read(y);read(val);
		tot[x + 1][y + 1] = val;
	}
	for(int i = 1;i < 5005;i++)
	{
		for(int j = 1;j < 5005;j++)
		{
			tot[i][j] = tot[i][j] + tot[i - 1][j] + tot[i][j - 1] - tot[i - 1][j - 1];
		}
	}
	int ans = -1;
	for (int i = 0; i <= 5001 - r; i++)
		for (int j = 0; j <= 5001 - r; j++)
			ans = max(ans, tot[i + r][j + r] - tot[i + r][j] - tot[i][j + r] + tot[i][j]);
	printf("%d",ans);
	return 0;
}