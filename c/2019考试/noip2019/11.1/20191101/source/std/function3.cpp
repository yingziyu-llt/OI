#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 5;

const int nn = 2;
struct Matrix
{
    ll a[5][5], n;
    Matrix(ll x = 0, ll b = 0, ll c = 0, ll d = 0)
    {
        n = 2;
        a[1][1] = x; a[1][2] = b;
        a[2][1] = c; a[2][2] = d;
    }
    ll* operator[](int i)
    {
        return a[i];
    }
};

Matrix operator-(Matrix A, Matrix B)
{
    ll n = A.n;
    Matrix C;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            C[i][j] = ((A[i][j] - B[i][j]) % mod + mod) % mod;
    return C;
}

Matrix operator*(Matrix A, Matrix B)
{
    int n = A.n;
    Matrix C;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
    return C;
}

Matrix power(Matrix A, ll n, ll mod)
{
    Matrix C(1, 0, 0, 1);
    while (n)
    {
        if (n & 1) C = C * A;
        A = A * A;
        n >>= 1;
    }
    return C;
}

int main()
{
    int T;
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
    scanf("%d", &T);
    while (T--)
    {
        ll n, m;
        scanf("%lld%lld", &n, &m);
        Matrix A(0, 2, 1, 1);
        Matrix B = n & 1 ? Matrix(-1, 2, 1, 0) : Matrix(1, 0, 0, 1);
        A = power(A, n, mod) - B;
        A = power(A, m - 1, mod);
        ll ans = (A[1][1] + A[2][1]) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}
