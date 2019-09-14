#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// template {{{  0 
// using {{{ 1
using ll = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
// }}} 1
// definition {{{ 1
// scaning {{{ 2
#define Scd(x) scanf("%d", &x)
#define Scd2(x,y) scanf("%d%d", &x, &y)
#define Scd3(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define Scll(x) scanf("%lld", &x)
#define Scll2(x,y) scanf("%lld%lld", &x, &y)
#define Scll3(x,y,z) scanf("%lld%lld%lld", &x, &y, &z)
#define Scc(c) scanf("%c", &c);
#define Scs(s) scanf("%s", s);
#define Scstr(s) scanf("%s", &s);
// }}} 2
// constants {{{ 2
#define EPS (1e-7)
#define INF (2e9)
#define PI (acos(-1))
// }}} 2
// systems {{{ 2
#define Repe(x,y,z) for(ll x = z; x < y; x++)
#define Rep(x,y) Repe(x,y,0)
#define RRepe(x,y,z) for(ll x = y-z-1; x >= 0; x--)
#define RRep(x,y) RRepe(x,y,0)
// }}} 2
// output {{{ 2
#define YesNo(a) (a)?printf("Yes\n"):printf("No\n")
#define YESNO(a) (a)?printf("YES\n"):printf("NO\n")
// }}} 2
// }}} 1
// input {{{ 1
// }}} 1
// }}} 0

int main() {

    int C,N;
    Scd2(C,N);
    int n = N/2;

    static char p[1111][1111];
    Rep(i,N){
        Scs(p[i]);
    }

    int sym = 0;
    int ans = 0;

    vector<vi> d(n,vi(n,0));
    Rep(i,n){
        Rep(j,n){
            d[i][j] |= ( p[i][j] == '1'     ) << 0;
            d[i][j] |= ( p[N-i-1][j] == '1'   ) << 1;
            d[i][j] |= ( p[i][N-j-1] == '1'   ) << 2;
            d[i][j] |= ( p[N-i-1][N-j-1] == '1' ) << 3;
            if( d[i][j] == 0 || d[i][j] == 15 ) sym++;
        }
    }
    if( sym == n*n ) ans++;

    C--;
    int D;
    int r,c;
    int sh;
    Rep(i,C){
        Scd(D);
        Rep(i,D){
            Scd2(r,c);
            r--,c--; sh = 0;
            if( r >= n ) sh+=1, r=N-r-1;
            if( c >= n ) sh+=2, c=N-c-1;
            if( d[r][c] == 0 || d[r][c] == 15 ) sym--;
            d[r][c] ^= 1 << sh;
            if( d[r][c] == 0 || d[r][c] == 15 ) sym++;
        }
        if( sym == n*n ) ans++;
    }

    printf ("%d\n", ans );

    return 0;
}



