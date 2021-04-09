#include<stdio.h>
int a[12][12];
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
inline int max(int a,int b){return a>b?a:b;}
int main(){
	freopen("haji.in","r",stdin);
	freopen("haji.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=read();
	int t=0;
	for(int i=1;i<=n;i++){
		int b1=0,b2=0,b3=0;
		for(int j=1;j<=m;j++){
			if(a[i][j]%3==0)b1++;
			if((a[i][j]+1)%3==0)b2++;
			if((a[i][j]+2)%3==0)b3++;
		}
		t+=max(b1,max(b2,b3));
	}
	printf("%d",t);
	fclose(stdin);fclose(stdout);
}
