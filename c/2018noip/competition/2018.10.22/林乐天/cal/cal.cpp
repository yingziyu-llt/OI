#include <stdio.h>
#include <stack>
#include <queue>
#include <string.h>
#include <iostream>
using namespace std;
stack<double> s1, s2;
stack<char> s3, s4;
int main()
{
	freopen("cal.in","r",stdin);
	freopen("cal.out","w",stdout);
	char c[1000];
	double n = 0;
	while (gets(c))
	{
		if (c[0] == '0' && c[1] == '\0')
			return 0;
		int len = strlen(c);
		bool next_plus = false;
		bool next_plusx = false;
		while (!s2.empty())
			s2.pop();
		while (!s1.empty())
			s1.pop();
		for (int i = 0; i < len; i++)
		{
			if (c[i] == ' ')
				continue;
			if (c[i] >= '0' && c[i] <= '9')
				n = n * 10 + c[i] - '0';
			else
			{
				if (next_plus)
				{
					double x = s1.top();
					s1.pop();
					s1.push(x * n);
					n = 0;
					next_plus = false;
					if (c[i] == '*')
						next_plus = true;
					else if (c[i] == '/')
						next_plusx = true;
					else
						s3.push(c[i]);
					n = 0;
				}
				else if (next_plusx)
				{
					double x = s1.top();
					s1.pop();
					s1.push(x / n);
					n = 0;
					next_plusx = false;
					if (c[i] == '*')
						next_plus = true;
					else if (c[i] == '/')
						next_plusx = true;
					else
						s3.push(c[i]);
				}
				else if (c[i] == '+' || c[i] == '-')
				{
					s1.push(n);
					s3.push(c[i]);
					n = 0;
				}
				else
				{
					s1.push(n);
					if (c[i] == '*')
						next_plus = true;
					else if (c[i] == '/')
						next_plusx = true;
					n = 0;
				}
			}
		}
		if (next_plus)
		{
			double x = s1.top();
			s1.pop();
			s1.push(x * n);
			n = 0;
			next_plus = false;
		}
		else if (next_plusx)
		{
			double x = s1.top();
			s1.pop();
			s1.push(x / n);
			n = 0;
			next_plusx = false;
		}
		else
		{
			s1.push(n);
		}
		while (!s1.empty())
			s2.push(s1.top()), s1.pop();
		while (!s3.empty())
			s4.push(s3.top()), s3.pop();
		while (!s4.empty())
		{
			double x = s2.top();
			s2.pop();
			double x2 = s2.top();
			s2.pop();
			if (s4.top() == '+')
				s2.push(x + x2);
			else
				s2.push(x - x2);
			s4.pop();
		}
		printf("%.2lf\n", s2.top());
		s2.pop();
		n = 0;
		memset(c, 0, sizeof(c));
	}
	return 0;
}
