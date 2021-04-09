#include<stdio.h>
int map[1002][1002];
int main()
{
	int n,m,k,o,p,q,s,ans=0;
	scanf("%d %d %d",&n,&m,&k);
	 for(int i=1;i<=m;i++){
        scanf("%d %d",&o,&p);
        o+=2;
        p+=2;
        map[o+2][p]=1;
        map[o][p+2]=1;
        map[o-2][p]=1;
        map[o][p-2]=1;
        map[o+1][p]=1;
        map[o+1][p+1]=1;
        map[o+1][p-1]=1;
        map[o][p+1]=1;
        map[o][p]=1;
        map[o][p-1]=1;
        map[o-1][p]=1;
        map[o-1][p+1]=1;
        map[o-1][p-1]=1;
    }
    for(int i=1;i<=k;i++){
        scanf("%d %d",&q,&s);
        q+=2;
        s+=2;
        map[q-2][s-2]=1;
        map[q-2][s-1]=1;
        map[q-2][s]=1;
        map[q-2][s+1]=1;
        map[q-2][s+2]=1;
        map[q-1][s-2]=1;
        map[q-1][s-1]=1;
        map[q-1][s]=1;
        map[q-1][s+1]=1;
        map[q-1][s+2]=1;
        map[q][s-2]=1;
        map[q][s-1]=1;
        map[q][s]=1;
        map[q][s+1]=1;
        map[q][s+2]=1;
        map[q+1][s-2]=1;
        map[q+1][s-1]=1;
        map[q+1][s]=1;
        map[q+1][s+1]=1;
        map[q+1][s+2]=1;
        map[q+2][s-2]=1;
        map[q+2][s-1]=1;
        map[q+2][s]=1;
        map[q+2][s+1]=1;
        map[q+2][s+2]=1;
    }
	for(int i=1+2;i<=n+2;i++)
	{
		for(int j=1+2;j<=n+2;j++)
		{
			if(map[i][j]==0)
				ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
