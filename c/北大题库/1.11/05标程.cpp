#include<stdio.h>
long long a[10000];
int main(){
long long n,f,num,mid,l=0,r=0,x;
while(~scanf("%lld %lld",&n,&f)){
a[n]=0;
for(int i=0;i<n;i++)
{
scanf("%lld",&x);
a[i]=3.14159265359*x*x*100000;
if(a[i]>r)r=a[i];
}
r++;f++;
while (l+1<r){
mid=(l+r)/2;
num=0;
for(int i=0;i<n;i++)
num+=a[i]/mid;
if(num<f)r=mid;
if(num>=f)l=mid;
}
printf("%.3lf\n",l/100000.0);
}
return 0;
}
