#include<stdio.h>
#include<ctype.h>
struct node
{
    char date,l,r;
}tree[1000];
int print(char head)
{
    if(head == '\0') return 0;
    printf("%c",head);
    print(tree[head].l);
    print(tree[head].r);
}
int main()
{
    int n,head;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        char c[10];
        scanf("%s",c);
        if(i == 0) head = c[0];
        tree[c[0]].date = c[0];
        if(isalpha(c[1]))
            tree[c[0]].l = c[1];
        else 
            tree[c[0]].l = '\0';
        if(isalpha(c[2]))
            tree[c[0]].r = c[2];
        else 
            tree[c[0]].r = '\0';
    }
    print(head);
}