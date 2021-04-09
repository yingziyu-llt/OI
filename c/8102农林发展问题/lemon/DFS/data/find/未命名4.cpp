#include <iostream>
using namespace std;
int main()
{
int a,b,sum,k,i;
cin>>k;
a=1;
b=1;
if(k==1||k==2)
cout<<1;
else
{for(i=1;i<=k-2;i++)
{
sum=b+a;
a=b;
b=sum;
}
cout<<sum;
}

}
