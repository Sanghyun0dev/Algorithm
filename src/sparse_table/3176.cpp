#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define f first
#define s second

vector<pair<int,int>> g[100'001]; //{par,len}
int dpth[100'001];
tuple<int,int,int> p[17][100'001]; //p[i][j]: j의 2^i단계 부모, {par,mn,mx}

void dfs(int v, int par, int len){
    dpth[v]=dpth[par]+1;
    p[0][v]={par,len,len};
    for (auto c:g[v]){
        if (c.f!=par) dfs(c.f,v,c.s);
    }
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    for (int i=1; i<n; i++){
        int u,v,l;
        cin >> u >> v >> l;
        g[u].push_back({v,l});
        g[v].push_back({u,l});
    }
    dpth[1]=0; dfs(1,1,0);

    //f2(x)=f(f(x))
    for (int i=1; i<17; i++){
        for (int x=1; x<=n; x++){
            auto fx=p[i-1][x]; auto ffx=p[i-1][get<0>(fx)];
            p[i][x]={get<0>(ffx),min(get<1>(fx),get<1>(ffx)),max(get<2>(fx),get<2>(ffx))};
        }
    }

    int m; cin >> m;
    while (m--){
        int u,v;
        cin >> u >> v;

        int mn=1'000'001, mx=0;

        //깊이 맞추기
        if (dpth[u]>dpth[v]) swap(u,v);
        int diff=dpth[v]-dpth[u];
        for (int i=16; i>=0; i--){
            if (diff & (1<<i)) {
                mn=min(mn,get<1>(p[i][v]));
                mx=max(mx,get<2>(p[i][v]));
                v=get<0>(p[i][v]);
            }
        }

        //공통 조상까지 올라가기
        for (int i=16; i>=0;){
            if (get<0>(p[i][u])==get<0>(p[i][v])) {i--; continue;}
                mn=min(mn,min(get<1>(p[i][u]),get<1>(p[i][v])));
                mx=max(mx,max(get<2>(p[i][u]),get<2>(p[i][v])));
                u=get<0>(p[i][u]), v=get<0>(p[i][v]);
        }
        while (u!=v) {
            mn=min(mn,min(get<1>(p[0][u]),get<1>(p[0][v])));
            mx=max(mx,max(get<2>(p[0][u]),get<2>(p[0][v])));
            u=get<0>(p[0][u]), v=get<0>(p[0][v]);
        }
        cout<<mn<<' '<<mx<<'\n';
    }

    cin.get(); cin.get();
    return 0;
}