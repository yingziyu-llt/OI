#include <windows.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
int main()
{
	srand((unsigned)time( NULL ));
while(1)
{
	int x=rand()%1000000;
	int y=rand()%1000000;
	printf("hahaha!!!!\n");
 ::SetCursorPos(x,y);				
}
}

