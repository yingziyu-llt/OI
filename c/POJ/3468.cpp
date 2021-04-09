#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 110000;
int a[N];
struct segment_tree
{
    int date[N << 2],lazy[N << 2];
    void pushup(int root)
    {
        date[root] = date[root << 1] + date[root << 1 | 1]; 
    }
    void pushdown(int root,int l,int r)
    {
        if(!lazy[root])
            return ;
        int mid = (l + r) >> 1;
        date[root << 1] += lazy[root] * (mid - l + 1);
        date[root << 1 | 1] += lazy[root] * (r - mid);
        lazy[root << 1] += lazy[root];
        lazy[root << 1 | 1] += lazy[root];
        lazy[root] = 0;
    }
    void build(int root,int l,int r)
    {
        if(l == r)
        {
            date[root] = a[l];
            lazy[root] = 0;
            return ;
        }
        int mid = (l + r) >> 1;
        build(root << 1,l,mid);
        build(root << 1 | 1,mid + 1,r);
        pushup(root);
    }
    void change(int root,int l,int r,int x,int y,int c)
    {
        if(l >= x && r <= y)
        {
            date[root] += c * (r - l + 1);
            lazy[root] += c;
            return ;
        }
        pushdown(root,l,r);
        int mid = (l + r) >> 1;
        if(x <= mid) change(root << 1,l,mid,x,y,c);
        if(y > mid)change(root << 1 | 1,mid + 1,r,x,y,c);
        pushup(root);
        return ;
    }
    int query(int root,int l,int r,int x,int y)
    {
        if(l >= x && r <= y)
            return date[root];
        int ans = 0;
        int mid = (l + r ) >> 1;
        pushdown(root,l,r);
        if(x <= mid) ans += query(root << 1,l,mid,x,y);
        if(y > mid) ans += query(root << 1 | 1,mid + 1,r,x,y);
        return ans;
    }
}Tree;
int main()
{
    int n;
    scanf("%d")
}