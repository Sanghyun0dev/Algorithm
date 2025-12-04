#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1'000'001],tree[4'000'000];

void init(int v, int s, int e){
    if (s==e) tree[v]=0;
    else {
        int m=(s+e)/2;
        init(v*2,s,m); init(v*2+1,m+1,e);
        tree[v]=0;
    }
}

void update(int v, int s, int e, int i){
    if (i<s || e<i) return;
    else if (s==e) tree[v]=dp[i];
    else {
        int m=(s+e)/2;
        update(v*2,s,m,i); update(v*2+1,m+1,e,i);
        tree[v]=max(tree[v*2],tree[v*2+1]);
    }
}

//query(1,1,n,i,j) i~j가 주어졌을 때 최대 길이
int query(int v, int s, int e, int l, int r){
    if (e<l || r<s) return 0;
    else if (l<=s && e<=r) return tree[v];
    else {
        int m=(s+e)/2;
        return max(query(v*2,s,m,l,r),query(v*2+1,m+1,e,l,r));
    }
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    
    int n; cin>>n;
    vector<int> aa(n); for (int &a:aa) cin>>a;
    vector<int> s_aa=aa; sort(s_aa.begin(),s_aa.end());
    s_aa.erase(unique(s_aa.begin(),s_aa.end()),s_aa.end());
    for (int &a:aa){
        int inp=(int)(lower_bound(s_aa.begin(),s_aa.end(),a)-s_aa.begin())+1;
        //a: 실제 입력, inp: 압축 입력; s_aa[inp-1]=a;
        dp[inp]=query(1,1,n,1,inp-1)+1;
        update(1,1,n,inp);
    }
    cout<<tree[1];

    cin.get(); cin.get();
    return 0;
}