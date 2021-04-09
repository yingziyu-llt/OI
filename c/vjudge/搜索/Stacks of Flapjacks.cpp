#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<sstream>
#include<string.h>
using namespace std;
int a[100],b[100];
int len = 0;
void fip(int p)
{
	int from = p,pos = len;
	for(int i = p;i <= (from + len) / 2;i++)
	{
		swap(b[i],b[pos]);
		pos--;
	}
}
bool check()
{
	int minn = b[1];
	for(int i = 2;i <= len;i++)
		if(b[i] < minn)
			return false;
	return true;
}
int main()
{
	stringstream ss;
	while(1)
	{
		ss.clear();
		string str;
		len = 0;
		int x;
		getline(cin,str);
		if(str[0] == '\0') break;
		ss << str;
		while(ss >> x)
			a[++len] = x;
		printf("%d",a[1]);
		for(int i = 2;i <= len;i++)
			printf(" %d",a[i]);
		printf("\n");
		memcpy(b,a,sizeof(a));
		sort(a + 1,a + 1 + len);
		int cnt = len;
		for(int i = 1;i <= len;i++)
		{
			int x = a[cnt--];
			bool flag = false;
			for(int j = i;j < len;j++)
			{
				if(b[i] == x)
				{
					printf("%d ",j);
					fip(j);
					if(check())
					{
						flag = true;
						break;
					}
					fip(i);
					printf("%d ",i);
				}
			}
			if(flag) break;
		}
		printf("0\n");
	}
}