#include<bits/stdc++.h>
using namespace std;
bool f,end;
long long scan()
{
	long long temp;
	char ch = getchar();
	temp = 0;
	while(ch > '9' || ch < '0') 
	{
		ch = getchar();
		if(ch == EOF) return -1;
		if(ch == '\n') f = true;
	}
	while(ch >= '0' && ch <= '9')
	{
		temp = temp * 10 + ch -'0';
		ch = getchar();
		if(ch == '\n') f = true;
	}
	return temp;
}

int main()
{
	freopen("1ol.in","r",stdin);
	freopen("1ol.out","w",stdout);
	while(1)
	{
		long long i,j,k;
		i = j = k = 0;
		f = false;
		while(1)
		{
			k++;
			long long a;
			a = scan();
			if(k % 2 == 0) i = i + a;
			else j = j + a;
			if(f == true) break;
			if(a == -1) return 0;		
		}
		if(i < j) swap(i,j);
		printf("%lld %lld",i,j);
		if(i == j) printf(" Draw\n");
		else if(i > j) printf(" Win\n");	
	}
}		 
