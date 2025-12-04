#include <iostream>
#include <algorithm>
using namespace std;
using ll=long long;

int n, aa[100'007];
pair<int,int> tree[400'007]; //{a[i],i}

void init(int v, int s, int e){
    if (s==e) tree[v]={aa[s],s};
    else {
        int m=(s+e)/2;
        init(v*2,s,m); init(v*2+1,m+1,e);
        tree[v]=min(tree[v*2],tree[v*2+1]);
    }
}

pair<int,int> query(int v, int s, int e, int l, int r){
    if (e<l || r<s) return {1'000'000'001,0};
    else if (l<=s && e<=r) return tree[v];
    else{
        int m=(s+e)/2;
        return min(query(v*2,s,m,l,r),query(v*2+1,m+1,e,l,r));
    }
}

ll res(int l, int r){
    if (l>r) return 0; if (l==r) return aa[l];
    pair<int,int> m=query(1,1,n,l,r);
    return max((m.first*(ll)(r-l+1)),max(res(l,m.second-1),res(m.second+1,r)));
}

int main() {
    //cin.tie(0)->sync_with_stdio(0);
    
    cin>>n;
    while (n){
        for(int i=1; i<=n; i++) cin>>aa[i];
        init(1,1,n);
        cout<<res(1,n)<<'\n';
        cin>>n;
    }

    cin.get(); cin.get();
    return 0;
}