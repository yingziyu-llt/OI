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
    ofstream out("����ɾ�������������롱����Ҫ����.txt", ios::in|ios::out);
    ifstream fin("fatures.dat", ios::binary);
    int num=0;
    fin.read((char*)&num, sizeof(int));
    cout<<"ZYR������� �汾��1.1.8"<<endl<<"�������޹�˾"; 
    cout<<"�������"<<num+1<<"�δ��ļ�";
    num+=1;
    out.write((char*)&num, sizeof(int));
    cout<<endl<<"�Ƿ��˽�汾���£���yes/no��";
    cin>>z;
    if(z=="yes")
    {
        cout<<endl<<"1.1.1 ��������������װBר��" ;
        Sleep(100);
        cout<<endl<<"1.1.2 �����˴���ʽ���룬�����������";
        Sleep(100);
        cout<<endl<<"1.1.3 �����˶�α��룬�����δ�Ӧ��";
        Sleep(100);
        cout<<endl<<"1.1.5 ��������������޷����������";
        Sleep(100);
        cout<<endl<<"1.1.6 �ӿ����������ĵȴ�����";
        Sleep(100);
        cout<<endl<<"1.1.7 �����˷����ܴ������ף���������";
        Sleep(100);
        cout<<endl<<"1.1.8 ����˸���1.1.7���޷����������";
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
    cout<<"�ַ���"; 
    char s[1000];
    int len,position;
    int sum=0;
    int i,j;
    system("cls");
    for(p=1;;p++)
    {
        cout<<"�ַ���"; 
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
            cout<<"���⵽���ڱ�����룬л��������룡����"; 
            Sleep(1000);
            h*=5;
            cout<<"����"<<h<<"�룡";
            Sleep(2000);
            system("cls");
            for(int i=h-2;i>=1;i--)
            {
                cout<<"��ʣ"<<i<<"�롣";
                Sleep(1000);
                system("cls");  
            } 

        }
        int i,j;
        cout<<"ԭ�ַ�Ϊ��";
        cout<<s<<endl;
        len=strlen(s);
        s[len]=' ';
        cout<<"��";
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
        cout<<"�����Ϊ:";
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