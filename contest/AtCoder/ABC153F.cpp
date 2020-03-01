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

    int N,D,A;
    Scd3(N,D,A);
    vii h(N);
    int X,H;
    Rep(i,N){
        Scd2(X,H);
        h[i] = {X,H};
    }
    sort( h.begin(), h.end() );

    vl s(N+1);
    s[0] = h[0].second;
    Rep(i,N-1){
        s[i+1] = h[i+1].second - h[i].second;
    }

    ll l = 0;
    ll r = 0;
    ll bomb = 0;
    ll ans = 0;
    Rep(i,N){
        l = i;
        while( r < N && h[r].first <= h[l].first+2*D ){
            r++;
        }

        bomb = max( (s[i]+A-1)/A, 0ll );
        ans += bomb;
        s[l] -= bomb*A;
        s[r] += bomb*A;
        s[l+1] += s[l];
    }

    printf ("%lld\n", ans );

    return 0;
}

