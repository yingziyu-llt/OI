#include <stdio.h>
#include <queue>
using namespace std;
int n, k;
int maxdep;
struct node
{
    long long w, h;
    node(long long W, long long H)
    {
        w = W, h = H;
    }
};
bool operator<(node a, node b)
{
    if (a.w != b.w)
        return a.w > b.w;
    return a.h > b.h; 
} 
priority_queue<node, std::less<node>, std::pairing_heap_tag> q;
int main()
{
    scanf("%d%d",&n,&k);
    long long tmp;
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld",&tmp);
        q.push(node(tmp,1))
    }
}