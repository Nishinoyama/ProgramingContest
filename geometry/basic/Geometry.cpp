#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;

// 参考サイト
// 前原 貴憲
// http://www.prefield.com/algorithm/index.html

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> Point; //複素数で平面定義
typedef Point P;

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
// Line L vector<P> PolyGon G vector<P> Circle C(P,int rad) {{{
// 直線 Line
// 線分 Segment
struct L : public vector<P> {
    L(const P &a, const P &b ){
        push_back(a); push_back(b);
    }
};

// 単純多角形 PolyGon
typedef vector<P> G;
typedef G Polygon;

// 円 cirlce
struct C {
    P p; double r;
    C(const P &p, double r ) : p(p), r(r) {}
};
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
double area( const Polygon &P ){
    double A = 0.0;
    for( int i = 0; i < P.size(); i++ ){
        A += cross( P[i], P[(i+1)%P.size()] );
    }
    return A;
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

int main() {

    double a,b,c,d;
    G pol;


    int q;
    cin >> q;

    while(q--){
        cin >> a >> b;
        P p(a,b);
        pol.push_back(p);
        // printf ("%1.10lf %1.10lf\n", real(x), imag(x) );
    }
    imagePointDescription(pol,1);

    printf ("%.1lf\n", area(pol)/2.0);


    return 0;
}

