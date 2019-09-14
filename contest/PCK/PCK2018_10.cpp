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

// {{{ HLD
struct HLD{
    // 森（木）を高さlogN程の木に成分分解します。
    int N; // 頂点数
    vector<vector<int> > e; // 辺

    // HLD前
    vector<int> sub; //部分木のサイズ
    vector<int> pare;//親のid
    vector<int> dep; //深さ

    // HLD後
    // vector<int> hvy; //hevyPathの次の頂点id
    vector<int> vid; //HLD後の頂点id
    vector<int> head;//HLD後の各成分の根
    vector<int> type;//森をHL分解するときの属する木の番号
    vector<int> inv; //HLD前の頂点id(vidの逆)

    // HLD(){}
    HLD( int n ):
        N(n), e(n), sub(n,1), pare(n), dep(n),
        vid(n,-1), head(n), type(n), inv(n){}

    void add_edge( int u, int v ){
        e[u].push_back(v);
        e[v].push_back(u);
    }

    // 再帰でする、Heavy-Lightパスの集計
    // e[v][0] を Heavy辺にする
    void dfs_sz( int from ){
        for( int &to : e[from] ){
            if( to == pare[from] ) continue; //逆走防止
            pare[to] = from;
            dep[to] = dep[from] + 1;
            dfs_sz( to );
            sub[from] += sub[to];
            if( sub[to] > sub[e[from][0]] ) swap( to, e[from][0] );
        }
    }

    // 元の木とHLD後の木を関連付ける
    void dfs_hld( int from, int c, int& pos ){
        // printf ("dfs_vid[%d] = %d\n", from, pos );
        vid[from] = pos++;
        inv[vid[from]] = from;
        type[from] = c;
        for( int to : e[from] ){
            if( to == pare[from] ) continue;
            // printf ("dfs_%d -> %d\n", from, to );
            head[to] = ( to == e[from][0] ? head[from] : to );
            dfs_hld( to, c, pos );
        }
    }

    // 入力より、HLD実施
    void build( vector<int> rs=vector<int>(1,0) ){
        int c = 0, pos = 0;
        for( int r : rs ){
            dfs_sz(r);
            head[r] = r;
            dfs_hld(r,c++,pos);
        }
    }

    //for_each(vertex)
    // 元の木の [u,v) の f を求める
    // f(l,r) -> [l,r)のf
    void for_each_vertex( int u, int v, const function<void(int,int)>& f ){
        while(1){
            if( vid[u] > vid[v] ) swap(u,v);
            f( max(vid[head[v]],vid[u]), vid[v]+1 );
            printf ("[%d,%d)\n", max(vid[head[v]],vid[u]), vid[v]+1 );
            if( head[u] != head[v] ) v = pare[head[v]];
            else break;
        }
    }

    //for_each(edge)
    // 元の木の [u,v) 辺の f を求める
    // f(l,r) -> [l,r)のf
    void for_each_edge( int u, int v, const function<void(int,int)>& f ){
        while(1){
            if( vid[u] > vid[v] ) swap(u,v);
            if( head[u] != head[v] ) {
                f( vid[head[v]], vid[v]+1 );
                printf ("[%d,%d)\n", vid[head[v]], vid[v]+1 );
                v = pare[head[v]];
            }else{
                if( u != v ) f( vid[u]+1, vid[v]+1 ), printf ("[%d,%d)\n", vid[u]+1, vid[v]+1 );
                break;
            }
        }
    }

    // 副産物.LCAがO(logN)
    int lca( int u, int v ){
        while(1){
            if( vid[u] > vid[v] ) swap(u,v);
            if( head[u] == head[v] ) return u;
            v = pare[head[v]];
        }
    }

    int distance( int u, int v ){
        return dep[u]+dep[v]-2*dep[lca(u,v)];
    }

};
// }}}

vector<vi> e;
vi vw;
vi pare;

vi sumsub;
void dfs( int from ){
    sumsub[from] += vw[from];
    for( int to : e[from] ){
        if(  )
        dfs( to );
        sumsub[from] += sumsub[to];
    }
}

int main() {

    int N;
    Scd(N);
    vw.assign(N);
    Rep(i,N) Scd(v[i]);
    e.assign(N);

    HLD hld(N);

    int x,y;
    Rep(i,N){
        Scd2(x,y);
        x--,y--;
        e[x].push_back(y);
        e[y].push_back(x);
        hld.add_edge(x,y);
    }

    hld.build(N);

    sumsub.assign(N);


    return 0;
}



