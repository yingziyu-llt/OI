#include <stdio.h>
int ans[32];
int fen(int n)
{
	int tmp;
 if(n==0||n==1)
    return 1 ;
 else
 {
 	if(ans[n-1]== ans[n-1]=fen(n-1);
    if(ans[n-2]==0) ans[n-2]=fen(n-2);
	return ans[n-1]+ans[n-2];

 }
}
int main()
{
 int n;
 ans[0]=1;
 ans[1]=1;
 while(scanf("%d",&n)!=EOF)
  printf("%d\n",fen(n));
 return 0;
}

