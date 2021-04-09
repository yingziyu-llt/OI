#include<bits/stdc++.h>
char a[100000];
int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	int m,n;
	while(1)
	{
		m=0;n=0;
		memset(a,'\0',sizeof(a)); 
		scanf("%d%d",&m,&n);
		getchar();
		if(m==0&&n==0) break;
	    for(int i=1;i<=n;i++)
	      scanf("%c",&a[i]);
	    getchar();
	    for(int i=1;i<=n;i++)
		  if(a[i]=='#')
		  {
			printf("No\n");
			break;
		  }
		  else if(a[i]=='@')
		  {
		  	printf("YES\n");
		  	break;
		  }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
 } 
