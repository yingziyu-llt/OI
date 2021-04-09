#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;
struct Word{
    string word,meaning;
    bool used;
}w[10000];
string ans;
char last,foo;
int tot,r=1,sumc,sump;
bool is_first=1;
void read();
void game();
int main(){
    srand((unsigned)time(NULL));
    read();
    cout<<"*-----------------------------------------------*"<<endl;
    cout<<"|Welcome to play the Word Solitaire!(By _Los)   |"<<endl;
    cout<<"|Make sure that you're using the Windows System!|"<<endl;
    cout<<"|Tips:You can give up by inputing 'GIVEUP'!     |"<<endl;
    cout<<"|     All the words in this game are lower case!|"<<endl;
    cout<<"*-----------------------------------------------*"<<endl;
    cout<<"Press any key to continue..."<<endl;
    foo=_getch();
    game();
    return 0;
}
void read(){
    ifstream fin;
    string buf;
    bool flag=0;
    fin.open("data.txt");
    fin>>buf;
    while(buf!="@"){
        w[tot].used=0;
        for(int i=0;i<buf.length();i++){
            if(buf[i]=='#'){
                flag=!flag;
                continue;
            }
            if(!flag)w[tot].word+=buf[i];
            if(flag)w[tot].meaning+=buf[i];
        }
        tot++;flag=0;
        fin>>buf;
    }
    fin.close();
}
void game(){
    string k;
    bool e=1,fail=is_first?1:0;
    int cword=rand()%tot;
    if(!is_first)
        for(int i=0;i<tot;i++)if((w[i].word)[0]==last)fail=1;
    if(fail==0){
        cout<<"Ooops!The computer lost!"<<endl;
        ofstream fout;
        fout.open("ans.txt");
        fout<<"The computer lost in Round "<<r<<".Congratulations!"<<endl;
        fout<<"The score of computer:"<<sumc<<endl;
        fout<<"The score of you:"<<sump<<endl<<ans<<endl;
        fout.close();
        system("cls");
        cout<<"Congratulations!"<<endl;
        return;
    }
    if(!is_first)
    while(w[cword].used || (w[cword].word)[0]!=last)cword=rand()%tot;
    w[cword].used=1;
    system("cls");
    cout<<"Round:"<<r<<endl;
    cout<<"The score of computer:"<<sumc<<endl;
    cout<<"The score of you:"<<sump<<endl;
    if(!is_first)cout<<"The 'Dragon':"<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<ans<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"The computer gave: "<<w[cword].word<<endl;
    cout<<"---------------Meaning--------------"<<endl<<w[cword].meaning<<endl<<"------------------------------------"<<endl;
    cout<<"Now,it's your turn:";
    sumc+=(w[cword].word).length();
    ans+=is_first?w[cword].word:"->"+w[cword].word;
    is_first=0;
    while(e){
        cin>>k;
        if(k=="GIVEUP"){
            ofstream fout;
            fout.open("ans.txt");
            fout<<"You gave up in Round "<<r<<".That's a pity!"<<endl;
            fout<<"The score of computer:"<<sumc<<endl;
            fout<<"The score of you:"<<sump<<endl<<ans<<endl;
            fout.close();
            system("cls");
            cout<<"See you~~~"<<endl;
            return;
        }
        for(int i=0;i<tot;i++)
            if(w[i].word==k && !w[i].used && (w[cword].word)[(w[cword].word).length()-1]==k[0] ){
                cout<<"Good!"<<endl<<"---------------Meaning--------------"<<endl<<w[i].meaning<<endl<<"------------------------------------"<<endl;
                ans+="->"+k;
                r++;
                e=0;
                w[i].used=1;
                last=k[k.length()-1];
                sump+=k.length();
                break;
            }
        if(e==1)cout<<"Wrong spelling!Please input again:";
    }
    cout<<"Press any key to continue another round..."<<endl;
    foo=_getch();
    game();
}