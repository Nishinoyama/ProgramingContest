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

    int L;
    Scd(L);

    vi a(L);

    Rep(i,L){
        Scd(a[i]);
    }

    static ll dp[5][222222] = {};
    Rep(i,5) Rep(j,L+1) dp[i][j] = 1e16;
    dp[0][0] = 0;

    int co = 0;
    Rep(i,L){

        co = a[i];
        dp[0][i+1] = min( dp[0][i+1], dp[0][i] + co );

        co = a[i]==0? 2 : a[i]%2;
        dp[1][i+1] = min( dp[1][i+1], dp[0][i] + co );
        dp[1][i+1] = min( dp[1][i+1], dp[1][i] + co );

        co = (a[i]%2)^1;
        dp[2][i+1] = min( dp[2][i+1], dp[0][i] + co );
        dp[2][i+1] = min( dp[2][i+1], dp[1][i] + co );
        dp[2][i+1] = min( dp[2][i+1], dp[2][i] + co );

        co = a[i]==0? 2 : a[i]%2;
        dp[3][i+1] = min( dp[3][i+1], dp[0][i] + co );
        dp[3][i+1] = min( dp[3][i+1], dp[1][i] + co );
        dp[3][i+1] = min( dp[3][i+1], dp[2][i] + co );
        dp[3][i+1] = min( dp[3][i+1], dp[3][i] + co );

        co = a[i];
        dp[4][i+1] = min( dp[4][i+1], dp[0][i] + co );
        dp[4][i+1] = min( dp[4][i+1], dp[1][i] + co );
        dp[4][i+1] = min( dp[4][i+1], dp[2][i] + co );
        dp[4][i+1] = min( dp[4][i+1], dp[3][i] + co );
        dp[4][i+1] = min( dp[4][i+1], dp[4][i] + co );

    }

    ll ans = 1e15;

    Rep(i,5) ans = min( ans, dp[i][L] );

    printf ("%lld\n", ans );

    return 0;
}

