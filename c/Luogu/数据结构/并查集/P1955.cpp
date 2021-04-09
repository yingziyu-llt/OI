#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int father[220000];
int aTob[120000];
int a[320000];
int n;
int input1[120000][2],input2[120000][2];
int findFather(int a)
{
    return father[a] = (father[a] == a) ? a : findFather(father[a]);
}
int findk(int n)
{
    int l = -1,r = n + 1,mid = (l + r) >> 1;
    while(l < r)
    {
        mid = (l + r) >> 1;
        if(aTob[mid] == n) return mid;
        if(aTob[mid] > n) r = mid;
        else l = mid + 1;
    }
    return mid;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int _i = 0;_i < T;_i++)
    {
        memset(a,0,sizeof(a));
        memset(aTob,0,sizeof(aTob));
        memset(input1,0,sizeof(input1));
        memset(input2,0,sizeof(input2));
        scanf("%d",&n);
        int j = 0,k = 0;
        for(int i = 0;i < n;i++)
        {
            int t1,t2,t3;
            scanf("%d%d%d",&t1,&t2,&t3);
            a[i * 2] = t1;
            a[i * 2 + 1] = t2; 
            if(t3 == 0)
            {
                input2[++j][0] = t1;
                input2[j][1] = t2;
            }
            else
            {
                input1[++k][0] = t1;
                input1[k][1] = t2;
            }
        }
        sort(a,a + n * 2);
        int tmp = 0;
        for(int i = 0;i < n * 2;i++)
        {
            if(a[i] != a[i + 1]) tmp++;
            aTob[a[i]] = tmp;
        }
        for(int i = 0;i <= tmp;i++)
            father[i] = i;
        for(int i = 1;i <= k;i++)
        {
            int k1 = findk(input1[i][0]);
            int k2 = findk(input1[i][1]);
            int f1 = findFather(k1);
            int f2 = findFather(k2);
            if(f1 != f2)
                father[f1] = f2;
        }
        bool flag = false;
        for(int i = 1;i <= j;i++)
        {
            int k1 = findk(input2[i][0]);
            int k2 = findk(input2[i][1]);
            int f1 = findFather(k1);
            int f2 = findFather(k2);
            if(f1 == f2)
            {
                flag = true;
                printf("NO\n");
                break;
            }
        }
        if(!flag)
            printf("YES\n");
    }
}