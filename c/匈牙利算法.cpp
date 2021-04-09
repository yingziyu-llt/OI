#include <stdio.h>
int n, m;
bool map[100][100];//map[i][j] ��ʾi��j���� 
int girls[100];
int used[100];
bool find(int x)
{
    for (int i = 1; i <= m; i++) {
        if (map[x][i] && !used[i]) {
        	used[i] = 1;
            if (!girls[i] || find(girls[i])) {
                girls[i] = x;
                return true;
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d%d", &n, &m);
	//
	for (int i = 1; i <= n; i++) {
		memset(used, 0, sizeof(used));
	    if (find(i)) ans++;   //find(x)�����x�������ܷ��ҵ��� 
	}
	printf("%d", ans);
	return 0;
}
