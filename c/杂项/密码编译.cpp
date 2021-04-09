#include<iostream>
#include<cstdio>
#include<cstring>
#include<Windows.h>
#include<conio.h> 
#include<fstream>
using namespace std;
string z;
int mon,p,ans,o,h=1;
int main()
{
    ofstream out("请勿删除，“密码破译”的重要数据.txt", ios::in|ios::out);
    ifstream fin("fatures.dat", ios::binary);
    int num=0;
    fin.read((char*)&num, sizeof(int));
    cout<<"ZYR密码编译 版本号1.1.8"<<endl<<"智力有限公司"; 
    cout<<"这是你第"<<num+1<<"次打开文件";
    num+=1;
    out.write((char*)&num, sizeof(int));
    cout<<endl<<"是否了解版本更新？（yes/no）";
    cin>>z;
    if(z=="yes")
    {
        cout<<endl<<"1.1.1 新增了启动器，装B专用" ;
        Sleep(100);
        cout<<endl<<"1.1.2 新增了打字式输入，更富有体验感";
        Sleep(100);
        cout<<endl<<"1.1.3 新增了多次编译，无需多次打开应用";
        Sleep(100);
        cout<<endl<<"1.1.5 解决了输入日文无法编译的问题";
        Sleep(100);
        cout<<endl<<"1.1.6 加快了启动器的等待数据";
        Sleep(100);
        cout<<endl<<"1.1.7 新增了防加密代码作弊，作者无聊";
        Sleep(100);
        cout<<endl<<"1.1.8 解决了更新1.1.7后无法输出的问题";
        Sleep(100);
        cout<<endl;
        system("pause");
    }
    Sleep(1000);
    for(int i=1;i<=25;i++)
    {
        cout<<i<<"%";
        Sleep(10);
        system("cls");
    }
    system("cls");
    cout<<"字符："; 
    char s[1000];
    int len,position;
    int sum=0;
    int i,j;
    system("cls");
    for(p=1;;p++)
    {
        cout<<"字符："; 
        char s[1000];
        int len,position;
        int sum=0;
        gets(s);
        for(int i=1;i<=1000;i++)
        {
            if(s[i]=='#'||s[i]=='<'||s[i]==';'||s[i]=='>'||s[i]=='{')
            {
                ans++; 
            } 
        }
        for(int i=1;i<=9;i++)
        {
            if(s[i]=='#'||s[i]=='i'||s[i]=='n'||s[i]=='c'||s[i]=='l'||s[i]=='u'||s[i]=='d'||s[i]=='e'||s[i]=='<')
            {
                o++;
            }
        }
        if(ans>=10&&o>=6)
        {
            cout<<"勘测到你在编译代码，谢绝编译代码！！！"; 
            Sleep(1000);
            h*=5;
            cout<<"锁定"<<h<<"秒！";
            Sleep(2000);
            system("cls");
            for(int i=h-2;i>=1;i--)
            {
                cout<<"还剩"<<i<<"秒。";
                Sleep(1000);
                system("cls");  
            } 

        }
        int i,j;
        cout<<"原字符为：";
        cout<<s<<endl;
        len=strlen(s);
        s[len]=' ';
        cout<<"嗯";
        Sleep(700);
        cout<<".";  
        Sleep(300); 
        cout<<".";
        Sleep(300);
        cout<<".";
        Sleep(300);
        cout<<".";
        Sleep(300);
        cout<<".";
        Sleep(300);
        cout<<".";
        system("cls");
        cout<<"编译后为:";
        for(i=0;i<=len;i++)
        {
            if(ans>=10&&o>=6)   break;
            if(s[i]!=' ')   sum++;
            else
        {           
                position=i;
                for(j=1;j<=sum;j++)
                {
                    cout<<s[--position];
                    Sleep(50);
                }
                sum=0;
            }
        }
//      cout.close();
        cout<<endl;
        ans=0;
        o=0;
    }

    return 0;
}