#include <cstdio>

inline int Max( int a, int b ) { return a > b? a: b; }
inline int Min( int a, int b ) { return a < b? a: b; }

const int N = 10 + 5;

int n, m, ans;
int a[N][N], base[N], cnt[3];


void check() {
	int res = 0;
	for( int i = 1; i <= m; i ++ ){
		cnt[0] = cnt[1] = cnt[2] = 0;
		for( int j = 1; j <= n; j ++ ) {
			int tmp = a[j][i] + base[j];
			if( tmp <= 12 ) {
				cnt[ tmp % 3 ] ++;
			}
		}
		res += Max( cnt[0], Max( cnt[1], cnt[2] ) );
	}
	ans = Max( ans, res );
}

void dfs( int now ) {
	if( now == n + 1 ) {
		check();
		return;
	}
	for( int i = 0; i <= 2; i ++ ) {
		base[now] = i;
		dfs( now + 1 );
	}
}

int main() {
	freopen( "haji.in", "r", stdin );
	freopen( "haji.out", "w", stdout );

	scanf( "%d%d", &n, &m );
	for( int i = 1; i <= n; i ++ ) {
		for( int j = 1; j <= m; j ++ ) {
			scanf( "%d", &a[i][j] );
		}
	}

	dfs( 1 );

	printf( "%d", ans );

	fclose( stdin );
	fclose( stdout );
	return 0;
}
