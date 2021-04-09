#include<stdio.h>
int a[10001],t,m,n;
int zhangxunqi(int m,int n)
{
   if(m==0||n==1)
   {
      a[1]=1;
      return a[1];
   }
   else if(m<n)
   {
      a[m]=zhangxunqi(m,m);
      return a[m];
   }
   else{
      a[m]=zhangxunqi(m-n,n)+zhangxunqi(m,n-1);
      return a[m];
   }
}
int main()
{
	scanf("%d",&t);
	while(t--){
	scanf("%d%d",&m,&n);
	printf("%d\n",zhangxunqi(m,n));
	}
	return 0;
}

