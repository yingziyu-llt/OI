#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	float a[100];
	int b[100];
	for(int i = 0;i < n;i++)
		scanf("%f%d",&a[i],&b[i]);
	float t = 0,s = 0;
	for(int i = 0;i < n;i++)
	{
		t += a[i] * b[i];
		s += b[i];
	}
	printf("%.1f",t / s);
	return 0;
}
