#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int father[20000],n,m,k;
string people[20000];
int findname(string str)
{
	for(int  i = 0;i < n;i++)
		if(people[i] == str) 
			return i;
}
int findfather(int x)
{
	return father[x] = father[x] == x ? x : findfather(father[x]);
}
int main()
{
	string str1,str2;
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i++)
		cin>>people[i];
	for(int i = 0 ;i < n;i++)
		father[i] = i;
	for(int i = 0;i < m;i++)
	{
		cin>>str1>>str2;
		int a1 = findname(str1),a2 = findname(str2);
		int fa1 = findfather(a1),fa2 = findfather(a2);
		if(fa1 != fa2)
			father[a1] = fa2;
	}
	scanf("%d",&k);
	for(int i = 0;i < n;i++) findfather(i);
	for(int  i = 0 ; i < k ;i++)
	{
		cin>>str1>>str2;
		int a = findname(str1),b = findname(str2);
		if(findfather(a) == findfather(b))
			printf("Yes.\n");
		else
			printf("No.\n");
	}
	return 0;
}