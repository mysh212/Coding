// Author : ysh
// Pre-compiled : 2026/11/07 Sat 20:43:22

#include<bits/stdc++.h>
# 0 "<stdin>"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "<stdin>"



using namespace std;
# 1 "/Users/ysh/lab/Coding/library/slow" 1
# 38 "/Users/ysh/lab/Coding/library/slow"
template<class T>
std::istream& operator>>(std::istream& fin,std::vector<T>&f) {
    for(auto &&i : f) fin>>i;
    return fin;
}
template<class T,class R>
std::istream& operator>>(std::istream& fin,std::pair<T,R>&x) {
    fin>>x.first>>x.second;
    return fin;
}

template<class T>
std::ostream& operator<<(std::ostream& fout,std::vector<T>&f) {
    for(auto &i : f) fout<<i<<" ";
    return fout;
}
template<class T,class R>
std::ostream& operator<<(std::ostream& fout,std::pair<T,R>&x) {
    fout<<x.first<<" "<<x.second;
    return fout;
}
# 6 "<stdin>" 2
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;cin>>n>>k;
    vector<pair<int, int>>f(k);
    for(auto &i : f) cin>>i.first>>i.second, i.first--, i.second--;

    int mmax = 0;
    int d = -1;
    vector<int>ct(n);
    map<int, map<int, int>>m;
    for(auto &[l, r] : f) {
        auto found = m.find(l);
        if(found == m.end()) m.insert({l, map<int, int>({{r, 1}})});
        else (found -> second)[l] += 1;
    }

    for(auto &[l, _] : f) ct[l]++;
    for(int i = 0;i<n;i++) if(ct.at(i) > mmax) mmax = ct.at(i), d = i;

    for(int i = 0;i<n;i++) {
        int now = mmax, dd = d;

        if(i == d) {
            auto p = ct;
            for(auto &[l, r] : m[i]) p[l] += r;

            vector<pair<int, int>>mm(n);
            for(int i = 0;i<n;i++) mm[i] = {i, p[i]};

            ranges::sort(mm, {}, &pair<int, int>::second);
            reverse(mm.begin(),mm.end());

            if(mm[0].first == i) cout<<mm[1].first + 1;
            else cout<<mm[0].first + 1;

            cout<<"\n";

            '*';

            continue;
        }

        '*';
        auto found = m.find(i);
        if(found != m.end()) {
            for(auto &[l, r] : found -> second) {
                if(ct.at(l) + r > now) {
                    now = ct.at(l) + r;
                    dd = l;
                }
            }
        }

        cout<<dd + 1<<"\n";
    }

    return 0;
}
