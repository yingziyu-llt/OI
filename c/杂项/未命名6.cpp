#include<bits/stdc++.h>
using namespace std;
char a[10010],anss[1010];
int main()
{
    int n,ans;
    scanf("%d%s",&n,a);
    if(a[0]=='x')
    {
        ans=(int)pow((int)a[1],n-1);
        printf("%d",ans);
    }
    else if(a[0]>='0'&&a[0]<='9')
    {
        ans=0;
        printf("%d",ans);
    }
    else if(a[0]=='e'&&a[1]=='^'&&a[2]=='x')
    {
        anss={'e','^','x'};
       printf("%d",anss);
    }
    else if(a[0]=='s'&&a[1]=='i'&&a[2]=='n'&&n==1)
    {
        anss={'c','o','s','(','x',')'};
        printf("%d",anss);
    }
    else if(a[0]=='s'&&a[1]='i'&&a[2]=='n'&&n==2)
    {
        anss={'-','s','i','n','(','x',')'};
        printf("%d",anss);
    }
    else if(a[0]=='c'&&a[1]=='o'&&a[2]=='s'&&n==1)
    {
        anss={'-','s','i','n','(','x',')'};
        printf("%d",anss);
    }
    return 0;
} 
