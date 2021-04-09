#include<cstdio>
#include<cstring>
#include<algorithm>
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
const int size=2;
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
struct matrix
{
	LL f[size+1][size+1];
	matrix(LL x=0)
	{
		memset(f,0,sizeof(f));
		if(x!=0)for(int i=1;i<=size;i++)f[i][i]=x;
	}
	LL* operator [](int i)
	{
		return f[i];
	}
	matrix operator *(const matrix &A)
	{
		matrix tmp=matrix(0);
		for(int i=1;i<=size;i++)
			for(int j=1;j<=size;j++)
				for(int k=1;k<=size;k++)
					tmp[i][j]=(tmp[i][j]+f[i][k]*A.f[k][j])%P;
		return tmp;
	}
	matrix operator ^(LL k)
	{
		matrix r=matrix(1),tmp=(*this);
		while(k!=0)
		{
			if(k&1)r=r*tmp;
			tmp=tmp*tmp;
			k>>=1;
		}
		return r;
	}
}ans,base;
void solve(LL n)
{
	ans[1][1]=1;ans[1][2]=1;
	base[1][1]=1;base[2][1]=2;base[1][2]=1;base[2][2]=0;
	ans=ans*(base^(n-2));
}
int main()
{
	int T;
	LL n,m;
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	read(T);
	while(T--)
	{
		read(n);read(m);
		if(m==1)
		{
			printf("1\n");
			continue;
		}
		if(n&1)
		{
			solve(n+1);
			matrix tmp;
			tmp[1][1]=ans[1][1];
			solve(n);
			tmp[1][2]=ans[1][1]-1;
			base[1][1]=ksm(2,n)-1;base[2][1]=-1;
			base[1][2]=0;base[2][2]=1;
			tmp=tmp*(base^(m-2));
			printf("%lld\n",(tmp[1][1]+P)%P);
		}
		else 
		{
			solve(n+1);
			printf("%lld\n",(ans[1][1]-1)*ksm(ksm(2,n)-1,m-2)%P);
		}
	}
	return 0;
}
