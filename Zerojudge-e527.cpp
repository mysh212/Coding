#include<bits/stdc++.h>
using namespace std;
int test();
int logg[1026][1026][7] = {};
int aa,bb,a,b,c,r;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int ab;cin>>ab;
    for(int i = 0;i<ab;i++) {
    cin>>a>>b>>c;
    aa=bb=0;
r = i + 1;
    cout<<test()<<"\n";
    }
    return 0;
}
int test() {
    queue<pair<int,int>> q;
    queue<pair<int,int>> m;
    q.push(make_pair(0,0));
    q.push(make_pair(0,0));
    m.push(make_pair(3,0));
    m.push(make_pair(4,0));
    while(1) {
        pair<int,int> pq = q.front();
        pair<int,int> pm = m.front();
        int aa = pq.first;
        int bb = pq.second;
        int move=pm.first;
        int nn=pm.second;
        //cout<<nn<<"\n";
        if(logg[aa][bb][move] == r&&!(q.empty())) {
            q.pop();
            m.pop();
            continue;
        }
        if(q.empty()) {
        	return -1;
		}
        logg[aa][bb][move] = r;
        if(move == 1) {
            bb = 0;
            nn+=1;
            for(int i = 1;i<=6;i++) {
                //cout<<"("<<aa<<","<<bb<<","<<i<<","<<nn<<")";
                q.push(make_pair(aa,bb));
                m.push(make_pair(i,nn));
            }
        }
        if(move == 2) {
            aa = 0;
            nn+=1;
            for(int i = 1;i<=6;i++) {
                q.push(make_pair(aa,bb));
                m.push(make_pair(i,nn));
            }
        }
        if(move == 3) {
            aa = a;
            nn+=1;
            for(int i = 1;i<=6;i++) {
                //cout<<"("<<aa<<","<<bb<<","<<i<<","<<nn<<")";
                q.push(make_pair(aa,bb));
                m.push(make_pair(i,nn));
            }
        }
        if(move == 4) {
            bb = b;
            nn+=1;
            for(int i = 1;i<=6;i++) {
                //cout<<"("<<aa<<","<<bb<<","<<i<<","<<nn<<")";
                q.push(make_pair(aa,bb));
                m.push(make_pair(i,nn));
            }
        }
        if(move == 5) {
            if(bb>=(a-aa)) {
                bb -= (a - aa);
                aa = a;
            }
            if(bb<(a-aa)) {
                aa += bb;
                bb = 0;
            }
            nn+=1;
            for(int i = 1;i<=6;i++) {
                //cout<<"("<<aa<<","<<bb<<","<<i<<","<<nn<<")";
                q.push(make_pair(aa,bb));
                m.push(make_pair(i,nn));
            }
        }
        if(move == 6) {
            if(aa>=(b-bb)) {
                aa -= (b - bb);
                bb = b;
            }
            if(aa<(b-bb)) {
                bb += aa;
                aa = 0;
            }
            nn+=1;
            for(int i = 1;i<=6;i++) {
                //cout<<"("<<aa<<","<<bb<<","<<i<<","<<nn<<")";
                q.push(make_pair(aa,bb));
                m.push(make_pair(i,nn));
            }
        }
        if(aa == c||bb == c) {
            return nn;
            break;
        }
        q.pop();
        //cout<<aa<<","<<bb<<"\t";
        m.pop();
        /*
        if(r == 8){
    for(int i = 0;i<100;i++) {
    pq = q.front();
    pm = m.front();
    aa = pq.first;
    bb = pq.second;
    move=pm.first;
    nn=pm.second;
        cout<<"("<<aa<<","<<bb<<","<<move<<","<<nn<<")";
        q.pop();
        m.pop();
    }
    system("pause");
    }
    */
    }
}
