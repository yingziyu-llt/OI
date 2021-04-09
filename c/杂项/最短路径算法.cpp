//Bellman_Ford O(n * (n+m))
bool Bellman_Ford() 
{
    for(int u=1; u<=n; u++) dis[u] = INF;
    dis[SSS] = 0;

    for(int t=1; t<=n; t++) {
        for(int u=1; u<=n; u++) {
            for(edge *i=head[u]; i; i=i->next) {
                if(dis[i->v] > dis[u] + i->w) {
                    dis[i->v] = dis[u] + i->w;
                }
            }
        }
    }
    for(int u=1; u<=n; u++) {
        for(edge *i=head[u]; i; i=i->next) {
            if(dis[i->v] > dis[u] + i->w) {
                return true;
            }
        }
    }
    return false;
}

//SPFA O(kn)
int dis[maxn];
int Q[maxn];
int cnt[maxn];
bool inQ[maxn];

bool SPFA() {
    for(int u=1; u<=n; u++) dis[u] = INF;
    dis[SSS] = 0;

    int Head(0), Tail(0);
    Q[Tail++] = SSS , inQ[SSS] = true;

    while(Head != Tail) {
        int u = Q[Head];
        inQ[u] = false;
        if(++Head == n) Head = 0;

        for(edge *i=head[u]; i; i=i->next) {
            if(dis[i->v] > dis[u] + i->w) {
                dis[i->v] = dis[u] + i->w;
                if(++cnt[i->v] > n) return true;
                if(!inQ[i->v]) {
                    inQ[i->v] = true;
                    if(Head!=Tail && dis[i->v] <= dis[Q[Head]]) {
                        if(--Head < 0) Head = n - 1;
                        Q[Head] = i->v;
                    }
                    else {
                        Q[Tail] = i->v;
                        if(++Tail == n) Tail = 0;
                    }
                }
            }
        }
    }
    return false;
}

//Dijkstra O(n^2 + m)
int dis[maxn];
bool vis[maxn];

void Dijkstra() {
    for(int u=1; u<=n; u++) dis[u] = INF;
    dis[SSS] = 0;

    for(int t=1; t<n; t++) {
        int u = 1;
        for(int j=1; j<=n; j++) {
            if(!vis[j] && dis[j] < dis[u]) {
                u = j;
            }
        }
        vis[u] = true;
        for(edge *i=head[u]; i; i=i->next) {
            if(dis[i->v] > dis[u] + i->w) {
                dis[i->v] = dis[u] + i->w;
            }
        }
    }
}


//Dijkstra + Heap
#include <queue>
#define fst first
#define sed second

using namespace std;
typedef pair<int,int> PII;

int dis[maxn];
bool vis[maxn];
priority_queue<pair<int,int> > Q;

void Dijkstra() {
    for(int u=1; u<=n; u++) dis[u] = INF;
    dis[SSS] = 0 , Q.push(make_pair(-dis[SSS],SSS));

    while(!Q.empty()) {
        int u = Q.top().sed; Q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(edge *i=head[u]; i; i=i->next) {
            if(dis[i->v] > dis[u] + i->w) {
                dis[i->v] = dis[u] + i->w;
                Q.push(make_pair(-dis[i->v], i->v));
            }
        }
    }
}


//Floyd O(n^3)
void Floyd() {
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}
