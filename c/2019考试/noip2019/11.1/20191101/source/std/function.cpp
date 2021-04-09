#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch<='9'&&ch>='0')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
	return;
}
typedef long long LL;
const LL P=1e9+7;
LL ksm(LL a,LL b)
{
	LL r=1;
	while(b!=0)
	{
		if(b&1)r=r*a%P;
		a=a*a%P;
		b>>=1;
	}
	return r;
}
int main()
{
	int T;
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	LL n,m;
	read(T);
	while(T--)
	{
		read(n);read(m);
		if(m==1){printf("1\n");continue;}
		if(n&1)printf("%lld\n",(2*ksm(ksm(2,n)-1,m-1)%P+1)*ksm(3,P-2)%P);
		else printf("%lld\n",2*ksm(ksm(2,n)-1,m-1)%P*ksm(3,P-2)%P);
	}
	return 0;
}
