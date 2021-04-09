#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
using namespace std;
int prime[100000];
bool notprime[100000000];
void findprime(int maxn)
{
	 for (int i = 2; i <= sqrt(maxn); ++i) 
	 { 
        if (notprime[i]) continue;
        for (int j = i + i; j < maxn; j += i)
           notprime[j] = true;
    }
}
string to_string(int a)
{
	string s;
	s.clear();
	int i=0;
	while(a!=0)
	{
		s[i]=a%10;
		a/=10;
	}
	return s;
} 
 bool ok(int k)   //???
{
   int a[10],i=0;     
   while (k>0){a[i]=k%10;k/=10;i++;}
   for(int j=0;j<i;j++)if(a[j]!=a[i-j-1])return false;   
   return true;     
}

int main()
{
	freopen("biao.x","w",stdout);
	findprime(100000000);
	int x=0; 
	for(int i=0;i<100000000;i++)
	{
		if(!notprime[i]) prime[x++] = i;
	}
	for(int i=0;i<x;i++)
	{
		if(ok(prime[i]))
			printf("%d,",prime[i]);
	}
}
