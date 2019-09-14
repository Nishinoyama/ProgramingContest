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

int A,B;
vector<vi> dp( 2002, vi( 2002 , 0 ) );
vi a;
vi b;

int dps( int ai, int bi, bool in ){
    if( ai == A && bi == B ) return 0;
    if( dp[ai][bi] ) return dp[ai][bi];
    if( in ){
        int r1 = ai != A ? dps(ai+1,bi,!in)+a[ai] : -INF;
        int r2 = bi != B ? dps(ai,bi+1,!in)+b[bi] : -INF;
        return dp[ai][bi] = max( r1 , r2 );
    }else{
        int r1 = ai != A ? dps(ai+1,bi,!in) : INF;
        int r2 = bi != B ? dps(ai,bi+1,!in) : INF;
        return dp[ai][bi] = min( r1, r2 );
    }
}

int main() {

    Scd2(A,B);

    a.assign(A,0);
    b.assign(B,0);

    Rep(i,A) Scd(a[i]);
    Rep(i,B) Scd(b[i]);

    printf ("%d\n", dps(0,0,1) );

    // Rep(i,A+1){
    //     Rep(k,B+1){
    //         printf ("%3d", dp[i][k] );
    //     }
    //     printf ("\n");
    // }

    return 0;
}



