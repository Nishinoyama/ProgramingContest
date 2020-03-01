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

ll pow2( int i ){
    return 1LL<<i;
}

int popn( ll b ){
    int cnt = 1;
    while( b ) cnt++, b -= (-b)&b;
    return cnt;
}


int N;
int M;
vector<vi> e;
map<pii,int> eid;
vii q;
vi tmp;
vector<set<int>> egn;

bool dfs1( int from, int goal, int pare = -1 ){
    for( int to : e[from] ){
        if( to == pare ) continue;
        tmp.push_back(to);
        if( to == goal ) return true;
        else if( dfs1(to,goal,from) ){
            return true;
        }else{
            tmp.pop_back();
        }
    }
    return false;
}

void search( int i, int u, int v ){
    tmp.clear();
    tmp.push_back(u);
    dfs1(u,v);
    Rep(j,(tmp.size()-1)){
        egn[i].insert(eid[pii(tmp[j],tmp[j+1])]);
    }
}

set<int> amp( set<int>& a, set<int>& b ){
    set<int> c;
    for( int t : a ){
        c.insert(t);
    }
    for( int t : b ){
        c.insert(t);
    }
    return c;
}

int main() {

    Scd(N);

    e.resize(N);

    int u,v;
    Rep(i,N-1){
        Scd2(u,v);
        u--,v--;
        e[u].push_back(v);
        e[v].push_back(u);
        eid[pii(u,v)] = i;
        eid[pii(v,u)] = i;
    }

    int M;
    Scd(M);
    q.resize(M);
    egn.resize(M);
    Rep(i,M){
        Scd2(u,v);
        u--,v--;
        q[i] = pii(u,v);
        search(i,u,v);
    }

    ll ans = 0;
    int MM = 1<<M;
    Rep(bi,MM){
        int num = popn(bi);
        set<int> exs;
        Rep(mi,M){
            if( (1<<mi) & bi ){
                exs = amp( exs, egn[mi] );
            }
        }
        ans += (num%2?1:-1) * pow2( N-1-exs.size() );
    }

    printf ("%lld\n", ans );

    return 0;
}

