#include <iostream>
using namespace std;

long long aa[1'000'005], tree[4'000'005];

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

long long  query(int v, int s, int e, int l, int r){
    if(s>=l && e<=r) return tree[v];
    else if (r<s || l>e) return 0;
    else {
        int m=(s+e)/2;
        return query(v*2,s,m,l,r)+query(v*2+1,m+1,e,l,r);
    }
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);

    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<n+1; i++){
        cin>>aa[i]; 
    }
    init(1,1,n);

    long long a,b,c;
    for (int _=0; _<m+k; _++){
        cin>>a>>b>>c;
        if (a==1){
            aa[b]=c;
            update(1,1,n,b);
        }
        else {
            cout<<query(1,1,n,b,c)<<'\n';
        }
    }
    
    cin.get(); cin.get();
    return 0;
}