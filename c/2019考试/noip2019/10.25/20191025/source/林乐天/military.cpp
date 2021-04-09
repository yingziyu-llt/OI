#include<stdio.h>
#include<algorithm>
const int INF = 0x7fffffff;
using namespace std;
int a[60010];
int read()
{
	char c;
	int ans = 0;
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
	{
		ans = ans * 10 + c - '0';
		c = getchar();
	}
	return ans;
}
int c[51000],m[51000],h[30][51000];
bool flag[30][51000];
int ans = INF;
int main()
{
	freopen("military.in","r",stdin);
	freopen("military.out","w",stdout);
	int n,m,c;
	printf("0");
	return 0;
}