#include<stdio.h>
int main(){
	freopen("nigeru.in","r",stdin);
	freopen("nigeru.out","w",stdout);
	char a;bool flag=0;
	scanf("%c",&a);
	if(a>='a'&&a<='z')a-=32;
	printf("%c",a);
	while(~scanf("%c",&a)){
		if(flag){
			if(a>'a'&&a>'z'||a<'A'&&a>'Z')
				printf("%c",a);
			else if(a>='a'&&a<='z')
				a-=32,flag=0;
			else flag=0;
		}
		else if(a>='A'&&a<='Z')a+=32;
		if(a=='.')flag=1;
		printf("%c",a);
	}
	fclose(stdin);fclose(stdout);
}
