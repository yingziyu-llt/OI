#include <cstdio>

char a;
bool end;

bool zm( char a ) {
	if( 'a' <= a && a <= 'z' ) 
		return true;
	if( 'A' <= a && a <= 'Z' ) 
		return true;
	return false;
}

char dx( char a ) {
	if( 'a' <= a && a <= 'z' ) {
		return a - 'a' + 'A';
	}
	else {
		return a;
	}
}

char xx( char a ) {
	if( 'a' <= a && a <= 'z' ) {
		return a;
	}
	else {
		return a - 'A' + 'a';
	}
}

int main() {
	freopen( "nigeru.in", "r", stdin );
	freopen( "nigeru.out", "w", stdout );

	end = true;
	while( a = getchar() ) {
		if( a <= 0 )
			break;
		if( zm(a) ) {
			if( end ) {
				end = false;
				putchar( dx(a) );
			}
			else {
				putchar( xx(a) );
			}
		}
		else {
			if( a == '.' )
				end = true;
			putchar( a );
		}
	}

	fclose( stdin );
	fclose( stdout );
	return 0;
}
