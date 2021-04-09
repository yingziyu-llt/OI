#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
string a[30];
int n,cnt,b[30];
int fun(int i,int j)
{
	int len=min(a[i].size(),a[j].size());
	for(int k=1;k<=len;k++)
		if(a[i].substr(a[i].size()-k,a[i].size())==a[j].substr(0,k)) return a[j].size()-k;
	return 0; 
}
int dfs(int len,int p)
{
	cnt=max(len,cnt);
	for(int i=1;i<=n;i++)
	{
		if(b[i]>1) continue;
		int k=fun(p,i);
		if(!k) continue;
		b[i]++;
		dfs(len+k,i);
		b[i]--; 
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cin>>a[0];
	dfs(1,0);
	cout<<cnt;
	return 0;
}

