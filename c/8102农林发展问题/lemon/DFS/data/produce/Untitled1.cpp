#include <cstdio>

struct queue {
  int v[3];
}q[10000];
int V[3], head, tail, res[21];
int vis[21][21][21];
int min(int a, int b) { return a < b ? a : b; }

int main() {
  freopen("produce5.in", "r", stdin);
  freopen("produce5.out", "w", stdout);
  for (int i = 0; i < 3; i++)
    scanf("%d", &V[i]);
  q[++tail].v[2] = V[2];
  //q[1].v[2] = V[2]
  while (head < tail) {
  	int v[3] = {q[++head].v[0], q[head].v[1], q[head].v[2]};
  	if (!v[0]) res[v[2]] = 1;
  	for (int i = 0; i < 3; i++)
  	  for (int j = 0; j < 3; j++)//从i桶倒到j桶 
  	    if (i != j && v[i] && v[j] != V[j]) {
  	      ++tail; 
		  q[tail] = q[head];
  	      int milk = min(v[i], V[j]-v[j]);
  	      q[tail].v[i] -= milk;
  	      q[tail].v[j] += milk;
  	      if (vis[q[tail].v[0]][q[tail].v[1]][q[tail].v[2]]) tail--;//访问过，队尾减1 
  	      vis[q[tail].v[0]][q[tail].v[1]][q[tail].v[2]] = 1; 
  	    }
  }
  for (int i = 0; i <= 20; i++)
    if (res[i]) printf("%d ", i);
  return 0;
}
