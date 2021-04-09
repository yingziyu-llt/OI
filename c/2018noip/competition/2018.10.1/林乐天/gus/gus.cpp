#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    freopen("gus.in","r",stdin);
    freopen("gus.out","w",stdout);
    int n,m;
    int ans = 0;
    bool way = true;
    scanf("%d%d",&n,&m);
    while(n > 0 || m > 0)
    {
    	if(n == 1||m == 1)
    	{
    		ans++;
    		break;
    	}
        if(way) n--;
        else    m--;
        way = !way;
        ans++;
    }
    printf("%d",ans);
    return 0;
}