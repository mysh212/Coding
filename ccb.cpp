// Author : ysh
// 11/04/2022 Fri 15:48:09.90
// https://cses.fi/problemset/task/1137
using namespace std;
#include<tree>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>v(a);
    for(int &i : v) {
        cin>>i;
    }
    vector<vector<int>>f(a);
    for(int i = 1;i<a;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }
    // tree<long long>t(v);
    vector<int>in(a),out(a);
    vector<long long>re;
    function<void(int,int)> check = [&] (int last,int x) {
        in.at(x) = re.size();
        re.push_back(v.at(x));
        for(int &i : f.at(x)) {
            if(i != last) check(x,i);
        }
        out.at(x) = re.size() - 1;
        return;
    };
    check(-1,0);
    for(long long &i : re) cerr<<i<<" ";
    tree<long long>t(re);
    while(b--) {
        int a,b;cin>>a>>b;
        b--;
        if(a == 1) {
            int c;cin>>c;
            int tmp = c;
            c = c - v.at(b);
            v.at(b) = tmp;
            b = in.at(b);
            t.add(b,c);
            continue;
        }
        // cerr<<in.at(b)<<" "<<out.at(b)<<"\n";
        cout<<t.sum(in.at(b),out.at(b))<<"\n";
    }
    return 0;
}