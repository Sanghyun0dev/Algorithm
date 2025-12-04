#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
 
pair<int,int> p[20][100005];
int dpth[100005];

vector<pair<int,int>> g[100005];

void dfs(int v, int par, int len) {
    dpth[v] = dpth[par]+1;
    p[0][v] = {par,len};
    
    for (auto x: g[v]) {
        if (x.f==par) continue;
        dfs(x.f, v, x.s);
    }
}

int main() {
    //cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    for (int i=0; i<n-1; i++) {
        int u,v,l;
        cin >> u >> v;
        g[u].push_back({v,l});
        g[v].push_back({u,l});
    }
    
    // 1째 부모 값을 구하기!
    dfs(1, 1, 0);
    
    // p2, p4 등을 미리 전처리!
    for (int i=1; i<20; i++) {
        for (int x=1; x<=n; x++) { //p[i-1][j]={1단계 부모,거리}
            p[i][x] = {p[i-1][p[i-1][x].f].f,p[i-1][x].s+p[i-1][p[i-1][x].f].s};
            // f2(x) = f( f(x) )
        }
    }
    
    int q; cin >> q;
    while (q--) {
        int u,v;
        cin >> u >> v;
        int l=0,r=0; //u,v에서 LCA까지의 거리
        
        // v를 더 깊은걸로 맞추고, 깊이 맞추기
        if (dpth[u] > dpth[v]) swap(u,v);
        int diff = dpth[v]-dpth[u];
        for (int i = 19; i >= 0; i--) {
            if (diff & (1<<i)) {
                r+=p[i][v].s;
                v = p[i][v].f;
            }
        }

        //p[0][i]: 부모, p[n][i]: i의 n+1단계 부모
        for (int i = 19; i > 0;) { //같지 않을 때 동안
            if (p[i][u].f == p[i][v].f) {i--; continue;}
            l+=p[i][u].s; u = p[i][u].f;
            r+=p[i][v].s; v = p[i][v].f;
        }
        while (u!=v) {
            l+=p[0][u].s, r+=p[0][v].s;
            u = p[0][u].f, v = p[0][v].f;} //같을 때 까지: 최대 2번
        cout << l+u << '\n';
    }

    cin.get(); cin.get();
    return 0;
}