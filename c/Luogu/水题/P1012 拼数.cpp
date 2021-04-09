#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;
string a[30];
bool cmp(string a,string b)
{
	return a+b>b+a;
}
int main()
{
	int i,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
       cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(i=0;i<n;i++) cout<<a[i];
	return 0;
}
