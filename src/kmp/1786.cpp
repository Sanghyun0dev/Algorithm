//1786

#include <iostream>
#include <vector>
using namespace std;

vector<int> getpi(const string &p){
    int n = p.size();
    vector<int> pi(n);

    int j=0;
    for (int i=1; i<n; i++){
        while (j>0 && p[i]!=p[j]) j=pi[j-1];
        if (p[i]==p[j]) pi[i]=++j;
    }
    return pi;
}

vector<int> kmp(const string &s, const string &p){
    vector<int> pi = getpi(p);
    int n= s.size(), m=p.size();

    int j=0;
    vector<int> res;
    for (int i=0; i<n; i++){
        while (j>0 && s[i]!=p[j]) j=pi[j-1];
        if (s[i]==p[j]){
            if (j==m-1){
                res.push_back(i-j+1);
                j=pi[j];
            }
            else j++;
        }
    }
    return res;
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);

    string s,p;
    getline(cin,s);
    getline(cin,p);

    vector<int> res=kmp(s,p);

    cout<<res.size() << '\n';
    for (int i:res) cout<<i<<'\n';

    cin.get(); cin.get();
    return 0;
}