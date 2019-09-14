//Segment Tree

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

// {{{ Segment Tree

// T : 要素
template <typename T>
struct SegmentTree{

    int leng;
    using F = function<T(T,T)>;
    F f;  // T*T -> T
    T ti; // (T,f) の 単位元
    vector<T> data; // 1-indexed

    SegmentTree( F f, T ti ) :
        f(f),ti(ti){}

    void init( int n ){
        leng = 1;
        while( leng < n ) leng += leng;
        data.assign(leng*2,ti);
    }

    void build( vector<T> &v ){
        int n = v.size();
        init( n );
        for (int i = 0; i < n; i++) data[leng+i] = v[i];
        for (int i = leng-1; i > 0 ; i--)
            data[i] = f(data[i<<1],data[(i<<1)|1] );
    }

    // data[a] を x で 変更
    void upda( int a, T x ){

        a += leng;

        data[a] = x;

        while( a >>= 1 ){
            data[a] = f( data[a<<1] , data[(a<<1)|1] );
        }

    }

    // [a,b)の f(演算結果) を求める
    T query(int a, int b, int k = 1, int l = 0, int r = -1 ){

        if( r == -1 ) return query(a,b,k,l,leng);

        //今探すkでの範囲がオーバーしたら単位元をを返す
        if( a>=r || b<=l ) return ti;

        //範囲内ならそのまま返す
        else if( a<=l && b>=r ){
            return data[k];
        //そうでもないなら子へ
        }else{
            T ld = query(a,b,k<<1,l,(l+r)/2);
            T rd = query(a,b,(k<<1)|1,(l+r)/2,r);
            return f(ld,rd);
        }

    }
    
    void dump(){
        for( int i = 1; i < leng*2; i++ ){
            cerr << "d[" << i << "]=" << data[i] << endl;
        }
    }
    
};

// }}}

int main() {

    int N,Q;
    Scd2(N,Q);

    using pii = pair<int,int>;
    vector<pii> a(N);
    int x;
    Rep(i,N) Scd(x), a[i] = { x, i+1 };

    auto f = []( pii a , pii b ){ return a.first < b.first ? a : b; };
    SegmentTree<pii> s( f,pii(INF,0) );
    s.build( a );

    int q,l,r;
    while(Q--){
        Scd3(q,l,r);
        l--,r--;
        if( q == 1 ) {
            pii la = pii(s.query(l,l+1).first,r+1);
            pii ra = pii(s.query(r,r+1).first,l+1);
            s.upda( l, ra );
            s.upda( r, la );
        }else if( q == 2 ){
            // printf ("%d,", s.query(l,r+1).first );
            printf ("%d\n", s.query(l,r+1).second );
        }
        s.dump();
    }

    return 0;
}


