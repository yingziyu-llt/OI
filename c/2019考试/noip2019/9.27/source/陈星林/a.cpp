#include <stdio.h>
#include <algorithm>
using namespace std;
int a[205],b[205];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
 int t,i,j,n,m;
 freopen("a.in","r",stdin);
 freopen("a.out","w",stdout);
 scanf("%d",&t);
 while(t!=0)
 {
 	scanf("%d %d",&n,&m);
 	for(i=1;i<=n;i++)
 	{
 		scanf("%d",&a[i]);
 		if(a[i]>m)
 		{
 			printf("No\n");
 			return 0;
 		}
 	}
 	for(i=1;i<=m;i++)
 	  scanf("%d",&b[i]);
 	sort(a+1,a+n+1,cmp);
 	sort(b+1,b+n+1);
 	for(i=1;i<=n;i++)
 	{
 		for(j=1;j<=m;j++)
 		{
 			if(b[j]==0)continue;
 			b[j]--;
 		}
 		if(b[j]!=0)
 		{
 			printf("No\n");
 			return 0;
 		}
 	}
 	printf("Yes\n");
	t--;
 }
 fclose(stdin);
 fclose(stdout);
 return 0;
} 
