// Author : ysh
<<<<<<< HEAD
<<<<<<< HEAD
// 03/18/2023 Sat 20:13:20.42
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int check(vector<int>&f) {
    int last = f.at(0);
    vector<int>mark((4e5) + 1);
    for(int i = 1;i<f.size();i++) {
        mark.at(f.at(i) + last) = 1;
        last = f.at(i);
    }
    for(int i = 0;i<=(4e5);i++) {
        if(!mark.at(i)) return i;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        int m = n;
        int a,b,c;a = b = c = 0;
        bool d = 0;
        while(n--) {
            int tmp;cin>>tmp;
            if(tmp == 0) a++;
            else if(tmp == 1) b++;
            else c++,d = d | (tmp > 2);
        }
        // debug(a,b,c);
        if(m == 1 && b == 1) cout<<1;
        else if(a - 1 <= b + c) cout<<0;
        else if(c >= 2 || (b == 0 && c == 0 && a != 0)) cout<<1;
        else if((b >= 2 && c == 1) || (b == 1)) cout<<2;
        else cout<<3;
        cout<<"\n";
        continue;
=======
=======
>>>>>>> 621ce5dcd29f3c018096c1c72754b7eb48ec2b78
// 04/28/2023 Fri 23:25:36.78
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        b = b / __gcd(a,b);
        string now = "";
        int left = 1;
        set<string>s;
        int t = 0;
        while(++t) {
            left = left * 10;
            now = now + (char) ('0' + (left / b));
            left = left % b;
            if(s.find(now) != s.end()) {
                cout<<(t >> 1)<<"\n";
                break;
            }
            s.insert(now + now);
        }
<<<<<<< HEAD
>>>>>>> 621ce5dcd29f3c018096c1c72754b7eb48ec2b78
=======
>>>>>>> 621ce5dcd29f3c018096c1c72754b7eb48ec2b78
    }
    return 0;
}