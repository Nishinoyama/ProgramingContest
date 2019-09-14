// tag:HLDecomposition,LazySegmentTree

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
    // 元の木の [u,v] 辺の f を求める
    // f(l,r) -> [l,r]のf
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

// {{{ SegmentTree (LazySegTree) 
// セグ木は結合律やらが～とか言ってたら実際その通りだったの巻
//-+-+-+-+-+-+-+-+-+-+-+-+-
// 遅延セグ木
// T := 要素
// E := 作用素(評価)
template <typename T, typename E>
struct SegmentTree{
    int n;
    using F = function<T(T,T)>;
    using G = function<T(T,E)>;
    using H = function<E(E,E)>;
    using P = function<E(E,int)>;
    F f; // 二値結合関数 T + T  -> T
    G g; // 本値作用関数 T <- E -> T
    H h; // 作用作用関数 E * E  -> E
    P p; // 作用多用関数 E ^ N  -> E
    T te; // Tの単位元 f(T,te) = T
    E ee; // Eの単位元 g(T,ee) = T
    vector<T> data; // データ
    vector<E> lazy; // 遅延評価
    SegmentTree( F f, G g, H h, T te, E ee , P p ) :
        f(f) , g(g) , h(h) , te(te) , ee(ee) , p(p) {}

    void build( vector<T> v ){
        int n_ = v.size();
        n = 1;
        while( n < n_ ) n<<=1;
        data.resize(2*n,te);
        lazy.resize(2*n,ee);
        for( int i = 0; i < n_ ; i++ ) data[n+i] = v[i];
        for( int i = n-1; i > 0 ; i-- ) data[i] = f( data[i*2] , data[i*2+1] );
    }

    // 遅延評価の実行
    // k番目 [l,r) のデータ
    void eval( int k, int l, int r){
        if( lazy[k] != ee ){
            // データの包括量に応じて評価
            data[k] = g( data[k] , p( lazy[k] , (r-l) ) );
            // 最下位じゃないなら子へ
            if( r-l > 1 ){
                lazy[2*k] = h(lazy[k*2] , lazy[k] );
                lazy[2*k+1] = h(lazy[k*2+1] , lazy[k] );
            }
            // 伝搬後は自分の評価を0にする
            lazy[k] = ee;
        }
    }

    // 区間加算（評価）
    void add( int a, int b, E x, int k=1, int l = 0, int r = -1 ){
        if( r == -1 ) r = n;

        // とりあえず遅延評価
        eval( k,l,r );

        // 範囲外ならなにもしない
        if( b <= l || r <= a ) return;
        // 範囲内ならそのまま評価
        if( a <= l && r <= b ){
            lazy[k] = x;
            eval(k,l,r);
        }else{
            add( a,b,x, 2*k, l, (l+r)/2 );
            add( a,b,x, 2*k+1, (l+r)/2, r );
            data[k] = f( data[2*k] , data[2*k+1] );
        }
    }

    T query( int a, int b, int k=1, int l = 0, int r = -1 ){
        if( r == -1 ) r = n;

        // 範囲外なら単位元返し
        if( b <= l || r <= a ) return te;
        // 大丈夫ならそのまま評価
        eval(k,l,r);
        // 範囲内ならそのまま返し
        if( a <= l && r <= b ){
            return data[k];
        }else{
            T tl = query( a,b, 2*k, l, (l+r)/2 );
            T tr = query( a,b, 2*k+1, (l+r)/2, r );
            return f(tl,tr);
        }
    }

};

// }}}

int N,Q;
int ans;
vl v;
vl vv;

int main() {

    Scd2(N,Q);
    v.resize(N);
    vv.resize(N);
    Rep(i,N) Scll(v[i]);

    HLD hld(N);

    int u,v;
    Rep(i,N-1) {
        Scd2(u,v);
        u--,v--;
        hld.add_edge(u,v);
    }

    hld.build();

    auto f = []( ll a, ll b ){ return a+b; };
    auto g = []( ll a, ll b ){ return b == INF ? a : b; };
    auto h = []( ll a, ll b ){ return b == INF ? a : b; };
    auto p = []( ll a, int b ){ return a * b; };
    SegmentTree<ll,ll> ST(f,g,h,0,INF,p);
    Rep(i,N){
        vv[hld.vid[i]] = ::v[i];
        // printf ("vid[%lld]<->%d\n", i, hld.vid[i] );
    }
    ST.build( vv );

    int q;
    int x;
    Rep(i,Q){
        Rep(i,ST.n*2){
            printf ("d[%lld] = %lld\n", i, ST.data[i] );
        }
        Scd(q);
        Scd2(u,v);
        Scd(x);
        u--,v--;
        if( q == 1 ) {
            auto hldf = [&]( int l, int r ){
                 ST.add(u,v+1,x);
            };
            hld.for_each_vertex( u, v, hldf );
        }else if( q == 2 ){
            ans = 0;
            auto hldf = [&]( int l, int r ){
                ans += ST.query(l,r);
            };
            hld.for_each_vertex( u, v, hldf );
            printf ("%d\n", ans );
        }
    }


    return 0;
}



