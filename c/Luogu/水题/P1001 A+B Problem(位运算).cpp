/*
题目描述
输入两个整数a,b，输出它们的和(|a|,|b|<=10^9)。

注意

pascal使用integer会爆掉哦！
有负数哦！
c/c++的main函数必须是int类型，而且最后要return 0。这不仅对洛谷其他题目有效，而且也是noip/noi比赛的要求！
好吧，同志们，我们就从这一题开始，向着大牛的路进发。

任何一个伟大的思想，都有一个微不足道的开始。

输入输出格式
输入格式：
两个整数以空格分开

输出格式：
一个数

输入输出样例
输入样例#1： 复制
20 30
输出样例#1： 复制
50
*/

#include<stdio.h>
int main()
{
	int jw,ans;
	int a,b;
	scanf("%d%d",&a,&b);
	jw = a & b;
	ans = a ^ b;
	while(1)
	{
		jw <<= 1;
		int tmp = ans & jw;
		ans = ans ^ jw;
		jw = tmp;
		if(jw == 0) break;
	}
	printf("%d",ans);
	return 0;
}