#include <bits/stdc++.h>

using namespace std;

// UF{{{
struct UF{ 

    // Number , Parent , Rank
    int N;
    vector<int> P;
    vector<int> R;

    UF ( int _N ):N(_N){
        init(_N);
    }

    void init( int _N ){
        P.assign( _N,0 );
        for (int i = 0; i < _N; i++) P[i] = i;
        R.assign( _N,0 );
    }

    int find( int x ){
        if( P[x] == x ) return x;
        else return P[x] = find(P[x]);
    }

    bool unite( int a, int b ){
        a = find(a);
        b = find(b);
        if( a == b ) return false;
        else{
            if( R[a] < R[b] ){
                P[a] = b;
            }else{
                P[b] = a;
                if( R[a] == R[b] ) R[a]++;
            }
        }
        return true;
    }

    bool same( int a, int b ){
        return find(a) == find(b);
    }

};
// }}}

int main(){

    int N,Q;
    int q,a,b;

    scanf("%d %d", &N, &Q );

    UF u(N+1);
    for (int i = 0; i < N; i++){
        scanf("%d %d %d", &q, &a, &b );
        if( q ){
            printf ( u.same(a,b) ? "Yes%c" : "No%c" , 10 );
        }else{
            u.unite( a,b );
        }
    }


    return 0;
}

