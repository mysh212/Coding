// Author : ysh
// 2024/03/19 Tue 10:41:17
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

const int xx[] = {0,1,0,-1};
const int yy[] = {1,0,-1,0};

class maze{
    public:
    inline int callme() {
        ifstream in;
    {
        redo:
        cerr<<"Input the filename: ";
        string zzz;cin>>zzz;
        in = ifstream(zzz);
        if(!in) {
            cerr<<"Incorrect filename.\n";
            goto redo;
        }
    }

    stringstream ss;
    string s;
    while(getline(in,s,',')) ss << s << " ";
    in.close();

    #define cin ss
    // while(ss >> s) cout<<s<<"\n";
    int a,b;cin>>a>>b;
    swap(a,b);
    vector<vector<bool>>f(a,vector<bool>(b));
    auto bz = f;
    int px,py,dx,dy;
    int ck = 0;
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            short tmp;cin>>tmp;
            // debug(tmp);
            f.at(i).at(j) = !(tmp == 1);
            if(f.at(i).at(j)) ck++;
            if(tmp == 200) px = i,py = j;
            if(tmp == 201) dx = i,dy = j;
        }
    }

    for(int i = 1,len = min(ck - 2,3);i<=len;i++) {
        int x = rand() % a;
        int y = rand() % b;
        while(!f.at(x).at(y) || bz.at(x).at(y) || (x == px && y == py) || (x == dx && y == dy)) x = rand() % a,y = rand() % b;
        bz.at(x).at(y) = 1;
    }
    
    // for(int i = 0;i<a;i++) {
    //     for(int j = 0;j<b;j++) {
    //         cerr<<(f.at(i).at(j) ? '1' : '0');
    //     }
    //     cerr<<"\n";
    // }
    // debug(px,py,dx,dy);
    
    queue<pair<int,int>>q;
    q.emplace(px,py);
    vector<vector<bool>>mark(a,vector<bool>(b));
    vector<vector<pair<int,int>>>re(a,vector<pair<int,int>>(b,{-1,-1}));
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int x = now.first;
        int y = now.second;
        if(!f.at(x).at(y) || mark.at(x).at(y)) continue;
        mark.at(x).at(y) = 1;
        if(x == dx && y == dy) break;
        for(int i = 0;i<=3;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx < 0 || ny < 0 || nx >= a || ny >= b) continue;
            q.emplace(nx,ny);
            if(re.at(nx).at(ny) == make_pair(-1,-1)) re.at(nx).at(ny) = {x,y};
        }
    }

    if(!mark.at(dx).at(dy)) return cerr<<"This maze has no solution.",0;

    pair<int,int>now({dx,dy});
    vector<vector<char>>pre(a,vector<char>(b,' '));
    while(now != make_pair(px,py)) {
        pre.at(now.first).at(now.second) = 'X';
        now = re.at(now.first).at(now.second);
    }
    // return 2;

    pre.at(px).at(py) = 'S';
    pre.at(dx).at(dy) = 'D';

    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            if(!f.at(i).at(j)) pre.at(i).at(j) = 'W';
        }
    }

    cout<<"Maze: \n";
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            if(bz.at(i).at(j)) cout<<"B ";
            else cout<<(pre.at(i).at(j) == 'X' ? ' ' : pre.at(i).at(j))<<" ";
        }
        cout<<"\n";
    }

    cout<<"Solution: \n";
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            if(pre.at(i).at(j) != 'X' && bz.at(i).at(j)) cout<<"B ";
            else cout<<pre.at(i).at(j)<<" ";
        }
        cout<<"\n";
    }
    #undef cin
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(NULL));

    maze().callme();  

    return 0;
}