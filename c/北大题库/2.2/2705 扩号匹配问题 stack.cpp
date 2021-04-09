#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,L;
	char a[101],b[101];
	while(scanf("%s",a)!=EOF) 
	{
		for(i=0;i<strlen(a);i++)
		{
			
			stack<char>S;
			if(a[i]=='(')
			{
				S.push(i);
				b[i]=' ';
			}
			else if(a[i]==')')
			{
				if(S.empty())
				{
					S.pop();
				}
				else 
				{
					b[i]='?';
				}
			}
			else
			{
				b[i]=' ';
			}
		}
		while(!S.empty())
		{
			b[S.top()]='$';
			S.pop();
		}
		b[i]='\0';
		printf("%s\n",a);
		printf("%s\n",b);
	}
	return 0;
}
