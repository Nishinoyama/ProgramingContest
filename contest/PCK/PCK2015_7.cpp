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

struct UF{
    vi par;
    vi rank;

    UF( int n ){
        init(n);
    }

    void init( int n ){
        par.assign(n,0);
        for( int i = 0; i < n; i++ ) par[i] = i;
        rank.assign(n,0);
    }

    int find( int x ){
        if( par[x] == x ) return x;
        else return par[x] = find(par[x]);
    }

    int unite( int x, int y ){
        x = find(x);
        y = find(y);
        if( x == y ) return -1;
        if( rank[x] < rank[y] ){
            par[x] = y;
        }else{
            par[y] = x;
            if( rank[x] == rank[y] ) rank[x]++;
        }
        return 1;
    }

    bool same( int x, int y ) {
        return find(x) == find(y);
    }

};

int main() {

    int N,M,K;
    Scd3(N,M,K);

    UF u(N+M);
    Repe(i,N+M,N) u.rank[i] = INF;

    int q,a,b;
    Rep(i,K){
        Scd3(q,a,b);
        a--,b--;
        if( q == 1 ){
            int xa = u.find(a);
            int xb = u.find(b);
            if( xa >= N && xb >= N && xa != xb ) { 
                printf ("%lld\n", i+1);
                return 0;
            }
            u.unite(a,b);
        }else{
            int xa = u.find(a);
            int xb = b+N;
            if( xa >= N && xb >= N && xa != xb ) { 
                printf ("%lld\n", i+1);
                return 0;
            }
            u.unite(a,b+N);
        }
    }

    printf ("%d\n", 0);

    return 0;
}



