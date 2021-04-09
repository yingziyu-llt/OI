#include<stdio.h>
int a[100005],pos[100005];
bool vis[100005];
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
int main(){
	freopen("wa.in","r",stdin);
	freopen("wa.out","w",stdout);
	int n=read(),num=n/2;
	for(int i=1;i<=n;i++)
		a[i]=read(),pos[a[i]]=i;
	int t=n,i;
	while(num){
		while(vis[t]||t==a[n])t--;
		for(i=pos[t]+1;i<=n;i++)if(!vis[a[i]])break;
		if(i==n+1){t--;continue;}
		vis[t]=1;vis[a[i]]=1;
		printf("%d %d ",t,a[i]);
		num--;
	}
	fclose(stdin);fclose(stdout);
}
