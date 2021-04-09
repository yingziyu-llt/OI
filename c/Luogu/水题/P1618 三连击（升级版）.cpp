#include<stdio.h>
#include<string.h>
using namespace std;
bool used[10];
int ans[1000][3];
int main()
{
    int a,b,c;//?? 
    int x,y,z;//??? 
    int cnt = 0;
    memset(ans,0,sizeof(ans));
    scanf("%d%d%d",&a,&b,&c);
    for(int i = 1;i <= 9;i++)
    {
        used[i] = true;//???? 
        for(int j = 1;j <= 9;j++)
        {
            if(j == i) continue;
            used[j] = true;//???? 
            for(int k = 1;k <= 9;k++)
            {
                bool flag=true;//??? 
                if(k == j || k == i) continue;
                used[k] = true;//???? 
                x = i * 100 + j * 10 + k;
                if((int)((float) x / a * b) != (float) x / a * b || (int)((float) x / a * c) != (float) x / a * c)
                    continue;
                y = (float) x / a * b;
                z = (float) x / a * c;
                int cp_y = y,cp_z = z;
                if(y < 100 || z < 100) flag = false;
                for(int m = 0;y > 0 || z > 0;m++)
                {
                    if(used[y % 10] || used[z % 10]) 
                    {
                        flag = false;
                        break;
                    }
                    used[y % 10] = true;
                    used[z % 10] =true;
                    y /= 10;
                    z /= 10;
                }
                if(used[0] == true) flag = false;
                for(int m = 0;m < 10; m++)//??????
                {
                    if(m != i && m != j)
                        used[m] = false;
                }
                if(cnt == 4) break;
                if(flag)
                {
                    printf("%d %d %d\n",x,cp_y,cp_z);
                    cnt++;
                }
            }
            used[j] = false;//?????? 
        }
        used[i] = false;//?????? 
    }
    if(cnt == 0)
        printf("No!!!");
} 
