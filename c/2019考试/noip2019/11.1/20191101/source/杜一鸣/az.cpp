#include<stdio.h>
#include<string.h>
int t[26000],t1[26000];
char a[105][50005];
void q_sort(int x,int l,int r)
{
	int i=l,j=r,mid=a[x][(l+r)/2],t;
	while(i<j)
	{
		while(a[x][i]<mid)
		{
			i++;
		}
		while(mid<a[x][j])
		{
			j--;
		}
		if(i<=j)
		{
			t=a[x][i];
			a[x][i]=a[x][j];
			a[x][j]=t;
			i++;
			j--; 
		}
	}
	if(l<j)
		q_sort(x,l,j);
	if(i<r)
		q_sort(x,i,r);
}
int main()
{
    int i,j,z,ans=0,n;
    //freopen("az.in","r",stdin);
    //freopen("az.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",a[i]+1);
    }
    for(i=1;i<=n;i++)  q_sort(i,1,strlen(a[i])-1);
    for(i=1;i<=250;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(z=j+1;z<=n;z++)
            {
                if(a[j][i]!=a[z][i]) ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}