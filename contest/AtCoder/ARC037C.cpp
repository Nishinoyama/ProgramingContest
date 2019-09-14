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

#define all(x) x.begin(),x.end()

int main() {

    int N;
    ll K;
    Scd(N);
    Scll(K);

    vl a(N);
    vl b(N);
    Rep(i,N) Scll(a[i]);
    Rep(i,N) Scll(b[i]);
    sort( all(a) );
    sort( all(b) );

    ll l = 1;
    ll r = 1e18; r+=7;
    ll m = 0;
    ll cnt = 0;
    // [l,r)
    while( r-l > 1 ){
        cnt = 0;
        m = ( r + l ) / 2;
        Rep(i,N){
            int li = -1;
            int ri = N;
            int mi = 0;
            while( ri-li > 1 ){
                mi = ( ri + li ) / 2;
                if( a[i]*b[mi] < m ) li = mi;
                else ri = mi;
            }
            cnt += ri;
        }
        // printf ("!%lld:%lld\n", m, cnt );
        if( cnt < K ) l = m;
        else r = m;
    }

    printf ("%lld\n", l );

    return 0;
}



