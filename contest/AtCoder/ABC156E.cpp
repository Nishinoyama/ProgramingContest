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

const long long int mod = 1000000007;

// PowMod( base, index, modulo) return base ** index % modulo {{{
// PowMod = base ** index % mod ( natural numbers )
inline constexpr long long int PowMod( long long int base, long long int index, long long int modulo = mod ){
    if( index == 0 ) return 1;
    // O( log(index) )
    if( index % 2 ){
        return base * PowMod(base, index - 1, modulo) % modulo;
    }else{
        long long int Phalf = index / 2;
        long long int half = PowMod(base, Phalf, modulo);
        return half * half % modulo;
    }
}
// }}}
// CombMod( n, r, modulo ) return nCr % modulo {{{
// CombMod(ination) = nCr % mod ( natural number )
inline constexpr long long int CombMod( long long int n, long long int r, long long int modulo = mod){
    if( n < r ) return CombMod(r,n,modulo);
    long long int Upper = 1;
    long long int Lower = 1;
    for(long long int i = 0; i < r; i++){
        Upper = Upper * (n-i) % modulo;
        Lower = Lower * (i+1) % modulo;
    }
    // Return (Upper / Lower)
    long long int ret = Upper * PowMod(Lower,modulo-2,modulo) % modulo;
    return ret;
}
// }}}
// FactMod( n, modulo ) return n! % modulo {{{
// Fact(orial) = n! % mod ( natural number )
inline constexpr long long int Fact( long long int n, long long int modulo = mod){
    long long int Upper = 1;
    for(long long int i = 0; i < n; i++){
        Upper = Upper * (n-i) % modulo;
    }
    return Upper;
}
// }}}
// modint {{{

struct modint{
    long long int a;
    inline constexpr modint( long long int x = 0 ) noexcept : a(x % mod) {}
    inline constexpr long long int &value() noexcept { return a; }
    inline constexpr const long long int &value() const noexcept { return a; }
    inline constexpr modint operator+(const modint rhs) const noexcept{ return modint(*this) += rhs; }
    inline constexpr modint operator+(const int rhs) const noexcept{ return modint(*this) += rhs; }
    inline constexpr modint operator+(const long long int rhs) const noexcept{ return modint(*this) += rhs; }
    inline constexpr modint operator-(const modint rhs) const noexcept{ return modint(*this) -= rhs; }
    inline constexpr modint operator-(const int rhs) const noexcept{ return modint(*this) -= rhs; }
    inline constexpr modint operator-(const long long int rhs) const noexcept{ return modint(*this) -= rhs; }
    inline constexpr modint operator*(const modint rhs) const noexcept{ return modint(*this) *= rhs; }
    inline constexpr modint operator*(const int rhs) const noexcept{ return modint(*this) *= rhs; }
    inline constexpr modint operator*(const long long int rhs) const noexcept{ return modint(*this) *= rhs; }
    inline constexpr modint operator/(const modint rhs) const noexcept{ return modint(*this) /= rhs; }
    inline constexpr modint operator/(const int rhs) const noexcept{ return modint(*this) /= rhs; }
    inline constexpr modint operator/(const long long int rhs) const noexcept{ return modint(*this) /= rhs; }
    inline constexpr modint operator+=(const modint rhs) noexcept{ a += rhs.a; if( a >= mod ) a -= mod; return *this; }
    inline constexpr modint operator-=(const modint rhs) noexcept{ a -= rhs.a; if( a < 0 ) a += mod; return *this; }
    inline constexpr modint operator*=(const modint rhs) noexcept{ a = a * rhs.a % mod ;  return *this; }
    inline constexpr modint operator/=(const modint rhs) noexcept{ a = a * PowMod(rhs.a,mod-2) % mod; return *this; }
};

// }}}
// Poly Definition{{{
 
template< class T >
struct Poly{
    vector< T > A;
 
    Poly(){}
    Poly( int n ) {
        A.assign(n,0);
    }
 
    void adjust(){
        int di = A.size()-1;
        while( di && A[di].a == 0 ){
            di--;
        }
        A.resize(di+1);
    }
 
