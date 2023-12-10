// Author : ysh
// 2023/12/07 Thu 17:16:53
#include<bits/stdc++.h>
using namespace std;
#include<slow>
const int R = 20000;
const int MAX = 90000;
vector<bitset<R>>s;
vector<bitset<MAX>>rez;
int n,k;
long double c,d;
vector<string> split(string a,string b) {
    vector<string>f;
    while(a.find(b) != string::npos) {
        f.push_back(a.substr(0,a.find(b)));
        a = a.substr(a.find(b) + b.size());
    }
    f.push_back(a);
    return f;
}
vector<vector<string>> input(ifstream& in) {
    vector<vector<string>>f;
    string a;
    while(in>>a>>a) {
        f.pb(split(a,","));
    }
    return f;
}
vector<string>re;
vector<vector<int>> offline(vector<vector<string>>f) {
    vector<string>v;
    repo(&i,f) repo(&j,i) v.pb(j);
    sort(all(v));
    v.resize(unique(v.begin(),v.end()) - v.begin());

    vc<vc<int>>ans;
    repo(&i,f) {
        vc<int>tmp;
        repo(&j,i) tmp.pb(lower_bound(all(v),j) - bg(v));
        ans.pb(tmp);
    }

    re = v;
    return ans;
}
inline bitset<R> mb(int x) {
    bitset<R>s;
    s.set(x);
    return s;
}
inline bool check(bitset<R>r) {
    bitset<MAX>tmp;
    tmp.set();
    re(i,k) if(r.test(i)) tmp = tmp & rez.at(i);
    return tmp.count() >= n * c;
}
inline bool co(int x) {
    int ans = 0;
    repo(&i,s) if(i.test(x)) ans++;
    return ans >= n * c;
}
bitset<MAX>mark;
bitset<R>mk;
inline bool ck(bitset<R>l,bitset<R>r) {
    bitset<MAX>ans;
    ans.set();
    re(i,k) if(r.test(i)) ans = ans & rez.at(i);

    if(mk == l) return (mark & ans).count() * 1.0 >= mark.count() * d;

    mk = l;
    mark.set();
    re(i,k) if(l.test(i)) mark = mark & (rez.at(i));

    return (mark & ans).count() >= mark.count() * d;
}
vector<bitset<R>> mg(int l,int r) {
    debug(l,r);
    if(l == r) return (co(l) ? vector<bitset<R>>({mb(l)}) : vector<bitset<R>>({}));
    int mid = (l + r) >> 1;
    vector<bitset<R>>ans;
    auto left = mg(l,mid);
    auto right = mg(mid + 1,r);
    repo(&i,left) ans.push_back(i);
    repo(&j,right) ans.push_back(j);

    repo(&i,left) repo(&j,right) if(check(i | j)) ans.push_back(i | j);
    return ans;
}
ostream& operator<<(ostream& fout,vector<bitset<R>>s) {
    repo(i,s) {
        re(j,k) if(i.test(j)) fout<<re.at(j)<<" ";
        fout<<"\n";
    }
    return fout;
}
inline bool alldigit(string x) {
    if(x.size() > 9) return 0;
    repo(&i,x) if(!isdigit(i)) return 0;
    return 1;
}
bool cp(string l,string r) {
    if(alldigit(l) && alldigit(r)) return stoi(l) < stoi(r);
    if(alldigit(l) || alldigit(r)) return alldigit(l);
    return l < r;
}
bool operator<(vector<string> l,vector<string> r) {
    re(i,min(l.size(),r.size())) {
        if(l.at(i) == r.at(i)) continue;
        return cp(l.at(i),r.at(i));
    }
    return l < r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    redo:
    string a;
    cerr<<"Input the name of the file: ";cin>>a;
    if(a.find(".txt") == -1) a = a + ".txt";

    ifstream in(a);
    if(!in) {
        cerr<<"Failed to open file.\n";
        goto redo;
    }
    cerr<<"Input the support value: ";cin>>c;
    cerr<<"Input the confidence value: ";cin>>d;
    auto f = offline(input(in));

    ofstream lout(a.substr(0,a.size() - 4) + "_Output" + ".txt");

    // debug(f);
    n = f.size(); 
    k = re.size();
    rez.resize(k);
    debug(k);
    assert(k <= R);

    s.resize(n);
    re(i,n) repo(&j,f.at(i)) s[i].set(j),rez[j].set(i);

    auto ans = mg(0,k - 1);
    int m = ans.size();

    vc<pair<bitset<R>,bitset<R>>>aans;
    re(i,m) re(j,m) {
        debug(i,j,m);
        if(i == j) continue;
        if(!((ans.at(i) & ans.at(j)).count() == 0)) continue;

        if(ck(ans.at(i),ans.at(j))) aans.push_back({ans.at(i),ans.at(j)});
    }

    outl(aans.size());
    vector<array<vector<string>,2>>aaans;
    repo(&i,aans) {
        vc<string>ll,rr;
        re(j,k) if(i.first.test(j)) ll.pb(re.at(j));
        re(l,k) if(i.second.test(l)) rr.pb(re.at(l));
        aaans.pb({ll,rr});
    }

    repo(&i,aaans) sort(all(i[0]),cp),sort(all(i[1]),cp);
    sort(all(aaans),[](array<vector<string>,2>a,array<vector<string>,2>b) {
        if(a[0].size() != b[0].size()) return a[0].size() > b[0].size();
        if(a[1].size() != b[1].size()) return a[1].size() > b[1].size();
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    });

    repo(&i,aaans) {
        repo(&j,i[0]) outs(j);
        outt(=>);out(" ");
        repo(&l,i[1]) outs(l);
        nl;
    }
    return 0;
}