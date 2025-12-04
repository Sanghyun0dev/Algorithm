//1717
#include <iostream>
using namespace std;

// 유니온 파인드 (Union Find)

int* P;

int find(int k){
  if (P[k]==-1) return k;
  //P[P[k]]=find(P[k])
  P[k]=find(P[k]);
  return P[k];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // n: 초기 집합,   m: 연산 개수(time)
  int n, m;
  cin >> n >> m;

  P = new int[n + 1]; // P 초기화. 모든 요소가 부모
  for (int i = 0; i <= n; ++i) P[i] = -1;

  for (int i = 0; i < m; ++i){
    int k, a, b;
    cin >> k >> a >> b;
    if (k == 1){ // check
      if (find(a) == find(b)) cout << "YES\n";
      else cout << "NO\n";
    }else{ // union
      if (find(a) != find(b)) P[find(a)] = find(b);
    }
  }

  delete[] P;
  return 0;
}
