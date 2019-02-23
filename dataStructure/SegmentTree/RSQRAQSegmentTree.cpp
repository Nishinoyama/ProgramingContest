#include<bits/stdc++.h>

using namespace std;

const int INF = 0x7FFFFFFF;

using LL = long long int;
// ST {{{
struct ST{

    // RSumQ and RAddQ
    // 0-indexed
    //
    // Number, datA, Delay(lazy)
    int N;
    int height = 0;
    vector<LL> A;
    vector<LL> D;

    ST( int _N ):N(_N){
        build(_N);
    }

    ~ST(){
        // for( int i = 0; i < N<<1; i++ ){
        //     printf("A[%2d]:%lld D[%2d]:%lld\n", i, A[i], i, D[i]);
        // }
    }

    void build( int _N ){
        N = 1;
        height = 0;
        while( N < _N ) N <<= 1, height++;
        A.assign( N<<1,0 );
        D.assign( N<<1,0 );
    }

    // (a) -> x
    // Pay Attention Operator Precedence
    // (*,/,,+,-) --> (>>,<<) --> (>=,<=,,==,!=) --> (&,,^,,|) --> (&&,,||) --> ( a?b:c,+=,= )
    // example:
    //   X : A[a<<1+1]
    //   O : A[a<<1|1]
    void upd( int a, LL x){
        a += N;
        A[a] = A[a] + x;
        while( a >>= 1 ) {
            A[a] = A[a<<1|1] + A[a<<1|0];
        }
    }


    // evaluate [k]
    void eval( int k ){
        if( D[k] == 0 ) return;
        A[k] += D[k];
        if( k < N ){
            D[k<<1|1] += D[k] / 2;
            D[k<<1|0] += D[k] / 2;
        }
        D[k] = 0;
    }

    // eval downward until [k]
    void evaldown( int k ){
        for(int i = height; i>=0 ; i--) eval( k>>i );
    }

    void recalc( int k ){
        while( k>>=1 ) 
            A[k] = A[k<<1|1] + D[k<<1|1] + A[k<<1|0] + D[k<<1|0];
    }

    // upd query [a,b) add x
    void upd( int a, int b, LL x ){
        evaldown(a+=N);
        evaldown(b+=N-1);
        for( int t=1,l=a,r=b+1; l<r; l>>=1,r>>=1,t<<=1 ){
            if( l&1 ) D[l++] += x * t;
            if( r&1 ) D[--r] += x * t;
        }
        recalc(a);
        recalc(b);
    }

    // query [l,r)
    LL query(int l, int r){
        evaldown(l+=N);
        evaldown(r+=N-1);
        LL lv=0, rv=0;
        for( l,r++; l<r; l>>=1,r>>=1 ){
            if( l&1 ) lv = lv + A[l] + D[l++];
            if( r&1 ) rv = rv + A[--r] + D[r];
        }
        return lv + rv;
    }


};
// }}}

// solve :
// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G

int main() {

    int N,Q;
    int q,l,r;
    LL x;

    scanf("%d %d", &N, &Q );

    ST st(N);
    for (int i = 0; i < Q; i++){
        scanf("%d", &q );
        if( q ){
            scanf("%d %d", &l, &r);
            printf( "%lld\n", st.query(--l,r) );
        }else{
            scanf("%d %d %lld", &l, &r, &x);
            st.upd( --l,r,x );
        }
    }

    return 0;
}
