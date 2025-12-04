#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,b,arr[8],res[8];

void back(int len){
    if (len==m){
        for (int i{0}; i<m; i++) cout<<res[i]<<' ';
        cout<<'\n'; return;
    }
    int last=0;
    for (int i=0; i<n; i++){
        if (arr[i]==last) continue;
        if (len!=0 && res[len-1]>arr[i]) continue;
        res[len]=arr[i];
        last=arr[i];
        back(len+1);
    }
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    
    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>arr[i];
    sort(arr,arr+n);
    back(0);

    cin.get(); cin.get();
    return 0;
}