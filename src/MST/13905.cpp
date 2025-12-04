
//미해결
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> p;

int find(int k){
    if (p[k]==-1) return k;
    p[k]=find(p[k]);
    return p[k];
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);

    int n,m; cin>>n>>m;
    int s,e; cin>>s>>e;
    vector<vector<int>> es(m,vector<int>(3));
    int h1,h2,k;
    for (int i=0; i<m; i++){
        cin>>h1>>h2>>k;
        es[i]={k,h1,h2};
    }
    sort(es.begin(),es.end(),-1);

    cin.get(); cin.get();
    return 0;
}
/*
s부터 e까지 연결된 서브 그래프에 대해 최소 스패닝 트리를 만들고 경로 최솟값 출력
*/