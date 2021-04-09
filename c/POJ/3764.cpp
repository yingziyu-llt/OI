#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct Tire
{
	bool n;
	bool isEnd;
	Tire *son[2];
}*root = new Tire;
int a[10010];
void clean(Tire *s)
{
	s->isEnd = false;
	s->n = 0;
	s->son[0] = s->son[1] = nullptr;
}
void crate(int a[])
{
	Tire *r = nullptr;
	r = root;
	int len = 32;
	for(int i = )
}