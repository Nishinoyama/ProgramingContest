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

    int N,M,V,P;
    Scd2(N,M); Scd2(V,P);

    vi a(N);
    vi b(N);
    Rep(i,N){
        Scd(a[i]);
    }

    sort( a.begin(), a.end() );
    reverse( a.begin(), a.end() );

    int l,r,c;
    bool ok;
    l = 0, r = N;
    // [l,r)
    while( r-l > 1 ){
        ok = false;
        c = (r+l)/2;

        int ac = a[c];
        int cnt = 0;
        Rep(i,N) {
            if( ac >= a[i] ) break;
            cnt++;
        }
        int B = cnt - V;
        int C = N - B;
        if( B < 0 ) { l = c; continue; }
        b.assign(B,0);
        Repe(i,B){
            b[i] = a[i+V-1] - ac;
        }

        if( C >= V ) { //投票度外視
            if( M >= b[0] ) ok = true;
        }else{
            int v = N-V;
            int ss = 0;
            rep(i,B) ss += b[i];
            if( ss )
        }
    }

    return 0;
}

