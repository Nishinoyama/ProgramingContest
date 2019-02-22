#include<bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x7FFFFFFF;

// ST {{{
struct ST{

    // RMinQ
    // 0-indexed
    //
    // Number, datA, Delay(lazy)
    // TODO develop delay
    int N;
    vector<int> A;
    vector<int> D;

    ST( int _N ):N(_N){
        build(_N);
    }

    void build( int _N ){
        N = 1;
        while( N < _N ) N <<= 1;
        A.assign( N<<1,INF );
        D.assign( N<<1,0 );
    }

    // (a) -> x
    // Pay Attention Operator Precedence
    // (*,/,,+,-) --> (>>,<<) --> (>=,<=,,==,!=) --> (&,,^,,|) --> (&&,,||) --> ( a?b:c,+=,= )
    // example:
    //   X : A[a<<1+1]
    //   O : A[a<<1|1]
    void upd( int a, int x){
        a += N;
        A[a] = x;
        while( a >>= 1 ) {
            A[a] = min( A[a<<1|1], A[a<<1|0] );
        }
    }

    // query [l,r)
    int query(int l, int r){
        int lv = INF, rv = INF;
        for( l+=N,r+=N; l<r; l>>=1,r>>=1 ){
            if( l&1 ) lv = min( lv, A[l++] );
            if( r&1 ) rv = min( rv, A[--r] );
        }
        return min( lv,rv );
    }


};
// }}}

// solve :
// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A

int main() {

    int N,Q;
    int q,l,r,a,x;

    scanf("%d %d", &N, &Q );

    ST st(N);
    for (int i = 0; i < Q; i++){
        scanf("%d", &q );
        if( q ){
            scanf("%d %d", &l, &r);
            printf( "%d\n", st.query(l,++r) );
        }else{
            scanf("%d %d", &a, &x);
            st.upd( a,x );
        }
    }

    return 0;
}