    int dim(){
        adjust();
        int dime = A.size()-1;
        return (dime);
    }
 
    inline T &operator[]( int k ) {
        return (A.at(k));
    }
 
    inline const T &operator[]( int k ) const {
        return (A.at(k));
    }
 
    // 単位多項式(1)
    static Poly E(){
        Poly pol(1);
        pol[0] = 1;
        return pol;
    }
 
    Poly &operator+=( Poly &B ){
        int n = B.dim();
        if( n >= dim() ) A.resize(n+1);
        for( int i = 0; i <= n; i++ ) (*this)[i] += B[i];
        return (*this);
    }
 
    Poly &operator-=( Poly &B ){
        int n = B.dim();
        if( n >= dim() ) A.resize(n+1);
        for( int i = 0; i <= n; i++ ) (*this)[i] -= B[i];
        return (*this);
    }
 
    Poly &operator*=( Poly &B ){
        int n = dim(), m = B.dim();
        vector< T > C( n+m+1,0 );
        for( int i = 0; i <= n; i++ )
            for( int j = 0; j <= m; j++ )
                C[i+j] += (*this)[i] * B[j];
        A.swap(C);
        return (*this);
    }
    Poly power( ll k ){
        Poly B = Poly::E();
        while( k > 0 ){
            if( k&1 ) B *= *this;
            *this *= *this;
            k >>= 1;
        }
        A.swap(B.A);
        return *this;
    }
    Poly powerMod( ll k, Poly &mod ){
        Poly B = Poly::E();
        while( k > 0 ){
            if( k&1 ) B *= *this, B %= mod;
            *this *= *this;
            *this %= mod;
            k >>= 1;
        }
        A.swap(B.A);
        return *this;
    }
 
    // TODO
    // polmod(%=) 多項式剰余
    Poly &operator%=( Poly &B ){
        int n = dim(), m = B.dim();
        for( int i = n-m; i >= 0; i-- ){
            T res = A[i+m] / B[m];
            for( int j = m; j >= 0; j-- ){
                A[i+j] - B[j] * res;
            }
        }
        A.resize(m);
        return (*this);
    }
 
    // divider(/=) 多項式除算
    // Poly &operator/=( const Poly &B );
 
    Poly operator+(const Poly &B ) const {
        return (Poly(*this) += B );
    }
    Poly operator-(const Poly &B ) const {
        return (Poly(*this) -= B );
    }
    Poly operator*(const Poly &B ) const {
        return (Poly(*this) *= B );
    }
 
 
    // digup けた上げ
    void digup( int di = 10 ){
        int n = dim();
        for( int i = 0; i < n; i++ ){
            A[i+1] += A[i]/di;
            A[i] %= di;
        }
        while( A[n] >= di ){
            A.push_back(A[n]/di);
            A[n++] %= di;
        }
    }
 
    void Print(){
        int m = dim();
        printf ("[");
        for( int j = 0; j <= m; j++ ){
            printf ("%lld%s", (*this)[j], j == m ? "]\n" : "," );
        }
    }
    void RevPrint(){
        int m = dim();
        printf ("[");
        for( int j = 0; j <= m; j++ ){
            printf ("%lld%s", (*this)[m-j], j == m ? "]\n" : "," );
        }
    }
    void DigiticPrint(){
        int m = dim();
        for( int j = m; j >= 0; j-- ){
            printf ("%lld%s", (*this)[j], j == 0 ? "\n" : "" );
        }
    }
};
// }}}
int main() {

    int N,K;
    Scd2(N,K);
    if( K > N-1 ) K = N-1;

    modint ans = 0;
    vector<modint> f(N*2+1,1);
    Rep(i,N*2){
        f[i+1] = f[i] * (i+1);
    }
    Rep(i,K+1){
        // i回移動
        ans += f[N]/f[i]/f[N-i] * f[N+i-1-i]/f[i]/f[N-i-1];
    }

    printf ("%lld\n", ans );

    return 0;
}

