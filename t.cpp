// Author : ysh
// 2023/12/04 Mon 22:10:50
#include<bits/stdc++.h>
using namespace std;
#include<slow>
vector<string> split(string a,string b) {
    vector<string>tmp;
    while(a.find(b) != -1) {
        tmp.push_back(a.substr(0,a.find(b)));
        a = a.substr(a.find(b) + b.size());
    }
    tmp.push_back(a);
    return tmp;
}
vector<string>re;
inline vector<vector<int>>offline(vector<vector<string>>&f) {
    vc<string>mark;
    vc<vc<int>>ans;
    repo(&i,f) repo(&j,i) {
        mark.pb(j);
    }
    sort(all(mark));
    mark.resize(unique(all(mark)) - mark.begin());
    repo(&i,f) {
        vc<int>tmp;
        repo(&j,i) {
            tmp.pb(lower_bound(all(mark),j) - mark.begin());
        }
        ans.pb(tmp);
    }
    re = mark;
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // string c;cin>>c;
    // debug(split(c,","));
    redo:
    cerr<<"Input the name of the file: ";
    string a;cin>>a;
    // if(a.find(".txt") == -1) a = a + ".txt";
    ifstream in(a);
    if(!in) {
        cerr<<"Failed to open file.\n";
        goto redo;
    }

    string b;
    vector<vector<string>>v;
    while(in>>a>>b) {
        v.push_back(split(b,","));
    }
    debug(v);
    auto f = offline(v);
    int n = f.size();
    int k = re.size();
    debug(f);

    double sp,cd;
    cerr<<"Minimum support: ";cin>>sp;
    cerr<<"Minimum confidence: ";cin>>cd;
    
    vector<vector<bool>>mark(n,vector<bool>(k));
    for(int i = 0,len = n;i<len;i++) {
        repo(&j,f.at(i)) mark.at(i).at(j) = 1;
    }

    vector<vector<int>>ans;
    vector<bool>now(k);

    function<bool()> ck = [&] () {
        int ans = 0;
        repo(&i,mark) {
            re(j,k) {
                if(now.at(j) && (!i.at(j))) goto next;
            }
            ans++;
            
            next:
            continue;
        }
        return ans >= n * sp;
    };

    function<void(int)> check = [&] (int x) {
        if(x == k) {
            //debug(now);
            vc<int>tmp;
            if(ck()) re(i,k) if(now.at(i)) tmp.pb(i);
            ans.pb(tmp);
            return;
        }
        check(x + 1);
        now.at(x) = 1;
        check(x + 1);
        now.at(x) = 0;
        return;
    };

    check(0);
    sort(all(ans));
    ans.resize(unique(ans.begin(),ans.end()) - ans.begin());

    outt(frequent patterns);nl;
    debug(ans);

    function<vector<int>(int)> appear = [&] (int x) {
        vc<int>tmp;
        re(i,n) {
            repo(&j,ans.at(x)) {
                if(!mark.at(i).at(j)) goto nt;
            }
            tmp.push_back(i);

            nt:
            continue;
        }
        return tmp;
    };

    function<int(vector<int>,int x)> prob = [&] (vector<int>v,int x) {
        int tmp = 0;
        repo(&i,v) {
            repo(&j,ans.at(x)) if(!mark.at(i).at(j)) goto nr;
            tmp++;

            nr:
            continue;
        }
        return tmp;
    };

    vector<pair<vector<int>,vector<int>>>aans;

    int m = ans.size();
    re(i,1,m) {
        vc<int>tmp(appear(i));
        re(j,1,m) {
            if(i == j) continue;
            int now = prob(tmp,j);
            debug(tmp.size(),now);
            if(now >= tmp.size() * cd) aans.push_back({ans.at(i),ans.at(j)});
        }
    }

    repo(&i,aans) sort(all(i.first)),sort(all(i.second));

    sort(all(aans),[] (pair<vector<int>,vector<int>>&a,pair<vector<int>,vector<int>>&b) {
        if(a.first.size() != b.first.size()) return a.first.size() > b.first.size();
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    repo(&i,aans) {
        repo(&j,i.first) outs(re.at(j));
        outt(=>);
        repo(&k,i.second) outs(re.at(k));
        nl;
    }
    return 0;
}