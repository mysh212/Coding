// Author : ysh
// 11/06/2022 Sun 13:32:37.78
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    double a,b,c;cin>>a>>b>>c;
    double alpha = 1 - b;
    double beta = 1 - a;
    cout<<fixed<<setprecision(2)<<(((1 - beta) * c) / (alpha + (1 - alpha - beta) * c) * 100)<<"% "<<(((2 * (1 - beta) * c) / (alpha + (2 - alpha - beta) * c)) * 100)<<"%\n";
    return 0;
}