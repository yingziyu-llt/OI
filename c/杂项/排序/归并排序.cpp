#include <stdio.h>
#include <stdlib.h>

/*by
���߱������С��
лл 
    */

int b[101] = {0};
void xsort(int a[], int left, int middle, int right)
{
	int i = left, j = middle + 1, k = left;
	while ((i <= middle) && (j <= right))
	{
		if (a[i] < a[j])
		{
			b[k++] = a[i++];
		}
		else
		{
			b[k++] = a[j++];
		}
	}
	while (i <= middle)
	{
		b[k++] = a[i++];
	}
	while (j <= right)
	{
		b[k++] = a[j++];
	}
	for (i = 1; i <= right; i++)
	{
		a[i] = b[i];
	}
}

void msort(int a[], int left, int right)
{
	int middle;
	middle = (left + right) / 2;
	if (left < right)
	{
		msort(a, left, middle);
		msort(a, middle + 1, right);
		xsort(a, left, middle, right);
	}
}
int main()
{
	int u, j, k, n, i, a[1001];
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	msort(a, 1, n);
	for (i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
