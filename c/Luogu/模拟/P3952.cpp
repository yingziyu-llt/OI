#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stack>
using namespace std;
stack <int> s1;//预处理用
stack <int> s2;//处理跳出语句点
int orders[10000][4];.//语句
bool used[100];//变量已使用标记
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		while(!s1.empty()) s1.pop();
		while(!s2.empty()) s2.pop();
		memset(orders,0,sizeof(orders));
		memset(used,0,sizeof(used));
		int L;
		scanf("%d",&L);
		char s[1000];
		scanf("%s",s);
		int i = 0,ox = 0;
		bool flag = false;
		while(s[i] != 'n' && s[i] != '1')
			i++;
		if(s[i] == '1') flag = true;//特殊处理O(1)
		for(i;i < strlen(s) && !flag;i++)
		{
			if(s[i] == ')') 
				break;
			if(s[i] >= '0' && s[i] <= '9')
				ox = ox  * 10 + s[i] - '0';
		}//处理O(n^w)
		int cnt = 0;//F语句个数
		bool Err = false;//是否出错
		for(int i = 0;i < L;i++)//预处理 坑点：Err处理
		{
			char c = 0;
			while(c != 'F' && c != 'E')//过滤空格和回车
				scanf("%c",&c);
			if(c == 'E')//E语句
			{
				if(!s1.empty()) 
					orders[s1.top()][3] = cnt;//建立goto语句方式
				if(s1.size() == 0 && i != 0 && !Err)//Err 1: E与F不匹配,E比F多(不包括只有一个E)
													//!Err :避免重复报错，同时读完所有数据
				{
					printf("ERR\n");
					Err = true;
				}
				if(s1.empty() && i == 0 && L != 1 && !Err)//Err 2：第一行为E,但代码没有结束
				{
					printf("ERR\n");
					Err = true;
				}
				if(i != 0 && !s1.empty())//循环结束,销毁变量
				{
					used[orders[s1.top()][0]] = false;
					s1.pop();
				}
			}
			else//F语句
			{
				char b[10010];
				getchar();
				scanf("%c %s",&c,b);
				orders[cnt][0] = c - 'a';//便于销毁变量
				if(!Err&&used[c - 'a'])//Err 3:出现重复变量
				{
					printf("ERR\n");
					Err = true;
				}
				used[c - 'a'] = true;//声明变量标记
				if(b[0] == 'n') orders[cnt][1] = -1;//记录a,b;如果是n就标记为-1
				else
				{
					int xx = 0;
					for(int j = 0;j < strlen(b);j++)
						xx = xx * 10 + b[j] - '0';
					orders[cnt][1] = xx;
				}
				scanf("%s",b);
				if(b[0] == 'n') orders[cnt][2] = -1;
				else
				{
					int xx = 0;
					for(int j = 0;j < strlen(b);j++)
						xx = xx * 10 + b[j] - '0';
					orders[cnt][2] = xx;
				}
				s1.push(cnt);
				cnt++;
			}
		}
		if(!s1.empty() && !Err)//Err 4:F和E不匹配(F多于E)
		{
			printf("ERR\n");
			Err = true;
		}
		if(Err) continue;
		int maxn = 0,now = 0;
		for(int i = 0;i < cnt;i++)//判断复杂度 坑点：特判顺序
		{
			while(!s2.empty() && s2.top() <= i)//特判1 :语句已到达其所对应的E处
				s2.pop(),now--;
			if((orders[i][1] == -1 && orders[i][2] != -1) || (orders[i][1] > orders[i][2] && orders[i][2] != -1)) 
					//特判2 : 循环无法进入
					/*
						1.a < b
						2.a 是 n,而b不是
					*/
					//直接跳转到该循环结束位置
			{
				i = orders[i][3];
				continue;
			}
			if(orders[i][1] * orders[i][2] > 0) continue;
			//特判3 : 循环仅提供常数级复杂度(a,b均为常数或n)

			
			now++;
			maxn = max(now,maxn);//复杂度增长
			s2.push(orders[i][3]);//将该语句放入待结束栈中
		}
		if(maxn == ox) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}