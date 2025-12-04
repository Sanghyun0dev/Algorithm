#include <iostream>
using namespace std;

int aa[500'007], tree[2'000'007];

void init(int v, int s, int e){
    if (s==e) tree[v]=aa[s];
    else {
        int m=(s+e)/2;
        init(v*2,s,m); init(v*2+1,m+1,e);
        tree[v]=tree[v*2]+tree[v*2+1];
    }
}

void update(int v, int s, int e, int i){
    if (i<s || i>e) return;
    else if (s==i && i==e) tree[v]=aa[s];
    else {
        int m=(s+e)/2;
        update(v*2,s,m,i); update(v*2+1,m+1,e,i);
        tree[v]=tree[v*2]+tree[v*2+1];
    }
}

int  query(int v, int s, int e, int l, int r){
    if(s>=l && e<=r) return tree[v];
    else if (r<s || l>e) return 0;
    else {
        int m=(s+e)/2;
        return query(v*2,s,m,l,r)+query(v*2+1,m+1,e,l,r);
    }
}

int main() {
    //cin.tie(0)->sync_with_stdio(0);

    int n,m; cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>aa[i];
    init(1,1,n);
    
    int x;
    for (int _=0; _<m; _++){
        cin>>x;
        cout<<query(1,1,n,1,x)<<' ';
        aa[x]=0; update(1,1,n,x);
    }

    cin.get(); cin.get();
    return 0;
}