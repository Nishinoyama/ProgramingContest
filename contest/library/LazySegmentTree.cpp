#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;

// definition {{{ 1

// scaning {{{ 2
#define Scd(x) scanf("%d", &x)
#define Scd2(x,y) scanf("%d%d", &x, &y)
#define Scd3(x,y,z) scanf("%d%d%d", &x, &y, &z)

#define Scll(x) scanf("%llu", &x)
#define Scll2(x,y) scanf("%llu%llu", &x, &y)
#define Scll3(x,y,z) scanf("%llu%llu%llu", &x, &y, &z)

#define Scc(c) scanf("%c", &c);
#define Scs(s) scanf("%s", s);
#define Scstr(s) scanf("%s", &s);
// }}} 2

// constants {{{ 2
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
// }}} 2

// systems {{{ 2
#define Rep(x,y) for(int x = 0; x < y; x++)
#define Repe(x,y,z) for(int x = z; x < y; x++)
// }}} 2

// output {{{ 2
#define YesNo(a) (a)?printf("Yes\n"):printf("No\n");
// }}} 2

// }}} 1

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
        data.resize(2*n-1,te);
        lazy.resize(2*n-1,ee);
        for( int i = 0; i < n_ ; i++ ) data[n-1+i] = v[i];
        for( int i = n-2; i >= 0 ; i-- ) data[n-1+i] = f( data[i*2+1] , data[i*2+2] );
    }

    // 遅延評価の実行
    // k番目 [l,r) のデータ
    void eval( int k, int l, int r){
        if( lazy[k] != ee ){
            // データの包括量に応じて評価
            data[k] = g( data[k] , p( lazy[k] , (r-l) ) );
            // 最下位じゃないなら子へ
            if( r-l > 1 ){
                lazy[2*k+1] = h(lazy[k*2+1] , lazy[k] );
                lazy[2*k+2] = h(lazy[k*2+2] , lazy[k] );
            }
            // 伝搬後は自分の評価を0にする
            lazy[k] = ee;
        }
    }

    // 区間加算（評価）
    void add( int a, int b, E x, int k=0, int l = 0, int r = -1 ){
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
            add( a,b,x, 2*k+1, l, (l+r)/2 );
            add( a,b,x, 2*k+2, (l+r)/2, r );
            data[k] = f( data[2*k+1] , data[2*k+2] );
        }
    }

    T query( int a, int b, int k=0, int l = 0, int r = -1 ){
        if( r == -1 ) r = n;

        // 範囲外なら単位元返し
        if( b <= l || r <= a ) return te;
        // 大丈夫ならそのまま評価
        eval(k,l,r);
        // 範囲内ならそのまま返し
        if( a <= l && r <= b ){
            return data[k];
        }else{
            T tl = query( a,b, 2*k+1, l, (l+r)/2 );
            T tr = query( a,b, 2*k+2, (l+r)/2, r );
            return f(tl,tr);
        }
    }

};

// }}}

ll INFI = 2 << 15;
int main() {

    int N,Q;
    Scd2(N,Q);

    auto f = []( ll a, ll b ){ return a+b; };
    auto g = []( ll a, ll b ){ return b == INFI ? a : b; };
    auto h = []( ll a, ll b ){ return b == INFI ? a : b; };
    auto p = []( ll a, int b ){ return a; };
    SegmentTree<ll,ll> ST(f,g,h,0,INFI,p);
    ST.build( vector<ll>(N,INFI) );

    int q,s,t,x;
    Rep(qi,Q){
        Scd(q);
        if(q){
            Scd2(s,t);
            printf ("%llu\n", ST.query(s-1,t));
        }else{
            Scd3(s,t,x);
            ST.add( s-1, t, x );
        }
    }

    return 0;
}

