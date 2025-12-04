#include <iostream>
#include <vector>
#include <deque>
using namespace std;


int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int n,l; cin>>n>>l;
    vector<int> a(n); for (int &x:a) cin>>x;

    //단조성: 새 값을 받을 때 그보다 작은 값 제거: 단조 증가
    deque<pair<int,int>> dq;
    for (int i=0; i<l; i++){
        while (!dq.empty() && dq.back().first >= a[i]) dq.pop_back(); //단조성
        dq.push_back({a[i],i}); //뒤 추가

        cout<<dq.front().first<<' ';
    }

    for (int i=l; i<n; i++){ //구간: i-l+1 ~ i
        while (!dq.empty() && dq.front().second < i-l+1) dq.pop_front(); //앞 제거
        while (!dq.empty() && dq.back().first >= a[i]) dq.pop_back(); //단조성
        dq.push_back({a[i],i}); //뒤 추가

        cout<<dq.front().first<<' ';
    }

    cin.get(); cin.get();
    return 0;
}