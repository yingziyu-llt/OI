#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 110000;
int positionInA[N];
int g[N];
int a[N],b[N],f[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		positionInA[a[i]] = i;
	}
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&b[i]);
		f[i] = 0x7fffffff;
	}
	f[0] = 0;
	int len = 0;
	for(int i = 1;i <= n;i++)
	{
		int l = 0,r = len,mid;
		if(positionInA[b[i]] > f[len]) f[++len] = positionInA[b[i]];
		else
		{
			while(l < r)
			{
				mid = (l + r) / 2;
				if(f[mid] > positionInA[b[i]]) r = mid;
				else l = mid + 1;
			}
			f[l] = min(positionInA[b[i]],f[l]);
		}
		
	}
	printf("%d",len);
	return 0;
}