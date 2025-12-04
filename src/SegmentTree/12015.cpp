#include <iostream>
#include <algorithm>
using namespace std;

int dp[1'000'007],tree[4'000'028]; //dp[i]: i로 끝나는 수열의 max_len

void update(int v, int s, int e, int i){
    if (i<s || i>e) return;
    else if (s==i && i==e) tree[v]=dp[i];
    else {
        int m=(s+e)/2;
        update(v*2,s,m,i); update(v*2+1,m+1,e,i);
        tree[v]=max(tree[v*2],tree[v*2+1]);
    }
}

int  query(int v, int s, int e, int l, int r){
    if(s>=l && e<=r) return tree[v];
    else if (r<s || l>e) return 0;
    else {
        int m=(s+e)/2;
        return max(query(v*2,s,m,l,r),query(v*2+1,m+1,e,l,r));
    }
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);

    for (int &i:tree)i=0; for(int &i:dp)i=0; //init
    int n; cin>>n; int a,d;
    for (int _=0; _<n; _++){
        cin>>a; 
        d=(a==1)? 1:query(1,1,1'000'007,1,a-1)+1;
        if (d>dp[a]){dp[a]=d; update(1,1,1'000'007,a);}
    }
    cout<<tree[1]; 

    cin.get(); cin.get();
    return 0;
}