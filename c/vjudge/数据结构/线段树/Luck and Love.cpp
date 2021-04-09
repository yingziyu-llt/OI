//二维线段树（线段树套线段树）
//HDU 1823
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define lson(id,l) id << 1,l,mid
#define rson(id,r) id << 1 | 1,mid + 1,r
using namespace std;
const int xsiz = 110,ysiz = 1100;
int hight,act,min_hight,max_hight,min_act,max_act;
double luck;
struct Segment_Tree_2
{
	double date[110 << 2][1100 << 2];
	void change_y(int x,int root,int l,int r)
	{
		date[x][root] = max(date[x][root],luck);
		if(l == r) return;
		int mid = (l + r) / 2;
		if(act <= mid)
			change_y(x,lson(root,l));
		else
			change_y(x,rson(root,r));
	}
	void change_x(int root,int l,int r)
	{
		change_y(root,1,0,ysiz);
		if(l == r) return ;
		int mid = (l + r) / 2;
		if(hight <= mid)
			change_x(lson(root,l));
		else
			change_x(rson(root,r));
		return ;
	}
	double quary_y(int x,int root,int l,int r)
	{
		if(l >= min_act && r <= max_act)
			return date[x][root];
		int mid = (l + r) / 2;
		double ans = -1;
		if(min_act <= mid) ans = max(quary_y(x,lson(root,l)),ans);
		if(mid < max_act) ans = max(quary_y(x,rson(root,r)),ans);
		return ans;
	}
	double quary_x(int root,int l,int r)
	{
		if(l >= min_hight && r <= max_hight)
			return quary_y(root,1,0,ysiz);
		int mid = (l + r)/ 2;
		double ans = -1;
		if(min_hight <= mid) ans = max(quary_x(lson(root,l)),ans);
		if(mid < max_hight) ans = max(quary_x(rson(root,r)),ans);
		return ans;
	}
	void build()
	{
		for(int i = 0;i < xsiz << 2;i++)
			for(int j = 0;j < ysiz << 2;j++)
				date[i][j] = -1;
		return;
	}
}Tree;

int main()
{
	int n;
	while(1)
	{
		Tree.build();
		scanf("%d",&n);
		if(n == 0) break;
		for(int i = 0;i < n;i++)
		{
			char s[10];
			scanf("%s",s);
			if(s[0] == 'I')
			{
				double aa;
				scanf("%d%lf%lf",&hight,&aa,&luck);
				hight -= 99;
				act = (int)(10 * aa);
				Tree.change_x(1,0,xsiz);
			}
			else
			{
				double x1,x2;
				scanf("%d%d%lf%lf",&min_hight,&max_hight,&x1,&x2);
				min_hight -= 99;
				max_hight -= 99;
				min_act = (int)(x1 * 10);
				max_act = (int)(x2 * 10);
				if(min_hight > max_hight) swap(min_hight,max_hight);
				if(min_act > max_act) swap(min_act,max_act);
				double ans = Tree.quary_x(1,0,xsiz);
				if(ans == -1) printf("-1\n");
				else printf("%.1lf\n",ans);
			}
		} 
	}
	return 0;
}