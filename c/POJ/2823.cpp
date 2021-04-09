#include<stdio.h>
#include<queue>
using namespace std;
deque <int> q;
int a[1100000];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	q.push_back(a[1]);
	for(int i = 2;i <= n + 1;i++)
	{
		if(i > k) printf("%d ",q.front());
		if(i > n) break;
		if(i > k && q.front() == a[i - k + 1]) q.pop_front();
		while(!q.empty() && q.back() >= a[i])
			q.pop_back();
		q.push_back(a[i]);
	}
	printf("\n");
	q.clear();
	q.push_back(a[1]);
	for(int i = 2;i <= n + 1;i++)
	{
		if(i > k) printf("%d ",q.front());
		if(i > n) break;
		if(i > k && q.front() == a[i - k + 1]) q.pop_front();
		while(!q.empty() && q.back() <= a[i])
			q.pop_back();
		q.push_back(a[i]);
	}
	return 0;
}