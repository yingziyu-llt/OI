#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;
stack<long long> s;
long long a[110000];
int main()
{
	while (1)
	{
		while (!s.empty())
		{
			s.pop();
		}
		long long n;
		scanf("%lld", &n);
		if (!n)
			break;
		for (long long i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		long long ans = -1;
		for (long long i = 1; i <= n; i++)
		{
			while (!s.empty() && s.top() >= a[i])
				s.pop();
			long long len = 1;
			long long k = i;
			while (a[k - 1] >= a[k])
				len++, k--;
			ans = max(ans,len * a[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}