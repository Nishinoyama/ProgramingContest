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

struct edge{
    int v,c,r;
    // u->v cap() u<-v
};

int V,E;
vector< vector<edge> > e; // e[u] : e.first = u->v ; e.second = cap(u);
vector< bool > used;


void addedge(int a, int b, int c){
    e[a].push_back( edge{b,c,(int)e[b].size()} );
    e[b].push_back( edge{a,0,(int)e[a].size()-1} );
}

void scan(){

    Scd2(V,E);
    e.assign( V, vector<edge>(0) );
    int u,v,c;
    Rep(i,E){
        Scd3(u,v,c);
        addedge(u,v,c);
    }

}

// v:now , t:sink , c:capacity
int dfs( int v, int t, int c){
    if( v==t ) return c;
    used[v] = true;
    // Ford-Fulkerson algorithm
    for( int ei = 0; ei < e[v].size(); ei++ ){
        edge &ez = e[v][ei];
        if( !used[ez.v] && ez.c > 0){
            int d = dfs( ez.v,t,min(c,ez.c));
            if( d>0 ){
                ez.c -= d;
                e[ez.v][ez.r].c += d;
                return d;
            }
        }
    }
    return 0;
}

int ans( int s , int t ){
    int flow = 0;
    while(1){
        used.assign( V, false );
        int f = dfs(s,t,INF);
        if( f ) flow+=f;
        else break;
    }
    return flow;
}

int main() {

    scan();
    printf ("%d\n", ans(0,V-1) );

    return 0;
}

