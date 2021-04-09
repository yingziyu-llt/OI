#include<stdio.h> 
#include<string.h>
#include<algorithm>
using namespace std;
int f[200010];
int vv[200010],mm[200010];
int main()
{
	int s,n;
	int a,b,c;
	scanf("%d%d",&n,&s);
		for(int i=1;i<=n;i++)
		{
			int w,c,p; 
			scanf("%d%d%d",&w,&c,&p);
    	    if(p>=1)
			{
    	        int d=1;
   	         	while(p>d)
				{
   	             	for(int j=s;j>=d*w;j--)f[j] = max(f[j-w*d]+c*d,f[j]);
  	              	p-=d;
  	              	d*=2;
  	          	}
  	     		for(int j=s;j>=w*p;j--)f[j] = max(f[j-w*p]+c*p,f[j]);
   	    	}
 	       else for(int j=w;j<=s;j++)f[j] = max(f[j-w]+c,f[j]);
    }
	printf("%d",f[s]);
	return 0;
} 
