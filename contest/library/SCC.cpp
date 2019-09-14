#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// {{{ Strong Connected Component
struct SCC{
    int N; // 頂点数
    vector<vector<int>> e;  //辺（有向）
    vector<vector<int>> re; //逆辺
    vector<bool> used; //探索フラグ
    vector<int> vs; //帰りがけ順序

    int K; // SCC後頂点数
    vector<int> cmp; //SCC前頂点->SCC後の頂点変換
    vector<set<int>> se;  //SCC後辺

    SCC( int N ) : N(N){
        e.resize(N);
        re.resize(N);
        used.resize(N);
        vs.resize(0);
        cmp.resize(N);
    }
    void add_edge( int v, int w ){
        e[v].push_back(w);
        re[w].push_back(v);
    }
    void dfs( int v ){
        used[v] = true;
        for( int to : e[v] ){
            if( !used[to] ) dfs(to);
        }
        vs.push_back(v);
    }
    // k = SCC後の扱いメモ
    void rdfs( int v, int k ){
        used[v] = true;
        cmp[v] = k;
        for( int to : re[v] ){
            if( !used[to] ) rdfs(to,k);
        }
    }
    // 返り値=強連結成分数
    int build(){
        vs.clear();
        used.assign(N,0);
        for( int i = 0; i < N; i++ ) if( !used[i] ) dfs(i);
        used.assign(N,0);
        K = 0;
        for( int i = N-1; i >= 0; i-- ) if( !used[vs[i]] ) rdfs(vs[i],K++);

        se.resize(K);
        for( int i = 0; i < N; i++ ){
            for( int to : e[i] ) if( cmp[i] != cmp[to] ) se[cmp[i]].insert(cmp[to]);
        }
        return K;
    }
};
// }}}

int main() {

    return 0;
}



