// Author : ysh
// 01/07/2023 Sat 19:07:20.97
// https://judge.tcirc.tw/ShowProblem?problemid=d118
using namespace std;
struct box{
    int l,r,w,n;
    box(int l = 0,int r = 0,int w = 0,int n = 0):
        l(l), r(r), w(w), n(n) {};
    inline bool operator<(const box a) const {
        return r > a.r;
    }
    void input() {
        cin>>l>>r>>w;
        if(l > r) swap(l,r);
    }
};
inline bool cpr(box a,box b) {
    return a.r < b.r;
}
vector<int>mark;
int check(vector<box>&f,int n) {
    // cerr<<n<<"\n";
    if(n == -1) return 0;
    if(mark.at(n) != 0) return mark.at(n);
    auto &now = f.at(n);
    auto found = upper_bound(f.rbegin(),f.rend(),box(0,now.l,0,0));
    if(found == f.rend()) return mark.at(n) = max(now.w,check(f,n - 1));
    return mark.at(n) = max(check(f,f.rend() - found - 1) + now.w,check(f,n - 1));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    mark.resize(n);
    vector<box>f(n);
    for(auto &i : f) {
        i.input();
    }
    // vector<box>g = f;
    sort(f.begin(),f.end(),cpr);
    cout<<check(f,n - 1);
    // for(int &i : mark) cerr<<i<<" ";
    return 0;
}