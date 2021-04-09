#include<sstream>
using namespace std;
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
int main()
{
	set<string> s;
	stringstream ss;
	string str,buf;
	while(cin >> str)
	{
		for(int i = 0;i < str.length();i++)
		{
			if(isalpha(str[i]))
				str[i] = tolower(str[i]);
			else
				str[i] = ' ';
			
		}
		ss << str;
		while(ss >> buf)
		{
			s.insert(buf);
		}
		ss.clear();
	}
	set<string>::iterator it = s.begin();
	while(it != s.end())
	{
		cout << *it << endl;
		it++;
	}
	return 0;
}