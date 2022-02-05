#include<bits/stdc++.h>
using namespace std;
int test();
int aa,bb,a,b,c;
int n = 0;
bool done=0;
int main() {
    aa=bb=0;
    cin>>a>>b>>c;
    cout<<test();
    return 0;
}
int test() {
    cout<<"("<<aa<<","<<bb<<")==>";
    if(aa == c||bb == c) {
        return n;
    }
    n++;
    if(aa == 0&&bb == 0) {
        aa = a;
        n++;
    }
    if(aa == 0) {
        aa = a;
        return test();
    }
    if(bb == b) {
        bb = 0;
        return test();
    }
    if(bb != b) {
        if(aa>=(b-bb)) {
            aa -= (b - bb);
            bb = b;
        }
        if(aa<(b-bb)) {
            bb += aa;
            aa = 0;
        }
        return test();
    }
    if(aa == a&&bb == 0&&done == 1) {
        done == 0;
        return -1;
    }
    return test();
}