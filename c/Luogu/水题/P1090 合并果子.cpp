#include<queue>
#include<stdio.h>
using namespace std;
struct node
{
	int n;
	bool operator <(const node &a)const
	{
		return a.n < n;
	}
}no;
priority_queue<node>q;
int main()
{
	int n;
	int tot = 0;
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d",&no.n);
		q.push(no);
	}
	while (q.size() > 1)
	{
		no = q.top();
		q.pop();
		int x = no.n;
		no = q.top();
		q.pop();
		no.n += x;
		tot += no.n;
		q.push(no);
	}
	printf("%d",tot );
	return 0;
}