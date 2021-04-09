#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
char a[100005];
int l;
int main()
{
    freopen("nigeru.in","r",stdin);
    freopen("nigeru.out","w",stdout);
    gets(a);
    l=strlen(a);
    for(int i=0;i<l;i++) 
    {
        if(a[i]<='Z'&& a[i]>='A') a[i]+=32;
    }
    int t=0;
    while(t<l)
    {
        while((a[t]<'a' || a[t]>'z') && t<l)
        {
            printf("%c",a[t]);
            t++;
        }
        if(t<l)
        {
            printf("%c",a[t]-32);t++;
        }
        else break;
        while(((a[t]<='z' && a[t]>='a') || a[t]==' ') && t<l) 
        {
            printf("%c",a[t]);
            t++;
        }
    }
    return 0;
}