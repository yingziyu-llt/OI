#include <stdio.h>
int a[100005],n,pos[100005],num,i;
bool vis[100005];
int main()
{
 freopen("wa.in","r",stdin);
 freopen("wa.out","w",stdout);
 scanf("%d",&n);
 num=n/2;
 for(i=1;i<=n;i++) 
 {
    scanf("%d",&a[i]);
	pos[a[i]]=i;	
 }  
 int t=n;
 for(;num;)
 {
    while(vis[t]||t==a[n])
	  t--;
    for(i=pos[t]+1;i<=n;i++)
	  if(!vis[a[i]])break;
    if(i==n+1) 
    {
	  t--;
	  continue;
    }
    vis[t]=1;
    vis[a[i]]=1;
    printf("%d %d ",t,a[i]);
    num--;
 }
return 0;
}
