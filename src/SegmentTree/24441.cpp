#include <iostream>
#include <vector>
using namespace std;

int aa[500'001]; //aa[i]: i*2-1의 행운 수 여부(0||1)
int tree[2'000'000]; //구간에서의 현재 행운 수 개수

void init(int v, int s, int e){
    if (s==e) tree[v]=1;
    else {
        int m=(s+e)/2;
        init(v*2,s,m); init(v*2+1,m+1,e);
        tree[v]=tree[v*2]+tree[v*2+1];
    }
}

void update(int v, int s, int e, int i){
    if (i<s || e<i) return;
    else if (s==i && i==e) tree[v]=0;
    else {
        int m=(s+e)/2;
        update(v*2,s,m,i); update(v*2+1,m+1,e,i);
        tree[v]=tree[v*2]+tree[v*2+1];
    }
}

int query(int v, int s, int e, int th){ //th: 0 based idx
    if (s==e) return s;
    int m=(s+e)/2, lc=tree[v*2];
    if(th<lc) return query(v*2, s, m, th);
    else return query(v*2+1, m+1, e, th-lc);
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);

    int n=500'000;
    for (int &i:aa) i=1; init(1,1,n);

    for (int i=2; i<=tree[1]; i++){
        int num=2*query(1,1,n,i-1)-1;
        for (int j=num; j<=tree[1]; j+=num-1){
            int idx=query(1,1,n,j-1);
            aa[idx]=0; update(1,1,n,idx);
        }
    }
    
    char ul[2][9]={"unlucky\n","lucky\n"};
    int nn; cin>>nn; int a;
    for (int _=0; _<nn; _++){
        cin>>a;
        cout << ((a%2 && aa[(a+1)/2])? ul[1] : ul[0]);
    }

    cin.get(); cin.get();
    return 0;
}