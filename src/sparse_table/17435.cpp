#include <iostream>
using namespace std;

int f[19][500'001];
//f[i][j]: f 2^i (j)

int main(){
    //cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> f[0][i];
    }

    //f2(x)=f(f(x))
    for (int i=1; i<19; i++){
        for (int j=1; j<=n; j++){
            f[i][j]=f[i-1][f[i-1][j]];
        }
    }

    int q;
    cin >> q;
    while (q--){
        int n, x;
        cin >> n >> x;
        for (int i=18; i>=0; i--){
            // n = 10 , 0b1010
            if (n&(1<<i)) x=f[i][x];
        }
        cout<<x<<'\n';
    }

    cin.get(); cin.get();
    return 0;
}