#include <iostream>
#include <vector>
#include <algorithm>
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
    p=vector<int>(n+1,-1);
    vector<vector<int>> gansun(m,vector<int>(3));
    int a,b,c;
    for (auto &i:gansun){
        cin>>a>>b>>c;
        i[0]=c; i[1]=a; i[2]=b;
    }
    sort(gansun.begin(),gansun.end());
     int sum=0;
    for (auto i:gansun){
        a=i[1]; b=i[2]; c=i[0];
        if (find(a)!=find(b)){
            p[find(a)]=find(b);
            sum+=c;
        }
    }
    cout<<sum;

    cin.get(); cin.get();
    return 0;
}