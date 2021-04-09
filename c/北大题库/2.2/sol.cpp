#include<stdio.h>
int t,m,n;
int zhangxunqi(int m,int n){
	if(m==0||n==1)return 1;
	else if(m<n)return zhangxunqi(m,m);
	else return zhangxunqi(m-n,n)+zhangxunqi(m,n-1);
}
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&t);
	while(t--){
	scanf("%d%d",&m,&n);
	printf("%d\n",zhangxunqi(m,n));
	}
	return 0;
}

