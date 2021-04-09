#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 1e5 + 10;
int n,m,num[N << 1],h[N << 1],tot,root[N << 1],cnt,L[30],R[30],cntl,cntr;
struct node
{
	int val,lson,rson;
}a[600000000];
int lowbit(int x)
{
	return x & -x;
}
void update(int last,int &o,int l,int r,int v,int k)
{
	o = ++cnt;
	a[o] = a[last];
	s[o].val += k;
	int mid = (l + r) >> 1;
	if(k <= mid) update(a[last].lson,a[o].lson,l,mid,v,k);
	else update(a[last].rson,a[o].rson,mid + 1,r,v,k);
	return ;
}
