#include<stdio.h>
#include<math.h>
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
        anss[0]='e';
        anss[1]='^';
        anss[2]='x';
        printf("%s",anss);
    }
    else if(a[0]=='s'&&a[1]=='i'&&a[2]=='n'&&n==1)
    {
        anss[0]='c';
        anss[1]='o';
        anss[2]='s';
        anss[3]='(';
        anss[4]='x';
        anss[5]=')';
        printf("%s",anss);
    }
    else if(a[0]=='s'&&a[1]=='i'&&a[2]=='n'&&n==2)
    {
        anss[0]='-';
        anss[1]='s';
        anss[2]='i';
        anss[3]='n';
        anss[4]='(';
        anss[5]='x';
        anss[6]=')';
        printf("%s",anss);
    }
    else if(a[0]=='c'&&a[1]=='o'&&a[2]=='s'&&n==1)
    {
        anss[0]='-';
        anss[1]='s';
        anss[2]='i';
        anss[3]='n';
        anss[4]='(';
        anss[5]='x';
        anss[6]=')';
        printf("%s",anss);
    }
    return 0;
} 

