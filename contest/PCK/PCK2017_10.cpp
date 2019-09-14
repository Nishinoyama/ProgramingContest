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

struct SCC{
    int N; // 頂点数
    vector<vi> e;  //辺（有向）
    vector<vi> re; //逆辺
    vector<bool> used; //探索フラグ
    vector<int> vs; //帰りがけ順序

    int K; // SCC後頂点数
    vector<int> cmp; //SCC前頂点->SCC後の頂点変換
    vector<set<int>> se;  //SCC後辺

    SCC( int N ) : N(N){
        e.resize(N);
        re.resize(N);
        used.resize(N);
        vs.resize(0);
        cmp.resize(N);
    }
    void add_edge( int v, int w ){
        e[v].push_back(w);
        re[w].push_back(v);
    }
    void dfs( int v ){
        used[v] = true;
        for( int to : e[v] ){
            if( !used[to] ) dfs(to);
        }
        vs.push_back(v);
    }
    // k = SCC後の扱いメモ
    void rdfs( int v, int k ){
        used[v] = true;
        cmp[v] = k;
        for( int to : re[v] ){
            if( !used[to] ) rdfs(to,k);
        }
    }
    // 返り値=強連結成分数
    int build(){
        vs.clear();
        used.assign(N,0);
        for( int i = 0; i < N; i++ ) if( !used[i] ) dfs(i);
        used.assign(N,0);
        K = 0;
        for( int i = N-1; i >= 0; i-- ) if( !used[vs[i]] ) rdfs(vs[i],K++);

        se.resize(K);
        for( int i = 0; i < N; i++ ){
            for( int to : e[i] ) if( cmp[i] != cmp[to] ) se[cmp[i]].insert(cmp[to]);
        }
        return K;
    }
};

int main() {

    Scd2(N,M);

    SCC scc(N);

    int v,w;
    Rep(i,M){
        Scd2(v,w);
        scc.add_edge(v,w);
    }

    int K = scc.build();

    vi dimin(K,0);
    vi dimout(K,0);
    for( int i = 0; i < K; i++ ){
        for( int j : scc.se[i] ){
            dimin[j]++;
            dimout[i]++;
            // printf ("%d,%d ", i, j);
        }
        // printf ("\n");
    }

    int inm = 0, outm = 0;
    Rep(i,K){
        if( !dimin[i] ) inm++;
        if( !dimout[i] ) outm++;
    }
    if( K == 1 ) inm = outm = 0;
    printf ("%d\n", max(inm,outm) );



    return 0;
}




