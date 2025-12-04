//7662
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int heap_size=0;
vector<int> heap(1000001); //min-max heap

bool is_min_level(int idx){
    return (int)log2(idx)%2==0;
}

//idx(child)에 따라 parent와 child가 유효한 관계면 true
bool check(int idx, int parent, int child){
    //부모-자식==짝-홀: 부모>자식
    if (is_min_level(idx)) return parent>child;

    //부모-자식==홀-짝: 부모<자식
    else return parent<child;
}

//부모(중간)와 비교 후 조부모들과 비교 up
void heap_insert(int item){
    int idx=++heap_size;

    if (idx>1 && check(idx,item,heap[idx/2])){
        heap[idx]=heap[idx/2];
        idx/=2;
    }

    if (is_min_level(idx)){ //홀수층: 위로 갈수록 작음
        while ((idx>=4)&&(item<heap[idx/4])){
            heap[idx]=heap[idx/4];
            idx/=4;
        }
    }
    else{ //짝수층: 위로 갈수록 큼
        while (idx>=4 && item>heap[idx/4]){
            heap[idx]=heap[idx/4];
            idx/=4;
        }
    }
    heap[idx]=item;
}

int find_min(int idx){
    int min_idx=idx;
    vector<int> downs={idx*2,idx*2+1,idx*4,idx*4+1,idx*4+2,idx*4+3};
    for (int &i:downs){
        if (i>heap_size) break;
        else if (heap[i]<heap[min_idx]) min_idx=i;
    }
    return min_idx;
}

int find_max(int idx){
    int max_idx=idx;
    vector<int> downs={idx*2,idx*2+1,idx*4,idx*4+1,idx*4+2,idx*4+3};
    for (int &i:downs){
        if (i>heap_size) break;
        else if (heap[i]>heap[max_idx]) max_idx=i;
    }
    return max_idx;
}

void heap_delete(int idx){
    if (is_min_level(idx)){ //홀수층: 밑에보다 작아야됨
        int min_idx=find_min(idx);
        if (heap[idx]>heap[min_idx]){
            swap(heap[idx],heap[min_idx]);
            if ((min_idx/4==idx)&&(heap[min_idx]>heap[min_idx/2]))
                swap(heap[min_idx],heap[min_idx/2]);
            heap_delete(min_idx);
        }
    }
    else { //짝수층: 밑에보다 커야됨
        int max_idx=find_max(idx);
        if (heap[idx]<heap[max_idx]){
            swap(heap[idx],heap[max_idx]);
            if ((max_idx/4==idx)&&(heap[max_idx]<heap[max_idx/2]))
                swap(heap[max_idx],heap[max_idx/2]);
            heap_delete(max_idx);
        }
    }
}

int heap_min_delete(){
    int ret=heap[1];
    heap[1]=heap[heap_size--];
    heap_delete(1);
    return ret;
}

int heap_max_delete(){
    if (heap_size<=2) return heap[heap_size--];

    int idx;
    if (heap[2]>heap[3]) idx=2;
    else idx=3;
    int ret=heap[idx];
    heap[idx]=heap[heap_size--];
    heap_delete(idx);
    return ret;
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int t,k,n; char c; cin>>t;
    for (int _=0; _<t; _++){
        heap_size=0; cin>>k;
        for (int __=0; __<k; __++){
            cin>>c>>n;
            if (c=='I') heap_insert(n);
            else { //c=='D'
                if (heap_size){
                    if (n==1) heap_max_delete();
                    else heap_min_delete();
                }
            }
        }
        if (heap_size){
            if (heap_size==1)
                cout<<heap[1]<<' '<<heap[1]<<"\n";
            else
                cout<<heap_max_delete()<<' '<<heap[1]<<"\n";
        }
        else cout<<"EMPTY\n";
    }

    cin.get(); cin.get();
    return 0;
}