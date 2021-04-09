#include <stdio.h>
#include <string>
#include<iostream>
using namespace std;
struct node
{
	node *l, *r;
	char kind;
} * T;
string str;
void create(string s, node *t, bool lr)
{
	char kind;
	int num0 = 0, num1 = 0;
	int len = s.length();
	if (len == 0)
		return;
	for (int i = 0; i < len; i++)
		if (s[i] == '0')
			num0++;
		else
			num1++;
	if (num0 == 0 && num1 != 0)
		kind = 'I';
	else if (num0 != 0 && num1 != 0)
		kind = 'F';
	else if(num0 != 0 && num1 == 0)
		kind = 'B';
	node *nn = new node;
	nn->l = NULL;
	nn->r = NULL;
	nn->kind = kind;
	if (lr)
		t->l = nn;
	else
		t->r = nn;
	create(s.substr(0,s.length()/2),nn,true);
	create(s.substr(s.length()/2,s.length() - 1),nn,false);
}
void print(node *t)
{
	if(t != NULL)
	{
		print(t->l);
		print(t->r);
		printf("%c",t->kind);
	}
}
int main()
{
	freopen("fbi.in","r",stdin);
	freopen("fbi.out","w",stdout);
	int n;
	cin >> n >> str;
	T = new node;
	char kind;
	int len = str.length();
	int num0 = 0,num1 = 0;
	for (int i = 0; i < len; i++)
		if (str[i] == '0')
			num0++;
		else
			num1++;
	if (num0 == 0 && num1 != 0)
		kind = 'I';
	else if (num0 != 0 && num1 != 0)
		kind = 'F';
	else if(num0 != 0 && num1 == 0)
		kind = 'B';
	T->kind = kind;
	T->l = NULL;
	T->r = NULL;
	create(str.substr(0,str.length()/2),T,true);
	create(str.substr(str.length()/2,str.length() - 1),T,false);
	print(T);
}