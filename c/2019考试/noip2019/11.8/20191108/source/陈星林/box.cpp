#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
 int v,minn=1000000000;
 freopen("box.in","r",stdin);
 freopen("box.out","w",stdout);
 scanf("%d",&v);
 for(int a=1;a<=(int)round(pow(v,1.0/3));a++)
 {
   for(int b=1;b<=sqrt(v/a);b++)
   {
   	 int c=v/a/b;
   	 if(a*b*c!=v)continue;
   	 minn=min(minn,2*(a*b+a*c+c*b));
   }
 }
 printf("%d",minn);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
