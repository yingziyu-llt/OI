#include <cstdio>

const int N = 1e5 + 1e4;

int T, n;
int a[N];

int main() {
	scanf( "%d", &T );
	while( T -- ) {
		scanf( "%d", &n );
		long long tmp = 1;
		long long k = 1;
		for( int i = 1; i <= n; i ++ ) {
			scanf( "%d", &a[i] );
			tmp *= 1LL * i;
			k += i * ( i + 1 );
		}

		
	}
}
