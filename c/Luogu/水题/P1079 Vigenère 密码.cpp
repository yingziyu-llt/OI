#include<stdio.h>
#include<string.h>
using namespace std;
char key[110],s[1010];
char kk[28][28]=
{
	"abcdefghijklmnopqrstuvwxyz",
	"bcdefghijklmnopqrstuvwxyza",
	"cdefghijklmnopqrstuvwxyzab",
	"defghijklmnopqrstuvwxyzabc",
	"efghijklmnopqrstuvwxyzabcd",
	"fghijklmnopqrstuvwxyzabcde",
	"ghijklmnopqrstuvwxyzabcdef",
	"hijklmnopqrstuvwxyzabcdefg",
	"ijklmnopqrstuvwxyzabcdefgh",
	"jklmnopqrstuvwxyzabcdefghi",
	"klmnopqrstuvwxyzabcdefghij",
	"lmnopqrstuvwxyzabcdefghijk",
	"mnopqrstuvwxyzabcdefghijkl",
	"nopqrstuvwxyzabcdefghijklm",
	"opqrstuvwxyzabcdefghijklmn",
	"pqrstuvwxyzabcdefghijklmno",
	"qrstuvwxyzabcdefghijklmnop",
	"rstuvwxyzabcdefghijklmnopq",
	"stuvwxyzabcdefghijklmnopqr",
	"tuvwxyzabcdefghijklmnopqrs",
	"uvwxyzabcdefghijklmnopqrst",
	"vwxyzabcdefghijklmnopqrstu",
	"wxyzabcdefghijklmnopqrstuv",
	"xyzabcdefghijklmnopqrstuvw",
	"yzabcdefghijklmnopqrstuvwx",
	"zabcdefghijklmnopqrstuvwxy"
};
char out_key(char k,char c)
{
	if(c >= 'A' && c <= 'Z')
	{
		int cc = kk[k - 'a'][c - 'A'] - 'a' + 'A';
		return cc;
	}
	else
	{
		int cc = kk[k - 'a'][c - 'a'];
		return cc;
	}
}
int main()
{
	scanf("%s",key);
	scanf("%s",s);
	int key_len = strlen(key);
	int s_len = strlen(s);
	int now = 0;
	for(int i = 0;i < key_len;i++)
	{
		if(key[i] >= 'A' && key[i] <= 'Z') key[i] = key[i] - 'A' + 'a';
	}
	for(int i = 0;i < s_len;i++)
	{
		s[i] = out_key(key[now],s[i]);
		now = (now + 1) % key_len;
	}
	for(int i = 0;i < s_len;i++)
		putchar(s[i]);
	return 0;
}