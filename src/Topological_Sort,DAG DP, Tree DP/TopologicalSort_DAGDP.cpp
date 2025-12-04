#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> g(1001,vector<int>());
vector<bool> visited(1001, false);
vector<int> stack;
int d[1001];
vector<int> dp(1001,0);

//v -> u
void dfs(int v){
    visited[v]=true;
    for (int u:g[v]){
        if (!visited[u]) dfs(u);
    }
    stack.push_back(v);
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    for (int _=0; _<t; _++){
        //초기화
        g=vector<vector<int>> (1001,vector<int>());
        visited=vector<bool> (1001, false);
        stack.clear();
        dp=vector<int> (1001,0);

        //입력
        int n,k; cin>>n>>k;
        for (int i=1; i<n+1; i++) cin>>d[i];
        for (int i=1; i<n+1; i++) dp[i]=d[i];
        int u,v;
        for (int __=0; __<k; __++){
            cin>>u>>v;
            g[u].push_back(v);
        }

        //위상정렬
        for (int i=1; i<=n; i++) {
            if(!visited[i]) dfs(i);
        }
        reverse(stack.begin(),stack.end());

        //cout<<"sort: "; for(int i:stack) cout<<i<<' '; cout<<'\n';
        
        //DP
        int w; cin>>w;
        dp[stack[0]]=d[stack[0]];
        for (int v : stack){
            if (v==w) break;
            for (int u : g[v]) dp[u]=max(dp[u],dp[v]+d[u]);
        }

        //출력
        cout<<dp[w]<<'\n';
    }

    cin.get(); cin.get();
    return 0;
}