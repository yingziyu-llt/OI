#include<stdio.h>
#include<string.h>
char name1[10010],name2[10010];
struct s
{
    int a,b,c,maxc;
    char name[10010];
}ax[4],bx[4];
int main()
{
    int n;
    scanf("%s",name1);
    scanf("%s",name2);
    for(int i = 0;i < 3;i++)
        scanf("%s%d%d%d",ax[i].name,&ax[i].a,&ax[i].b,&ax[i].c),ax[i].maxc = ax[i].c;
    for(int i = 0;i < 3;i++)
        scanf("%s%d%d%d",bx[i].name,&bx[i].a,&bx[i].b,&bx[i].c),bx[i].maxc = bx[i].c;
    scanf("%d",&n);
    int now = 0,na = 0,nb = 0;
    for(int i =0 ;i < n;i++)
    {
        char commond[100];
        scanf("%s",commond);
        if(strcmp("Attack",commond) == 0)
        {
            if(now == 0)//a -> b
            {
                int heat = ax[na].a - bx[nb].b;
                if(heat > 0) bx[nb].c -= heat;
                if(bx[nb].c <= 0) nb++;
                if(nb > 2)
                {
                    printf("%s",name1);
                    return 0;
                } 
            }
            else
            {
                int heat = bx[nb].a - ax[na].b;
                if(heat > 0) ax[na].c -= heat;
                if(ax[na].c <= 0) na++;
                if(na > 2)
                {
                    printf("%s",name2);
                    return 0;
                } 
            }
        }
        else
        {
            if(now == 0)
            {
                int recovered = ax[na].maxc / 2;
                ax[na].c += recovered;
                if(ax[na].c > ax[na].maxc)
                    ax[na].c = ax[na].maxc;
            }
            else
            {
                int recovered = bx[nb].maxc / 2;
                bx[nb].c += recovered;
                if(bx[nb].c > bx[nb].maxc)
                    bx[nb].c = bx[nb].maxc;
            }
        }
    }
    int tota,totb;
    for(int i = 0 ;i < 3;i++)
        if(ax[i].c > 0)
            tota += ax[i].c;
    for(int i = 0;i < 3;i++)
        if(bx[i].c > 0)
            totb += bx[i].c;
    if(tota > totb)
        printf("%s",name1);
    else if(tota == totb)
        printf("Shiroha");
    else
        printf("%s",name2);
    return 0;
}

/*
题目背景
退役的小z开始玩一个叫做夏日岛可梦的游戏。游戏的制作商在制作了夏日岛可梦游戏本体的同时，还附赠了六条剧情线和高水准配乐。

游戏内容大概是：在游泳比赛中失利的男主鹰原羽依里，来到鸟白岛上参加了已经举办十年的岛可梦大赛。经过激烈的战斗，男主依次击败了裸王，绝壁的秘宝，加藤的诅咒，绿之死神，姬骑士，千年不变女帝，北星坚牢王，最后一举击败boss，成为了岛可梦大师。最后，男主将至尊H本留在了岛的各处，重塑信心迎接新的生活。

题目描述
具体而言，这个岛可梦小游戏的规则是这样的：

双方分为挑战方和迎战方，规定挑战方为先手。此后双方轮流出手。

双方各携带三只岛可梦，每一只岛可梦有如下属性：

攻击力aa：决定攻击时造成的伤害

防御力bb:决定受到攻击时受到的伤害

生命值cc:字面意思

每一次轮到某一方行动时，可能会进行如下两种活动：

1.攻击（Attack），对对方的岛可梦造成攻击，造成的伤害为己方攻击力减去对方防御力。如果己方攻击力小于等于对方防御力，那么造成的伤害为0

2.恢复（Recover），本回合恢复生命值上限 50\%50% 的生命值，恢复的生命值向下取整。也就是说如果生命值为101，那么使用一次Recover可以恢复50点生命值。注意回复时不能超过生命值上限。

胜负结算方式有两种：

1.如果一只岛可梦的生命值降到0或者更低，它就会退出战斗，并且按照顺序更换为下一只。如果一方的三只岛可梦全部退出战斗，那么这方就被判定为输。

2.如果达到了规定的回合数，那么所有未退出岛可梦总剩余血量高的一方会被判定为胜利。

现在你被给定了一次战斗的数据，请你根据这个数据判断出最后的胜利者是哪一方。

输入输出格式
输入格式：
第一行一个字符串，描述挑战方的姓名。仅包含英文大写和小写字母，长度不超过50.

第二行一个字符串，描述应战方的姓名。仅包含英文大写和小写字母，长度不超过50.

接下来三行，每行分别是一个字符串 ss ，三个整数 a,b,ca,b,c，分别表示挑战方三只岛可梦的姓名，攻击力，防御力，生命值

接下来三行，每行分别是一个字符串 ss ，三个整数 a,b,ca,b,c，分别表示应战方三只岛可梦的姓名，攻击力，防御力，生命值

请注意，读入顺序便是三只岛可梦的出战顺序，不可交换。

接下来一个整数 nn 表示总共进行的动作数。

接下来 nn 行，每行一个字符串，分别是 Attack 或者 Recover，描述了一次行动。

输出格式：
一行一个字符串，表示胜利方的姓名。

注意，在模拟每次行动的过程中，如果一方所有的岛可梦已经退出战斗而接下来仍有输入的行动，那么请忽略之后的双方所有行动，直接输出胜利者姓名。

同理，如果处理完所有行动后双方中并没有任何一方的岛可梦全部退出战斗，那么未退出岛可梦剩余总血量最高的一方即为获胜者。此规则下若是剩余血量相等，则输出 "Shiroha"(不含引号)

输入输出样例
输入样例#1： 复制
TakaharaHairi
SorakadoAo
aaa 30 30 100
bbb 30 30 100
ccc 30 30 100
Inari 100 20 300
qqq 30 30 100
www 30 30 100
5
Attack
Attack
Attack
Recover
Attack
输出样例#1： 复制
SorakadoAo
说明
数据范围
测试点	n的最大值	特殊约定
1	n \leq 10 n≤10	只存在Attack行动
2	n \leq 100 n≤100	只存在Attack行动
3	n \leq 1000n≤1000	只存在Attack行动
4	n \leq 10 n≤10	只存在Recover行动
5	n \leq 100n≤100	只存在Recover行动
6	n \leq 1000 n≤1000	只存在Recover行动
7	n \leq 10 n≤10	无
8	n \leq 100n≤100	无
9	n \leq 1000n≤1000	无
10	n \leq 1000 n≤1000	无
保证所有岛可梦生命值、攻击力和防御力均在 [0,10^9]
*/