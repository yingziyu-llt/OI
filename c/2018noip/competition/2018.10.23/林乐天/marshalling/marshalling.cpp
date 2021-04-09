#include <stdio.h>
struct stack
{
	int s[110];
	int head;
	bool empty() { return head == 0; }
	int top() { return s[head]; }
	void clean() { head = 0; }
	void pop() { head--; }
	void push(int a) { s[++head] = a; }
} s1;
int main()
{
	freopen("marshalling.in","r",stdin);
	freopen("marshalling.out","w",stdout);
	int arr[1000];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int k = 0;
	s1.clean(); 
	for (int i = 1; i <= n; i++)
	{
		while(s1.top() == arr[k])
		{
			printf("B");
			s1.pop();
			k++;
		}
		s1.push(i);
		printf("A");
	}
	while(!s1.empty())	printf("B"),s1.pop();
	return 0;
}
