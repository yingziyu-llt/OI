#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
//¥ÀÃ‚Œ¥AC 
long long a[100000],b[100000];
int fir=0
bool isprime(long long x)
{
	for(long long i=2;i<x;i++)
	{
		if(x%i==0) return false;
	}
	return true;
}
void x(int a[100000],int i)
{
	for(;i<100000;i++)
	{
		for(long long j=2;j<a[i];j++)
		{
			if(a[i]%j==0) 
			{
				a[fir]=j;
				a[i]/=j;
				fir++;
				
			}
		}
	}
}
int main()
{
	int t;
	scanf("%lld",&t);
	for(int k1=0;k1<t;k1++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		long long n,m,i;
		scanf("%lld %lld",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]==1)
			{
				a[i]=0;
				i--;
			}
		}
			
		long long lena=i+1;
		for(i=0;i<m;i++)
		{
			scanf("%lld",&b[i]);
			if(b[i]==1)
			{
				b[i]=0;
				i--;
			}
		}
		long long lenb=i+1;
		sort(a,a+lena-1);
		sort(b,b+lenb-1);
		long long tmp=0;
		for(long long j=0;a[j]!=0;)
		{
			long long l=tmp,r=lena-1;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(b[mid]==a[j])
				{
					b[mid]=0;
					lenb--;
					a[j]=0;
					lena--;
					sort(b,b+lenb-1);
					tmp++;
					break;
				}
				if(b[mid]>a[j]) r=mid;
				if(b[mid]<a[j]) l=mid+1;
			}
			j++;
		}
		if(lena-1>=2||lenb-1>=2)	
		{
			printf("NO\n");continue;
		}
		bool flag=false;
		for(long long j=2;j<a[tmp];j++)
		{
			if(a[tmp]%j==0)
			{
				flag=true;
				break;
			}
		}
		if(flag) printf("NO\n");
		else     printf("YES\n");
	}
	return 0;
} 
