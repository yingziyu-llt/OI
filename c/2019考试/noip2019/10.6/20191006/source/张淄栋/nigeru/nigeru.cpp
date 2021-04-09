#include <bits/stdc++.h>
using namespace std;

char ch, s[1000010];
int len = 1;
bool flag;

int main()
{
    freopen("nigeru.in", "r", stdin);
    freopen("nigeru.out", "w", stdout);
    while (scanf("%c", &ch) != EOF)
    {
        if (!flag)
        {
            if (ch >= 'a' && ch <= 'z')
            {
                ch -= 32;
                flag = true;
            }
            if (ch >= 'A' && ch <= 'Z')
                flag = true;
            printf("%c", ch);
            continue;
        }
        if (ch >= 'A' && ch <= 'Z')
            ch += 32;
        printf("%c", ch);
        if (ch == '.')
            flag = false;
    }
    return 0;
}