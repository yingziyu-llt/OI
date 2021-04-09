#include <cstdio>
#include <algorithm>

const int N = 210;

int T, n, m;
int a[N], b[N];

bool cmp( int a, int b ) { return a > b; }

int main() {
	freopen( "a.in", "r", stdin );
	freopen( "a.out", "w", stdout );
	scanf( "%d", &T );
	while( T -- ) {
		bool flag = false;

		scanf("%d%d", &n, &m );
		for( int i = 1; i <= n; i ++ ) 
			scanf( "%d", &a[i] );
		for( int i = 1; i <= m; i ++ ) 
			scanf( "%d", &b[i] );

		std::sort( a + 1, a + n + 1, cmp );
		std::sort( b + 1, b + m + 1 );

		for( int i = 1; i <= n; i ++ ) {
			for( int j = 1; j <= m; j ++ ) {
				if( b[j] == 0 ) 
					continue;
				b[j] --; a[i] --;
				if( a[i] == 0 ) 
					break;
			}
			if( a[i] > 0 ) {
				printf( "No\n" );
				flag = true;
			}
		}

		if( flag == false ) 
			printf( "Yes\n" );
	}

	fclose( stdin );
	fclose( stdout );
	return 0;
}
