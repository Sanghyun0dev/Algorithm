#include <iostream>
#include <vector>
using namespace std;


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    vector<int> a(n);
    for (int &x:a) cin>>x;

    vector<pair<int,int>> stack;
    vector<int> res(n,-1);
    for (int i=0; i<n; i++){
        while (!stack.empty() && stack.back().first<=a[i]){
            res[stack.back().second]=a[i];
            stack.pop_back();
        }
        stack.push_back({a[i],i});
    }

    for(int &x:res) cout<<x<<' ';

    cin.get(); cin.get();
    return 0;
}