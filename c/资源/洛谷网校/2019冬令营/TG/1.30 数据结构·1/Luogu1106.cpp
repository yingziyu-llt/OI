#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#define ll long long
#define INF 1000000000
#define clr(x) memset(x,0,sizeof(x))
#define maxclr(x) memset(x,0x3f,sizeof(x))

using namespace std;

inline int read()
{
	register int ret=0,c=getchar(),b=1;
	while(!isdigit(c))b=c=='-'?-1:1,c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret*b;
}

#define M 1005

int k,n,a[M],S[M],b[M],h,p;
char s[M]; 

int main()
{
	while(scanf("%s %d",s+1,&k)!=EOF)
	{
		clr(b);clr(S);h=0;p=1;
		n=strlen(s+1); 
		for(int i=1;i<=n;i++)a[i]=s[i]-'0';
		for(int i=1;i<=n;i++)
		{
			while(k&&h&&a[i]<S[h])
				h--,k--;
			S[++h]=a[i];
		}
		while(k&&h)k--,h--;
		while(S[p]==0&&p<=h)p++;
		if(h==0||p==h+1) putchar('0');
		for(int i=p;i<=h;i++)
			printf("%d",S[i]);
		puts("");
	}
	return 0;
}
