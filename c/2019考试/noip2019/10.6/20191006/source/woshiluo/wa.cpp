#include <cstdio>
#include <algorithm>

const int N = 1e5 + 10;

int n, cnt;
int a[N], c[N], next[N], last[N];
struct node {
	int a, id;
} b[N];
bool ok[N];

bool cmp( node a, node b ) { return a.a > b.a; }

int main() {
	freopen( "wa.in", "r", stdin );
	freopen( "wa.out", "w", stdout );
	scanf( "%d", &n );
	for( int i = 1; i <= n; i ++ ) {
		scanf( "%d", &a[i] );
		b[i] = (node) { a[i], i };
		if( i != 1 ) 
			last[i] = i - 1;
		if( i != n ) 
			next[i] = i + 1;
	}
	std::sort( b + 1, b + n + 1, cmp );

	for( int i = 1; i <= n; i ++ ) { 
		if( cnt == n ) 
			break;
		if( ok[ b[i].id ] == true )
			continue;
		if( next[ b[i].id ] == 0 ) 
			continue;
		c[ ++ cnt ] = a[ b[i].id ];
		c[ ++ cnt ] = a[ next[ b[i].id ] ];
		ok[ b[i].id ] = ok[ next[ b[i].id ] ]= true;
		int tmp = last[ b[i].id ];
		next[tmp] = next[ next[ b[i].id ] ];
		last[ next[tmp] ] = tmp;
	}

	if( cnt != n ) {
		for( int i = 1; i <= n; i ++ ) 
			if( ok[i] == false ) 
				c[ ++ cnt ] = a[i];
	}
		
	for( int i = 1; i <= n; i ++ ) 
		printf( "%d ", c[i] );

	fclose( stdin );
	fclose( stdout );
	return 0;
}
