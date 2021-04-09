#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 110000;
int d[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&d[i]);
	int now = d[0],ans = 0;
	for(int i = 1;i < n;i++)
	{
		if(d[i - 1] > d[i])
		{
			ans += now - d[i];
			now = d[i];
		}
	}
	printf("%d",ans);
	return 0;
}