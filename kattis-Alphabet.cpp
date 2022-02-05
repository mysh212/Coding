// Author : ysh
// 01/30/2022 Sun 11:39:58.43
// https://open.kattis.com/problems/alphabet
#include<bits/stdc++.h>
using namespace std;
inline void pc(int*);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;cin>>a;
    int fst[27] = {};
    // pc(fst);
    int tmpj = 0;
    for(char i : a) {
        int j = (int) i - (int) 'a' + 1;
        
        if(tmpj == j) continue;
        tmpj = j;
        fst[j] = max(fst[j - 1] + 1,fst[j]);
        for(int i = j+1;i<=26;i++) {
            fst[i] = max(fst[i - 1],fst[i]);
        }
        
    //     cout<<a<<"\n";
    //     system("pause");
    // pc(fst);
    }
    cout<<26 - fst[26];
    return 0;
}
inline void pc(int* fst) {
    for(int i = 1;i<=26;i++) {
        cout<<(char) (i - 1 + (int) 'A')<<" ";
    }
    cout<<"\n";
    for(int i = 1;i<=26;i++) {
        cout<<fst[i]<<" ";
    }
    cout<<"\n";
}