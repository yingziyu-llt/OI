#include <cstdio>

inline int Min( int a, int b ) { return a < b? a: b; }

const int N = 1100;

int n;
int f[N][2];

// Edge Start 
struct edge {
	int next, to;
} e[ N << 1 ];
int ehead[N], ecnt;

inline void add_edge( int now, int to ) {
	ecnt ++;
	e[ecnt].to = to;
	e[ecnt].next = ehead[now];
	ehead[now] = ecnt;
}
// Edge End

void dfs( int now, int la ) {
	f[now][1] = 1;
	for( int i = ehead[now]; i; i = e[i].next ) {
		if( e[i].to == la ) 
			continue;
		dfs( e[i].to, now );
		f[now][0] += f[ e[i].to ][1];
		f[now][1] += Min( f[ e[i].to ][1], f[ e[i].to ][0] );
	}
}

int main() {
	freopen( "c.in", "r", stdin );
	freopen( "c.out", "w", stdout );
	scanf( "%d", &n );
	for( int i = 1, u, v; i < n; i ++ ) {
		scanf( "%d%d", &u, &v );
		add_edge( u, v );
		add_edge( v, u );
	}

	dfs( 1, 0 );
	printf( "%d", Min( f[1][0], f[1][1] ) );
	fclose( stdin );
	fclose( stdout );
	return 0;
}
