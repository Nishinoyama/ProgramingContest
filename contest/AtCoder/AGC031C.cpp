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

int popn( int b ){
    int cnt = 0;
    while(b) cnt++, b-=b&(-b);
    return cnt;
}

int N,A,B;
int b;
// int cnt = 0;
// void dfsfin( int ans ){
//     printf ("%d ", ans );
//     printf ("%d ", ans xor bi);
// }
// void dfs( int ans, int i ){
//     if( i == N ) {
//         dfsfin(ans);
//         return;
//     }
//     int b = 1<<i;
//     char c = cnt++==0?'\n':' ';
//     if( bi&b ) dfs(ans,i+1);
//     else{
//         dfs(ans, i+1);
//         dfs(ans xor b , i+1);
//     }
// }

int streak1( int b ){
    int cnt = 0;
    while(b&1) cnt++, b>>=1;
    return cnt;
}

int main() {

    Scd3(N,A,B);
    b = A xor B;

    if( popn(b)%2 != 1 ) {
        YESNO(false);
        return 0;
    }

    YESNO(true);


    int M = 1<<N;
    int L = popn(b); // 
    int R = N-L;

    vi l(L);
    vi r(R);
    int li=0, ri=0;
    Rep(i,N){
        if( (1<<i) & b ) l[li++] = i;
        else r[ri++] = i;
    }
    vi check(M);
    Rep(i,(1<<L)){
        Rep(j,(1<<R)-1){
            check[A]++;
            printf ("%d ", A );
            A ^= (1<<r[streak1(i+j)%R]);
        }
        check[A]++;
        printf ("%d ", A, i+1==(1<<L)?"\n":" " );
        A ^= (1<<l[streak1(i)]);
    }

    Rep(i,M){
        if( check[i] != 1 ){
            return 0;
        }
    }

    return 0;
}

/*
 * 0000 *
 * 0001 0
 * 0011 1
 * 0010 0
 * 0110 2
 * 0100 1
 * 0101 0
 * 0111 1
 * 1111 3
 * 1110 0
 * 1100 1
 * 1101 0
 * 1001 2
 * 1011 1
 * 1010 0
 * 1000 1
 * 1000 4
 */

