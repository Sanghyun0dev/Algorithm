#include <iostream>
#include <algorithm>
using namespace std;

int aa[100'007];
pair<int,int> tree[400'007]; //{min,max}

void init(int v, int s, int e){
    if (s==e){
        tree[v]={aa[s],aa[s]};
    }
    else {
        int m=(s+e)/2;
        init(v*2,s,m); init(v*2+1,m+1,e);
        pair<int,int> f=tree[v*2], s=tree[v*2+1];
        tree[v]={min(f.first,s.first),max(f.second,s.second)};
    }
}

// void update(int v, int s, int e, int i){
//     if (i<s || i>e) return;
//     else if (s==i && i==e) tree[v]={aa[i],aa[i]};
//     else {
//         int m=(s+e)/2;
//         update(v*2,s,m,i); update(v*2+1,m+1,e,i);
//         pair<int,int> f=tree[v*2], s=tree[v*2+1];
//         tree[v]={min(f.first,s.first),max(f.second,s.second)};
//     }
// }

pair<int,int> query(int v, int s, int e, int l, int r){
    if (l<=s && e<=r) return tree[v];
    else if (e<l || r<s) return {1'000'000'000,1};
    else {
        int m=(s+e)/2;
        pair<int,int> f=query(v*2,s,m,l,r), s=query(v*2+1,m+1,e,l,r);
        return {min(f.first,s.first),max(f.second,s.second)};
    }
}

int main() {
    //cin.tie(0)->sync_with_stdio(0);

    int n, m; cin>>n>>m;
    for (int i=1; i<=n; i++){
        cin>>aa[i];
    }
    init(1,1,n);

    int a,b;
    for (int _=0; _<m; _++){
        cin>>a>>b;
        pair<int,int> p=query(1,1,n,a,b);
        cout<<p.first<<' '<<p.second<<'\n';
    }

    cin.get(); cin.get();
    return 0;
}