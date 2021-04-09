#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXN=1010;
int a[MAXN],b[MAXN];
int main()
{
	freopen("fantasy.in","r",stdin);
	freopen("fantasy.out","w",stdout);
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<n;i++)scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        int al=0,ah=n-1;
        int bl=0,bh=n-1;
        int ans=0;
        while(al<=ah&&bl<=bh)
        {
            if(a[al]>b[bl])
            {
                ans++;
                al++;bl++;
            }
            else if(a[al]<b[bl])
            {
                ans--;
                al++;bh--;
            }
            else
            {
                if(a[ah]>b[bh])
                {
                    ans++;
                    ah--;bh--;
                }
                else if(a[ah]<b[bh])
                {
                    ans--;
                    al++;bh--;
                }
                else
                {
                    if(a[al]<b[bh])
                    {
                        ans--;
                        al++;bh--;
                    }
                    else if(a[al]==b[bh])//所有的都一样了
                    {
                        break;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
