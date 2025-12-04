#include <iostream>
#include <algorithm>
using namespace std;
using ll=long long;

int n, aa[100'001];
pair<ll,int> tree[400'000];

pair<ll,int> combine(pair<ll,int> l, pair<ll,int> r){
    if (aa[l.second]<aa[r.second]) return {l.first+r.first,l.second};
    else return {l.first+r.first,r.second};
}

void init(int v, int s, int e){
    if (s==e) tree[v]={aa[s],s};
    else {
        int m=(s+e)/2;
        init(v*2,s,m); init(v*2+1,m+1,e);
        tree[v]=combine(tree[v*2],tree[v*2+1]);
    }
}

pair<ll,int> query(int v, int s, int e, int l, int r){
    if (e<l || r<s) return {0,0};
    else if (l<=s && e<=r) return tree[v];
    else {
        int m=(s+e)/2;
        return combine(query(v*2,s,m,l,r), query(v*2+1,m+1,e,l,r));
    }
}

ll dc(int s, int e){
    if (s>e) return 0;
    pair<ll,int> q=query(1,1,n,s,e);
    if (s==e) return q.first*aa[q.second];
    ll all=q.first*aa[q.second], l=dc(s,q.second-1), r=dc(q.second+1,e);
    return max(all,max(l,r));
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    
    cin>>n; aa[0]=1'000'001;
    for (int i=1; i<=n; i++){cin>>aa[i];}
    init(1,1,n);
    cout<<dc(1,n);

    cin.get(); cin.get();
    return 0;
}