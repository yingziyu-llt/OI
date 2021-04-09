#include <stdio.h>
#include <string.h> 
#include <algorithm>
using namespace std;
char a[50005];
char s[50005][105];
int n,i,ans,j,k;
int len[50005];
char t;
int main()
{
 freopen("az.in","r",stdin);
 freopen("az.out","w",stdout);
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 	memset(a,-1,sizeof(a));
 	scanf("%s",a);
 	len[i]=strlen(a);
 	sort(a,a+n);
 	for(j=0;j<len[i];j++)
 	  s[i][j]=a[j];
 }
 for(i=0;i<n;i++)
 {
 	if(s[i][0]==0)continue;
 	for(j=i+1;j<n;j++)
 	{
 		for(k=0;;k++)
 		{
		  if(s[i][k]!=s[j][k])
		  {
		  	s[j][1]=0;
		  	ans++;
		  	break;
		  }
		 s[j][k]=0;
		}
 	}
 }
 printf("%d",ans);
 return 0;
} 
