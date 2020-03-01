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

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> Point; //複素数で平面定義
using P = Point ;

// system {{{
// オペレーター< を定義、後々楽
namespace std{
    bool operator < ( const P& a, const P& b) {
        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
}

// 外積
double cross( const P& a, const P& b ){
    return imag(conj(a)*b);
}
// 内積
double dot( const P& a, const P& b ){
    return real(conj(a)*b);
}
// }}}
// Line L:vector<P> Polygon G:vector<P> Circle C(P,int rad) {{{
// 直線 Line 線分 Segment {{{
struct L : public vector<P> {
    L(const P &a, const P &b ){
        push_back(a); push_back(b);
    }
};
using Line = L;
// }}}
// 単純多角形 Polygon {{{
struct G : public vector<P> {
    Point curr( int i ){
        return *(begin()+i);
    }
    Point next( int i ){
        return *(begin()+(i+1)%size());
    }
    Point prev( int i ){
        i += size();
        return *(begin()+(i-1)%size());
    }
    double area2(){
        double A = 0.0;
        for( int i = 0; i < size(); i++ ){
            A += cross( curr(i),next(i) );
        }
        return A;
    }
    int contains( P &p ){
        bool in = false;
        for( int i = 0; i < size(); i++ ){
            Point a = curr(i) - p, b = next(i) - p;
            if( imag(a) > imag(b) ) {
                Point c = a;
                a = b; b = c;
            }
            if( imag(a) <= 0 && 0 < imag(b))
                if( cross(a,b) < 0) in = !in;
            if( cross(a,b) == 0 && dot(a, b) <= 0 ) return 1;
        }
        return in*2;
    }
    Point& operator []( size_t i ){
        return *(begin()+i%size());
    }
    const Point& operator []( size_t i ) const {
        return *(begin()+i%size());
    }
};
using Polygon = G;
//}}}
// 円 cirlce {{{
struct C {
    P p; double r;
    C(const P &p, double r ) : p(p), r(r) {}
};
// }}}
// }}}
// counter clockwise {{{
//
int ccw( P a, P b, P c ){
    b -= a; c -= a;
    if( cross(b,c) > 0 )   return +1; //counter clockwise
    if( cross(b,c) < 0 )   return -1; //clockwise
    if( dot(b,c) < 0 )     return +2; //online_back
    if( norm(b) < norm(c)) return -2; //online_front
    return 0; // on_segment
} //}}}
// 交点判定 交点座標 LSPtoLSP {{{
bool intersectLL( const L &l, const L &m ){
    return abs( cross(l[1]-l[0], m[1]-m[0]) ) > EPS || // cross(l,m) != 0 <-> not paralell
           abs( cross(l[1]-l[0], m[0]-l[0]) ) < EPS;   // cross(l,(m-l)) == 0 <-> same line
}
bool intersectLS( const L &l, const L &s ){
    return cross( l[1]-l[0], s[0]-l[0] ) *
           cross( l[1]-l[0], s[1]-l[0] ) < EPS;
}
bool intersectLP( const L &l, const P &p ){
    return abs( cross(l[0]-p, l[1]-p) );
}
bool intersectSS( const L &s, const L &t ){
    return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
           ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
bool intersectSP( const L &s, const P &p ){
    return abs( s[0]-p )+abs( s[1]-p )-abs(s[1]-s[0]) < EPS;
}
P crossPoint( const L &l, const L &m ){
    double A = cross( l[1] - l[0], m[1] - m[0] );
    double B = cross( l[1] - l[0], l[1] - m[0] );
    // A は に直線の成す平行四辺形
    // B は そのA のうちの片側
    // 書いたら分かる
    // 参考サイト
    // http://www.fumiononaka.com/Business/html5/FN1312003.html
    if( abs(A) < EPS && abs(B) < EPS ) return m[0];
    return m[0] + B / A * ( m[1] - m[0] );
}
// }}}
// 射影 反射 距離 LSPtoLSP  {{{
P projection( const L &l, const P &p ){
    double t = dot( p-l[0], l[0]-l[1] ) / norm( l[0]-l[1] );
    return l[0] + t*(l[0]-l[1]);
}
P reflection( const L &l, const P &p ){
    return p + 2.0*( projection(l,p) - p );
}
double distanceSP( const L &s, const P &p ){
    const P r = projection(s,p);
    if( intersectSP(s,r) ) return abs(r-p);
    else return min( abs(s[0] - p), abs(s[1] - p) );
}
double distanceSS( const L &s, const L &t ){
    if( intersectSS(s,t) ) return 0.0;
    return min( min( distanceSP(s,t[0]), distanceSP(s,t[1]) ),
                min( distanceSP(t,s[0]), distanceSP(t,s[1]) ) );
}
// }}}
// 多角形面積 G {{{
double area2( const Polygon &P ){
    double A = 0.0;
    for( int i = 0; i < P.size(); i++ ){
        A += cross( P[i], P[(i+1)%P.size()] );
    }
    return A;
}
// }}}
// 凸包 {{{
Polygon convexHull( Polygon pl ){
    int n = pl.size(), k=0;
    sort( pl.begin(), pl.end() , []( Point& a, Point& b ) -> bool {
        return imag(a) != imag(b) ? imag(a) < imag(b) : real(a) < real(b);
    } );
    // sort( pl.begin(), pl.end());
    Polygon ch;
    ch.resize(2*n);
    for( int i = 0; i < n; ch[k++] = pl[i++] )
        while( k >= 2 && ccw( ch[k-2], ch[k-1], pl[i] ) == -1 )k--;
    for( int i = n-2, t = k+1; i >= 0; ch[k++] = pl[i--] )
        while( k >= t && ccw( ch[k-2], ch[k-1], pl[i] ) == -1 )k--;
    ch.resize(k-1);
    return ch;

}
// }}}
// 凸多角形の直径 {{{
double convexDiameter( const Polygon &pt ){
    const int n = pt.size();
    int is = 0, js = 0;
    for (int i = 1; i < n; i++){
        if( imag(pt[i]) > imag(pt[is]) ) is = i;
        if( imag(pt[i]) < imag(pt[js]) ) js = i;
    }
    double maxd = norm( pt[is] - pt[js] );
    int i,maxi,j,maxj;
    i = maxi = is;
    j = maxj = js;
    do{
        Point pi = pt[i+1] - pt[i];
        Point pj = pt[j+1] - pt[j];
        if( cross(pi , pj) >= -EPS ) j++;
        else i++;
        i %= n;
        j %= n;
        if( norm( pt[i] - pt[j] ) > maxd ){
            maxd = norm( pt[i] - pt[j] );
            maxi = i; maxj = j;
        }
    } while ( i != is || j != js );
    return maxd; /* farthest pair is (maxi, maxj). */
}
// }}}
// 凸多角形の切断 {{{
pair<Polygon,Polygon> convexCut( const Polygon& P , const Line &l ){
    pair<Polygon, Polygon> Q;
    // Q.first:LeftRemain
    // Q.right:RightRemain
    for( int i = 0; i < P.size(); i++ ){
        Point A = P[i]; Point B = P[i+1];
        if( ccw( l[0], l[1], A ) != -1 ) Q.first.push_back(A);
        else Q.second.push_back(A);
        if( ccw( l[0], l[1], A ) * ccw( l[0], l[1], B ) < 0)
            A = crossPoint( Line(A,B), l ),
            Q.first.push_back(A),
            Q.second.push_back(A);
    }
    return Q;
}
// }}}
// 最近点 {{{
double closestPair( vector<P> p, int n ){
    if( n <= 1 ) return INF;
    int m = n/2;
    double x = real(p[m]);
    vector<P> left(m);
    vector<P> right(n-m);
    for( int i = 0; i < m; i++ ) left[i] = p[i];
    for( int i = m; i < n; i++ ) right[i] = p[i];
    double d = min( closestPair(left, m), closestPair(right, n-m ));
    printf ("%d\n", n );
    sort( p.begin(), p.end(), []( Point& a, Point& b ) -> bool {
        return imag(a) != imag(b) ? imag(a) < imag(b) : real(a) < real(b);
    } );

    vector<P> b;

    for( int i = 0; i < n; i++ ){
        if( abs( p[i] - x ) >= d  ) continue;
        if( b.size() )
        for (int j = b.size()-1; j >= 0; j-- ){
            if( imag(p[i] - b[i]) >= d ) break;
            d = min( d, sqrt( norm( p[i] - b[i] ) ));
        }
        b.push_back( p[i] );
    }

    return d;
}
// }}}
// imagePointDescription(点表示) {{{ 
void imagePointDescription( const vector<P> &p, double scale = 1 ){
    int here[51][51] = {};
    int i = 0;
    for( P t : p ){
        i++;
        int y = round(imag(t)/scale);
        int x = round(real(t)/scale);
        if( abs(y) > 25 ) continue;
        if( abs(x) > 25 ) continue;
        here[y+25][x+25] = i;
    }

    for( i = 50; i >= 0; i-- ){
        for( int j = 0; j <= 50; j++ ){
            if( here[i][j] ) printf ("%2d", here[i][j] );
            else if( i == 25 && j == 25 ) printf ("-+");
            else if( i == 25 ) printf ("--");
            else if( j == 25 ) printf (" |");
            else if( j % 5 == 0 && i % 5 == 0)printf (" .");
            else printf ("  ");
        }
        printf ("\n");
    }

}
// }}}

// 引用元:https://tubo28.me/compprog/algorithm/minball/

template <class iter>
double min_ball(iter left, iter right, int seed = 1414 ) {
    const int n = right - left;

    assert(n >= 1);
    if (n == 1) {
        return INF;
    }

    mt19937 mt(seed);
    shuffle(left, right, mt);

    iter ps = left;

    auto make_circle_3 = [](const P &a, const P &b, const P &c) -> C {
        double A = norm(b - c), B = norm(c - a), C = norm(a - b),
           S = cross(b - a, c - a);
        P p = (A * (B + C - A) * a + B * (C + A - B) * b + C * (A + B - C) * c) / (4 * S * S);
        double r2 = norm(p - a);
        return {p, r2};
    };

    auto make_circle_2 = [](const P &a, const P &b) -> C {
        P c = (a + b) / (double)2;
        double r2 = norm(a - c);
        return {c, r2};
    };

    auto in_circle = [](const P &a, const C &c) -> bool {
        return norm(a - c.p) <= c.r + EPS;
    };

    C c = make_circle_2(ps[0], ps[1]);

    // MiniDisc
    for (int i = 2; i < n; ++i) {
        if (!in_circle(ps[i], c)) {
            // MiniDiscWithPoint
            c = make_circle_2(ps[0], ps[i]);
            for (int j = 1; j < i; ++j) {
                if (!in_circle(ps[j], c)) {
                    // MiniDiscWith2Points
                    c = make_circle_2(ps[i], ps[j]);
                    for (int k = 0; k < j; ++k) {
                        if (!in_circle(ps[k], c)) {
                            c = make_circle_3(ps[i], ps[j], ps[k]);
                        }
                    }
                }
            }
        }
    }
    return c.r;
}

int main() {

    int N;
    Scd(N);

    G pol;
    int x,y;
    Rep(i,N){
        Scd2(x,y);
        P p(x,y);
        pol.push_back(p);
    }

    // imagePointDescription(pol);

    printf ("%.12lf", sqrt(min_ball(pol.begin(),pol.end())) );

    return 0;
}

