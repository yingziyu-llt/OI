#include <stdio.h>
#include <string.h>
char a[100005];
int p,len,i;
int main()
{
 freopen("nigeru.in","r",stdin);
 freopen("nigeru.out","w",stdout);
 gets(a);
 len=strlen(a);
 a[len]='!';
 while(a[i]!='!')
 {
 	if(a[i]=='.')p=0;
 	if(a[i]>='a'&&a[i]<='z'&&p==0)
 	{
 		a[i]-=32;
 		p=1;
 		i++;
 		continue;
 	}
 	else if(a[i]>='A'&&a[i]<='Z'&&p==1)
 	{
 		a[i]+=32;
 		i++;
 		continue;
 	}
 	else if(a[i-1]>='A'&&a[i-1]<='Z'&&p==0)
 	{
 		a[i]+=32;
 		p=1;
 		i++;
 		continue;
 	}
 	i++;
 }
 for(i=0;i<len;i++)
   printf("%c",a[i]);
 fclose(stdin);
 fclose(stdout);  
 return 0;
} 
