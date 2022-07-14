#include<bits/stdc++.h>
using namespace std;
int main() {
    double sig = 3.1415926 / 3.0;
    double mmax = -10.0,mmin = 10.0;
    for(double i = -10.0;i<10.0;i = i + 0.001) {
        mmax = max(mmax,sin(i) * sin(sig - i));
        if(mmax == 0.25) cout<<i;
        mmin = min(mmin,sin(i) * sin(sig - i));
        if(mmin == -0.75) cout<<i;
    }
    cout<<mmax<<" "<<mmin;
}