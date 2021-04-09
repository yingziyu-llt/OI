#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef double db;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x*f;
}
const int MAXN=1e5+10;
int n;
char a[MAXN];
int main()
{
    gets(a+1);
    n=strlen(a+1);
    int l=1;
    for(int i=1;i<=n;++i)
    {
        if(a[i]=='.'||i==n)
        {
            bool flag=true;
            for(int j=l;j<=i;++j)
            {
                if(a[j]>='a'&&a[j]<='z')
                {
                    if(flag)printf("%c",a[j]-'a'+'A'),flag=false;
                    else printf("%c",a[j]);
                }
                else if(a[j]>='A'&&a[j]<='Z')
                {
                    if(flag)printf("%c",a[j]),flag=false;
                    else printf("%c",a[j]-'A'+'a');
                }
                else printf("%c",a[j]);
            }
            l=i+1;
        }
    }
    return 0;
}
