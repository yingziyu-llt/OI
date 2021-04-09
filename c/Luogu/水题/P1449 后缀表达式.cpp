#include<stdio.h>
#include<stack>
using namespace std;
stack <int> s;
int main()
{
	char a[10000];
	scanf("%s",a);
	int num = 0;
	int i = 0;
	bool flag = true;
	while(a[i]!='\0')
	{
		num = 0;
		flag = true;
		while(a[i]>='0'&&a[i]<='9')//处理字符串，提取数字 
		{
			if(a[i]>='0'&&a[i]<='9')
				num = (num << 3) + (num << 1) + a[i] - '0';
			flag = false;
			i++;
		}
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')//为符号 
		{
			int x,y;
			switch (a[i])
			{
				case '+' :
					{
						x = s.top();
						s.pop();
						y = s.top();
						s.pop();
						s.push(x+y);
						i++;
						break;
					}
					case '-' :
					{
						x = s.top();
						s.pop();
						y = s.top();
						s.pop();
						s.push(y-x);
						i++;
						break;
					}
					case '*' :
					{
						x = s.top();
						s.pop();
						y = s.top();
						s.pop();
						s.push(x*y);
						i++;
						break;
					}
					case '/' :
					{
						x = s.top();
						s.pop();
						y = s.top();
						s.pop();
						s.push(y/x);
						i++;
						break;
					}
			};
		}
		else if(a[i] == '.')
		{
			i++;
			s.push(num);
		}
			
		else if(a[i] == '@')
			break;
	}
	printf("%d",s.top());
}
