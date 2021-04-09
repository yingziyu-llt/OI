#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
 
int l,r,c;
char map[32][32][32];
int book[32][32][32];
 
struct note
{
   int x,y,z;
   int step;
}str,end,st,ed;
 
int bfs()
{
	int next[6][3]={{-1,0,0},{0,-1,0},{0,0,-1},{1,0,0},{0,1,0},{0,0,1}};
	queue<note>Q;
	memset(book,0,sizeof(book));
	st.x=str.x;st.y=str.y;st.z=str.z;st.step=0;
	book[st.x][st.y][st.z]=1;
	Q.push(st);
	while(!Q.empty())
	{
		st=Q.front();
		Q.pop();
		for(int i=0;i<6;i++)
		{
			ed.x=st.x+next[i][0];
			ed.y=st.y+next[i][1];
			ed.z=st.z+next[i][2];
			ed.step=st.step+1;
			if(ed.x>=0&&ed.y>=0&&ed.z>=0&&ed.x<l&&ed.y<r&&ed.z<c&&map[ed.x][ed.y][ed.z]!='#'&&book[ed.x][ed.y][ed.z]==0)//此处特别注意，调试了好久这里时！=‘#’而不是==‘.'这样的话E就被排除在外了
			{
				book[ed.x][ed.y][ed.z]=1;
				if(ed.x==end.x&&ed.y==end.y&&ed.z==end.z)
                {
                    return ed.step;
		        }
				Q.push(ed);
			}
		}
	}
	return -1;
}
int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	while(~scanf("%d %d",&l,&r))
	{
		c=r;
		if(l==0&&r==0&&c==0)
		    break;
		map[0][0][0]='S';
		if(l==1) r=1;
		if(l==2) l--;
		for(int i=0;i<l;i++)
		{
		    getchar();
			for(int j=0;j<r;j++)
			{
				for(int k=0;k<c;k++)
				{
					scanf("%c",&map[i][j][k]);
					if(map[i][j][k]=='S')
				    {
				    	str.x=i;str.y=j;str.z=k;
				    }
				    if(map[i][j][k]=='@')
				    {
				    	end.x=i;end.y=j;end.z=k;
				    }
				}
				getchar();
			}
		}
		if(bfs()!=-1)
		    printf("YES\n");
		else
		    printf("No\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
