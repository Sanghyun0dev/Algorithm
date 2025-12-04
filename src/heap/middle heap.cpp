//2696
#include <iostream>
#include <vector>
using namespace std;

vector<int> max_heap(9999), min_heap(9999);
int min_size=0, max_size=0;

void max_insert(int item){
    int tmp=++max_size;
    while (tmp>1 && item>max_heap[tmp/2]){
        max_heap[tmp]=max_heap[tmp/2];
        tmp/=2;
    }
    max_heap[tmp]=item;
}

void min_insert(int item){
    int tmp=++min_size;
    while (tmp>1 && item<min_heap[tmp/2]){
        min_heap[tmp]=min_heap[tmp/2];
        tmp/=2;
    }
    min_heap[tmp]=item;
}

int max_delete(){
    int item=max_heap[1];
    int tmp=max_heap[max_size--];
    int parent=1, child=2;
    while (child<=max_size){
        if ((child<max_size)&&(max_heap[child]<max_heap[child+1]))
            child++;
        if (tmp>max_heap[child]) break;
        else {
            max_heap[parent]=max_heap[child];
            parent=child; child*=2;
        }
    }
    max_heap[parent]=tmp;
    return item;
}

int min_delete(){
    int item=min_heap[1];
    int tmp=min_heap[min_size--];
    int idx=1;
    int parent=1, child=2;
    while (child<=min_size){
        if ((child<min_size)&&(min_heap[child]>min_heap[child+1]))
            child++;
        if (tmp<min_heap[child]) break;
        else {
            min_heap[parent]=min_heap[child];
            parent=child; child*=2;
        }
    }
    min_heap[parent]=tmp;
    return item;
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int t,m,x; cin>>t;
    vector<int> res;
    for (int _=0; _<t; _++){
        cin>>m; min_size=0; max_size=0;
        res.clear();
        for (int i=1; i<=m; i++){
            cin>>x;
            if (max_size==0) max_insert(x);
            else if (min_size==0){
                if (max_heap[1]<x) min_insert(x);
                else {
                    min_insert(max_delete());
                    max_insert(x);
                }
            }
            else if (x<max_heap[1]) max_insert(x);
            else min_insert(x);

            if (i%2==1){
                //to max_size==min_size+1
                while (max_size!=min_size+1){
                    if (max_size<min_size+1)
                        max_insert(min_delete());
                    else min_insert(max_delete());
                }
                res.push_back(max_heap[1]);
            }
        }
        cout<<m/2+1<<"\n";
        for (int i=0; i<m/2+1; i++){
            cout<<res[i]<<' ';
            if (i%10==9) cout<<"\n";
        }
        if ((m/2+1)%10!=0)cout<<"\n";
    }
    cin.get(); cin.get();
    return 0;
}