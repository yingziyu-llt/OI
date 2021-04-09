#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<set>
multset <pair <int,int> > s;
pair <int,int> p;
struct list
{
    int nxt;
    pair<int,int> date;
}lst[100100];
int a[100100];
int head = 0,end = 0;
int add(int a,int b)
{
    pair<int,int> p;
    p = make_pair<int,int>(a,b);
    lst[end].nxt = end + 1;
    end++;
    lst[end].date = p;
    lst[end].nxt = head;
}
int del(int k)
{
    lst[k - 1].date = lst[k - 1].date + lst[lst[lst[k - 1].nxt]].date - lst[k].date;
    lst[k - 1].nxt =
}
int main()
{

}