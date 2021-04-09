#include<stdio.h>
int main()
{
	char a;
	bool stack[10000]={0};
	int top=0;
	do
	{
		a=getchar();
		if(a=='(')  top++;
		else if(a==')')
		{
			if(top==0)
			{
				printf("NO");
				return 0;
			}
			top--;
		}
	}while(a != '@');
	if(top==0) printf("YES");
	else       printf("NO");
}
