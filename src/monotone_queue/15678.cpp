#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;


int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int n,l; cin>>n>>l;
    vector<int> inp(n); for (int &x:inp) cin>>x;
    
    deque<pair<long long,int>> dq; //단조성: 뒤 추가 시 맨 뒤가 x 이하일 시 제거
    vector<long long> dp(n); dp[0]=inp[0];
    for (int i=1; i<l; i++){ //처음 l: 앞 제거 X
        while (!dq.empty() && dq.back().first<=dp[i-1]) dq.pop_back(); //단조성
        dq.push_back({dp[i-1],i}); //뒤 추가

        dp[i]= (dq.front().first>0)? inp[i]+dq.front().first:inp[i];
    }

    for (int i=l; i<n; i++){ //구간: i-l+1 ~ i
        while (!dq.empty() && dq.front().second<i-l+1) dq.pop_front(); //앞 제거
        while (!dq.empty() && dq.back().first<=dp[i-1]) dq.pop_back(); //단조성
        dq.push_back({dp[i-1],i}); //뒤 추가

        dp[i]= (dq.front().first>0)? inp[i]+dq.front().first:inp[i];
    }

    cout<<*max_element(dp.begin(),dp.end());

    cin.get(); cin.get();
    return 0;
}