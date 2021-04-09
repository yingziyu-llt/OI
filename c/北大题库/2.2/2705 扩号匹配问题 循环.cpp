#include<stdio.h>
#include<string.h>
char s[101];int a[101];
int main()
{
	int  i,j,ls,k=99;
	while(scanf("%s",s)!=EOF)
	{
  		printf("%s\n",s);
  		ls=strlen(s);
  		for(i=0;i<ls;i++)
  		{
		  if(s[i]=='(') {
			a[i]=1;
			if(i<k) k=i;
			
		  }
		  if(s[i]==')')
		  {
		  	j=i;
  			for( ;j>=k;j--)
  			{
  				if(a[j]==1) {a[j]=0;break;}
			  	if(j<k) a[i]=-1;
			}
			 for(i=0;i<ls;i++)
			 { 
  				if(a[i]==0) printf("");
  				else if(a[i]==1) {printf("$");a[i]=0;}
  				else if(a[i]==-1) {printf("?");a[i]=0;}
  			} 
  			printf("\n");
  	
		  }
  		}
  		return  0;
  	}
}

