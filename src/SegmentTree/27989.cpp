#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll=long long;
#define MAX 300'000

vector<ll> dp,tree; //dp[i]: cc[i]로 끝나는 수열의 max_sum

void update(int v, int s, int e, int i){
    if (i<s || i>e) return;
    else if (s==i && i==e) tree[v]=dp[i];
    else {
        int m=(s+e)/2;
        update(v*2,s,m,i); update(v*2+1,m+1,e,i);
        tree[v]=max(tree[v*2],tree[v*2+1]);
    }
}

ll  query(int v, int s, int e, int l, int r){
    if (r<s || l>e) return 0;
    else if (s>=l && e<=r) return tree[v];
    else {
        int m=(s+e)/2;
        return max(query(v*2,s,m,l,r),query(v*2+1,m+1,e,l,r));
    }
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n; vector<ll> aa(n),bb(n);
    for (ll &x:aa) cin>>x; bb=aa;
    sort(bb.begin(),bb.end()); bb.erase(unique(bb.begin(), bb.end()), bb.end());
    n=bb.size(); dp=vector<ll>(n+1); tree=vector<ll>(4*n);
    for (ll &i:tree)i=0; for(ll &i:dp)i=0; //init

    for (ll a:aa){
        //a: 값; c: 구간에서의 인덱스 (1~n)
        int c=int(lower_bound(bb.begin(),bb.end(),a)-bb.begin())+1;
        ll d=query(1,1,n,1,c-1)+a;
        if (d>dp[c]){dp[c]=d; update(1,1,n,c);}
    }
    cout<<tree[1];

    cin.get(); cin.get();
    return 0;
}