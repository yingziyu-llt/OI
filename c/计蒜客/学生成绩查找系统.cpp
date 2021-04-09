#include<stdio.h>
#include<string.h>
struct aa
{
    int score;
    char name[100]={0};
}student[100];
void insertf(char a[],int b,int i)
{
    student[i].score=b;
    strcpy(student[i].name,a);
    return ;
}
int findf(char n[])
{
    for(int i=0;i<100;i++)
    {
        if(strcmp(n,student[i].name)==0)
        {
            return student[i].score;
        }
    }
    return -1;
}
int main()
{
   	char commed[10];
    int i=0;
    while(1)
    {
        scanf("%s",commed);
        if(strcmp(commed,"insert\0")==0)
        {
            int score={0};
            char name[100];
            scanf("%s %d",name,&score);
            insertf(name,score,i);
        }
        else if(strcmp(commed,"find\0")==0)
        {
        	char name[100]={0};
            scanf("%s",name);
            int score=findf(name);
            printf("%d\n",score);
        }
        else return 0;
    }
}
