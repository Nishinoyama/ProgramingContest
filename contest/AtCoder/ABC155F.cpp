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

#define L first
#define R second

int main() {

    int N,M;
    Scd2(N,M);

    vii a(N);
    vii l(M);

    int x,y;
    Rep(i,N){
        Scd2(x,y);
        a[i] = {x,y};
    }
    Rep(i,M){
        Scd2(x,y);
        l[i] = {x,y};
    }

    sort(a.begin(),a.end());
    vi sbom(N+2,0);
    Rep(i,N) {
        sbom[i] ^= a[i].second;
        sbom[i+1] ^= a[i].second;
        printf ("%d", sbom[i]);
        // printf ("%d %d\n", a[i].first, a[i].second );
    }
    sbom[N] ^= sbom[N-1];


    map<int,int> pre;
    Rep(i,N){
        pre[a[i].first] = i;
    }
    pre[INF] = N;

    vector<pair<pii,int>> r(M);
    Rep(i,M){
        r[i].second = i+1;
        r[i].first.L = pre.lower_bound(l[i].L)->second;
        r[i].first.R = pre.upper_bound(l[i].R)->second+1;
        printf ("[%d,%d)\n", r[i].first.L, r[i].first.R );
    }
    map<pii,int> mr;
    Rep(i,M){
        mr.insert(r[i]);
    }

    int pi = -1;
    int li = -1;
    int ri = 0;

    vi pare(N,-1);
    map<int,pii> re;

    for( pair<pii,int> tr : mr ){
        if( li == tr.first.L ) {
            pare[pi] = pare[tr.second];
            pare[tr.second] = pi;
            mr.insert( {{ri,tr.first.R}, tr.second });
        }else{
            li = tr.first.L;
            re.insert({ tr.first.L, {tr.first.R, tr.second }});
        }
        pi = tr.second;
        ri = tr.first.R;
    }

    vi ans;
    Rep(i,N){
        if( sbom[i] ){
            auto itr = re.find(i);
            if( itr == re.end() ){
                printf ("%d\n", -1);
                return 0;
            }else{
                ans.push_back(itr->second.second);
                sbom[itr->second.first] ^= 1;
            }
        }
    }

    int K = ans.size();
    vi anss;
    pi = -1;
    Rep(i,K){
        pi = ans[i];
        while( pi != -1 ){
            anss.push_back(pi);
            pi = pare[pi];
        }
    }
    sort(anss.begin(),anss.end());
    anss.push_back(-1);

    vi ansss;
    K = anss.size();
    Rep(i,K-1){
        if( anss[i] == anss[i+1] ) i++;
        else ansss.push_back(anss[i]);
    }

    K = ansss.size();
    printf ("%d\n", K);
    Rep(i,K){
        printf ("%d%s", ansss[i], i==K-1?"\n":" " );
    }


    return 0;
}

