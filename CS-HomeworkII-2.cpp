// Author : ysh
// 2024/03/05 Tue 00:04:14
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int n,m;
vc<vc<bool>>f,mark;
vc<vc<int>>ct;
const int xx[] = {0,1,0,-1,1,1,-1,-1};
const int yy[] = {1,0,-1,0,1,-1,1,-1};
#undef outs
#define outs(i) cout<<i<<setw(3)
void print() {
    re(n + 1) out("=="); outl('=');
    out("   ");
    re(i,n) outs(i + 1); nl;
    re(i,n) {
        out(' ');
        outs(i + 1);
        re(j,n) {
            if(mark.at(i).at(j) && f.at(i).at(j)) outs('O');
            else if(mark.at(i).at(j)) outs(ct.at(i).at(j));
            else outs('#');
        }
        nl;
    }
    re(n + 1) out("=="); outl('=');
    return;
}
void init(int m,int px,int py) {
    int x,y;
    do {
        x = rand() % n;
        y = rand() % n;
        if(x == px && y == py) continue;
        if(!f.at(x).at(y)) m--;
        f.at(x).at(y) = 1;
    } while(m != 0);

    re(i,n) re(j,n) re(k,8) {
        int nx = i + xx[k];
        int ny = j + yy[k];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(f.at(nx).at(ny)) ct.at(i).at(j)++;
    }
    return;
}
inline short isend() {
    re(i,n) re(j,n) if(mark.at(i).at(j) && f.at(i).at(j)) return 2; 

    int ans = 0;
    repo(&i,mark) repo(j,i) if(j) ans++;
    if(ans == (n * n) - m) return 1;

    return 0;
}
vc<vc<bool>>mk;
void autoflip(int x,int y) {
    if(mk.at(x).at(y) || ct.at(x).at(y) != 0) return void();
    mk.at(x).at(y) = 1;

    re(i,4) {
        int nx = x + xx[i];
        int ny = y + yy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        autoflip(nx,ny);
    }

    re(i,8) {
        int nx = x + xx[i];
        int ny = y + yy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        mark.at(nx).at(ny) = 1;
    }
    // mk.at(x).at(y) = 0;
    return;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    redo:
    cerr<<"Input the length of the ground: ";
    cin>>n;
    cerr<<"Input the number of mines: ";
    cin>>m;

    if(n <= 0 || m < 0 || m >= n * n) {
        cerr<<"Invalid\n";
        goto redo;
    }

    f = mark = mk = vc<vc<bool>>(n,vc<bool>(n));
    ct = vc<vc<int>>(n,vc<int>(n));
    bool c = 1;

    int x,y;
    print();
    cerr<<"Input [x,y] that you would would like to step on: ";
    while(cin>>x>>y) {
        x--,y--;
        if(x < 0 || y < 0 || x >= n || y >= n || mark.at(x).at(y)) {
            cerr<<"Invalid.\n";
            continue;
        }
        if(c) init(m,x,y);
        c = 0;
        mark.at(x).at(y) = 1;
        mk = vc<vc<bool>>(n,vc<bool>(n));
        autoflip(x,y);
        // repo(i,f) {repo(j,i) outs((j ? 1 : 0)); nl;}
        // repo(i,mark) {repo(j,i) outs((j ? 1 : 0)); nl;}

        short tmp = isend();
        if(tmp == 1) goto yes;
        if(tmp == 2) goto no;
        print();
        cerr<<"Input [x,y] that you would would like to step on: ";
    }

    cerr<<"[Unexpected EOF] You Losed.";
    exit(-1);

    yes:
    cout<<"You won.\n";
    re(i,n) re(j,n) mark.at(i).at(j) = 1;
    print();
    goto pre;

    no:
    cout<<"You Losed.\n";
    re(i,n) re(j,n) if(f.at(i).at(j) && !mark.at(i).at(j)) mark.at(i).at(j) = 1;
    print();
    goto pre;

    pre:
    cerr<<"Would you like to play me again [y/N]? ";
    string a;cin>>a;
    if(a == "y" || a == "Y") goto redo;

    return 0;
}