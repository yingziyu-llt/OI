#include <stdio.h>
#include <string.h>
struct node
{
	node *nxt[26];
	int kind;
	int count;
};
node *head = new node;
void clean(node *a)
{
	for (int i = 0; i < 26; i++)
	{
		a->nxt[i] = NULL;
	}
	a->kind = 0;
	a->count = 1;
}
void cre(char a[])
{
	node *r = NULL;
	r = head;
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		if (r->nxt[a[i] - 'a'] == NULL)
		{
			r->nxt[a[i] - 'a'] = NULL;
			r->nxt[a[i] - 'a'] = new node;
			clean(r->nxt[a[i] - 'a']);
		}
		r = r->nxt[a[i] - 'a'];
	}
	r->kind = 2;
}
node *searchf(char a[])
{
	node *r = head;
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		if (r->nxt[a[i] - 'a'] != NULL)
			r = r->nxt[a[i] - 'a'];
		else
		{
			return NULL;
		}
	}
	return r->kind == 2 ? r : NULL;
}
int main()
{
	int n;
	scanf("%d", &n);
	clean(head);
	for (int i = 0; i < n; i++)
	{
		char a[100];
		memset(a, 0, sizeof(a));
		scanf("%s", &a);
		cre(a);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char a[100];
		memset(a, 0, sizeof(a));
		scanf("%s", a);
		node *x = searchf(a);
		if (x == NULL)
		{
			printf("WRONG\n");
		}
		else
		{
			switch (x->count)
			{
				case 1:
				{
					printf("OK\n");
					x->count++;
					break;
				}
				default:
				{
					printf("REPEAT\n");
					break;
				}
			}
		}
	}
	return 0;
}