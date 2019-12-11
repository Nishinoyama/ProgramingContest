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

    int H,W;
    Scd2(H,W);

    vector<vi> a(H,vi(W));
    vector<vi> b(H,vi(W));
    vector<vi> c(H,vi(W));
    Rep(i,H){
        Rep(j,W){
            Scd(a[i][j]);
        }
    }
    Rep(i,H){
        Rep(j,W){
            Scd(b[i][j]);
            c[i][j] = abs(a[i][j]-b[i][j]);
        }
    }

    static int dp[81][81][30000] = {};
    int offset = (W+H)*80+2;
    dp[0][0][offset+c[0][0]] = 1;
    dp[0][0][offset-c[0][0]] = 1;

    Rep(di,W+H)Rep(wi,W){
        int hi = di-wi;
        if( hi>=H ) continue;
        if( hi<0 ) break;
        Rep(ai,((W+H)*160+10)){
            // dp[hi][wi][ai];
            if( dp[hi][wi][ai] == 0 ) continue;
            if( hi != H-1 ) {
                dp[hi+1][wi][ai+c[hi+1][wi]] = 1;
                dp[hi+1][wi][ai-c[hi+1][wi]] = 1;
            }
            if( wi != W-1 ) {
                dp[hi][wi+1][ai+c[hi][wi+1]] = 1;
                dp[hi][wi+1][ai-c[hi][wi+1]] = 1;
            }
        }
    }

    int ans = INF;

    for( int ai = 0; ai < 30000; ai++ )
        if( dp[H-1][W-1][ai] ) ans = min(ans,abs(offset-ai));

    printf ("%d\n", ans );

    return 0;
}

