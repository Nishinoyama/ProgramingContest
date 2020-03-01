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

    int N,M;
    Scd2(N,M);

    vector<vi> d(N,vi(N,1e9));
    vector<vii> e(N);
    Rep(i,N) d[i][i] = 0;

    int a,b,c;
    Rep(i,M){
        Scd3(a,b,c);
        a--,b--;
        d[a][b] = c;
        e[a].push_back(pii(b,c));
    }

    Rep(k,N) Rep(i,N) Rep(j,N){
        d[i][j] = min( d[i][j], d[i][k] + d[k][j] );
    }
    Rep(i,N) Rep(j,N) Rep(k,N){
        d[i][j] = min( d[i][j], d[i][k] + d[k][j] );
    }
    Rep(i,N) Rep(j,N) Rep(k,N){
        d[i][j] = min( d[i][j], d[i][k] + d[k][j] );
    }

    int ans = 0;
    Rep(from,N){
        for( pii tom : e[from] ){
            int to = tom.first;
            int di = tom.second;
            if( di > d[from][to] ){
                ans++;
            }
        }
    }

    printf ("%d\n", ans );

    return 0;
}

