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

int N,M;
vector<vi> e;
vii d;

int main() {

    Scd2(N,M);
    d.resize(N);
    e.resize(N);
    Rep(i,N) Scd(d[i].first), d[i].second = i;

    vi col(N,-1);
    vi co(N);
    vii exs(M);
    map<pii,int> ans;

    int u,v;
    Rep(i,M){
        Scd2(u,v);
        u--,v--;
        e[u].push_back(v);
        e[v].push_back(u);
        exs[i] = pii(u,v);
        ans[pii(u,v)] = 1e9;
        ans[pii(v,u)] = 1e9;
    }

    bool ok = true;
    sort( d.begin(), d.end() );
    Rep(i,N) {
        co[d[i].second] = i;
    }
    // コストが小さい順に見ていく
    Rep(i,N){
        int dist = d[i].first;
        int from = d[i].second;
        if( col[from] != -1 ) continue;
        ok = false;
        for( int to : e[from] ){
            if( dist >= d[co[to]].first && ( col[to] == -1 || col[from] != col[to] ) ){
                // printf ("%d->%d\n", from, to );
                if( col[to] != -1 ) col[from] = col[to]^1;
                else col[from] = 0, col[to] = 1;
                ans[pii(from,to)] = dist;
                ans[pii(to,from)] = dist;
                ok = true;
                break;
            }
        }
        if( !ok ){
            printf ("%d\n", -1 );
            return 0;
        }
    }

    Rep(i,N){
        if( col[i] == -1 ){
            printf ("%d\n", -1 );
            return 0;
        }
    }
    Rep(i,N){
        printf ("%c", col[i]?'B':'W');
    }
    printf ("\n");
    Rep(i,M){
        printf("%d\n", ans[exs[i]] );
    }


    return 0;
}

