#include<stdio.h>
using namespace std;
int main(){
	freopen("PVZ.in","r",stdin);
	freopen("PVZ.out","w",stdout);
	int n,x,y,ans = 1,flag=-1;
	scanf("%d%d",&n,&x);
	for(int i=2;i<=n;i++){
		scanf("%d",&y);
		if(y>x&&flag!=1){
			ans++;
			flag=1;
		}
		if(y<x&&flag!=0){
			ans++;
			flag=0;
		}
		x=y;
	}
	printf("%d",ans);
}
