#include<stdio.h>
#include<math.h>
#include<set>
using namespace std;
bool chosen[10000];
int a[100000];
int ans,n;

bool isPrime(int x)
{
	if(x==0) return false;
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return false;
	}
	return true;
}

void dfs(int k,int chose,int sum,int start)
{
	sum+=a[chose];
	if(k==0)
	{
		if(isPrime(sum))
		{
			ans++;
			return ;
		}
	}	
	else
	{
		for(int i=start;i<n;i++)
		{
			if(chosen[i] == false)
			{
				chosen[i]=true;
				dfs(k-1,i,sum,i);
				chosen[i]=false;
			}
		}
	}
}			

int main()
{
	int x;
	scanf("%d%d",&n,&x);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		chosen[i]=true;
		dfs(x-1,i,0,i);
		chosen[i]=false;
	}
		
	printf("%d",ans);
}
