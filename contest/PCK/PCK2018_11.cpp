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
#define INF (1000000000l)
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

// {{{ Segment Tree

// {{{実装
// T : 要素
template <typename T>
struct SegmentTree{

    int leng;
    using F = function<T(T,T)>;
    F f; // T*T -> T
    T ti; // T の 単位元
    vector<T> data;

    SegmentTree( F f, T ti ) :
        f(f),ti(ti){}

    void init( int n ){
        leng = 1;
        while( leng < n ) leng*=2;
        data.assign(leng*2,ti);
    }

    void build( vector<T> v ){
        int n = v.size();
        init( n );
        for (int i = 0; i < n; i++) data[leng+i] = v[i];
        for (int i = leng-1; i > 0 ; i--)
            data[i] = f(data[i<<1],data[(i<<1)|1] );
    }

    void upda( int a, T x ){

        a += leng;
        data[a] = x;
        while( a >>= 1 ){
            data[a] = f( data[a<<1], data[(a<<1)|1] );
        }

    }

    // [a,b)の f(演算結果) を求める
    //data[k] を参照
    //l,r は data[k] の包括する範囲 [l,r)を示す
    //呼び出す時は query(a,b)でおｋ
    //サーチのイメージは上から下へ（親から子へ）
    T query(int a, int b, int k = 1, int l = 0, int r = -1 ){

        //どうしてもうまく行かなかったのでここで再呼び出し
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
};
// }}}

// }}}

ll K,N,Q;
int main() {

    Scll3(K,N,Q);
    using P = pair<ll,ll>;
    vector<P> a(N);
    Rep(i,N){
        ll x;
        Scll(x);
        if( x == 0 ) a[i] = P(0,1);
        else{
            x = (-x+K*INF)%K;
            a[i] = P(x,0);
        }
    }
    auto f = []( P a , P b ){
        P c;
        c.first = a.first;
        c.first += ( a.second ? -1 : 1 ) * b.first + K*INF;
        c.first %= K;
        c.second = a.second xor b.second;
        return c;
    };
    SegmentTree<P> s( f,P(0,0) );
    s.build( a );

    // Rep(i,s.leng*2){ printf ("data[%lld] = %lld,%lld\n", i, s.data[i].first, s.data[i].second ); }

    int l,r;
    while(Q--){
        Scd2(l,r);
        l--,r--;
        P lp = s.query(l,l+1);
        P rp = s.query(r,r+1);
        // printf ("lp = %lld,%lld\n", lp.first, lp.second );
        // printf ("rp = %lld,%lld\n", rp.first, rp.second );
        s.upda(l,rp);
        s.upda(r,lp);
        P ans = s.data[1];
        // printf ("ans = %lld,%lld\n", ans.first, ans.second );
        // Rep(i,s.leng*2){ printf ("data[%lld] = %lld,%lld\n", i, s.data[i].first, s.data[i].second ); }

        if( ans.second == 0 ){
            printf ("%lld\n", ans.first+1 );
        }else{
            printf ("%lld\n", -ans.first-1 );
        }
    }

    return 0;
}


