#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<int> g[100'001];
int dpth[100'001];
int p[17][100'001]; //p[i][j]: j의 2^i단계 부모

void dfs(int v, int par){
    dpth[v]=dpth[par]+1;
    p[0][v]=par;
    for (int c:g[v]){
        if (c!=par) dfs(c,v);
    }
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dpth[0]=0; dfs(1,0);

    //f2(x)=f(f(x))
    for (int i=1; i<17; i++){
        for (int x=1; x<=n; x++){
            p[i][x]=p[i-1][p[i-1][x]];
        }
    }

    int m; cin >> m;
    while (m--){
        int u,v;
        cin >> u >> v;

        //깊이 맞추기
        if (dpth[u]>dpth[v]) swap(u,v);
        int diff=dpth[v]-dpth[u];
        for (int i=16; i>=0; i--){
            if (diff & (1<<i)) v=p[i][v];
        }

        //공통 조상까지 올라가기
        if (u==v) {cout<<u<<'\n'; continue;}
        for (int i=16; i>=0; i--){
            if (p[i][u]!=p[i][v]) u=p[i][u], v=p[i][v];
        }
        cout<<p[0][u]<<'\n';
    }

    cin.get(); cin.get();
    return 0;
}