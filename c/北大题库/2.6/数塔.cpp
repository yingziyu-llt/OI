#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n, x, y;
	int a[71][71][3];
	cin >> n;
	memset(a, 0, sizeof(a));
	for (x = 1; x <= n; x++) //���������ĳ�ʼֵ
		for (y = 1; y <= x; y++)
		{
			cin >> a[x][y][1];
			a[x][y][2] = a[x][y][1];
			a[x][y][3] = 0;
		}
	for (x = n - 1; x >= 1; x--)
		for (y = 1; y <= x; y++)
			if (a[x + 1][y][2] > a[x + 1][y + 1][2]) //ѡ��·�����������·��ֵ
			{
				a[x][y][2] = a[x][y][2] + a[x + 1][y][2];
				a[x][y][3] = 0;
			}
			else
			{
				a[x][y][2] = a[x][y][2] + a[x + 1][y + 1][2];
				a[x][y][3] = 1;
			}
	cout << a[1][1][2] << endl; //����������ֵ
	y = 1;
	for (x = 1; x <= n - 1; x++) //����������ֵ��·��
	{
		cout << a[x][y][1] << "-";
		y = y + a[x][y][3]; //��һ�е�����
	}
	cout << a[n][y][1] << endl;
}
