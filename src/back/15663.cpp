#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,b,arr[8],res[8],used[8];

void back(int len){
    if (len==m){
        for (int i{0}; i<m; i++) cout<<res[i]<<' ';
        cout<<'\n'; return;
    }
    int last=0;
    for (int i=0; i<n; i++){
        if (arr[i]==last || used[i]) continue;
        res[len]=arr[i];
        last=arr[i];
        used[i]=1;
        back(len+1);
        used[i]=0;
    }
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    
    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>arr[i];
    sort(arr,arr+n); fill(used,used+8,0);
    back(0);

    cin.get(); cin.get();
    return 0;
}