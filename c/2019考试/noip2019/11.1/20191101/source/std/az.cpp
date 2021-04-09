#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<iostream>
#define ll long long 
using namespace std;
template<class T>void read(T &x){
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
    while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return ;
}
set< map< char , int > > k;
map< char , int > vis;
int n;
char a[200];
int main()
{
	freopen("az.in","r",stdin);
	freopen("az.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i)
	{
		vis.clear();
		scanf("%s",a+1);
		int len=strlen(a+1);
		for(int j=1;j<=len;++j)
		vis[a[j]]++;
		k.insert(vis);
	}
	printf("%d",k.size());
	return 0; 
}
