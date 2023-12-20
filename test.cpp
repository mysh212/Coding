// Author : ysh
// 2023/12/20 Wed 23:09:31
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#define fs first
#define sd second
#ifndef LOCAL
#undef assert
#define assert(...)
#endif

pair<int,int> operator+ (pair<int,int>a,pair<int,int>b) {
	return {a.first + b.first,a.second + b.second};
}

struct box_E24124723{
	const int xx[8] = {-1,0,1,0,1,-1,1,-1};
	const int yy[8] = {0,1,0,-1,1,1,-1,-1};
	const int dd[7] = {3,2,1,1,1,2,3};

	#define att(i,j) at(i).at(j)
	#define inside(i,j) (i >= 0 && i <= R - 1 && j >= 0 && j <= R - 1)
	#define R 7

	vc<vc<int>>f;
	int c,ot,p,n;
	map<vc<int>,long double>m;

	box_E24124723(vc<vc<int>>v,int c,int ot,int p):
		f(v), c(c), ot(ot), p(p), n(v.size()) {};

	inline int count(int c) {
		int ans = 0;
		repo(&i,f) repo(&j,i) if(j == c) ans++;
		return ans;
	}

	inline bool line(int x,int y) {
		assert(inside(x,y));
		if(f.att(x,y) == 0 || f.att(x,y) == -1) return 0;

		re(i,4) {
			re(j,1,3) {
				int nx = x + (xx[i] * dd[y] * j);
				int ny = y + (yy[i] * dd[x] * j);

				if(!inside(nx,ny)) break;
				if(f.att(nx,ny) != f.att(x,y)) break;
				// debug(nx,ny);
				if(j == 2) return 1;
			}
		}

		re(i,2) {
			re(j,0,3,2) {
				int nx = x + (xx[i + j] * dd[y]);
				int ny = y + (yy[i + j] * dd[x]);

				if(!inside(nx,ny)) break;
				if(f.att(nx,ny) != f.att(x,y)) break;
				if(j == 2) return 1;
			}
		}
		return 0;
	}


	inline bool valid(vc<int>v,int p) {
		if(not(inside(v[1],v[2]) && inside(v[3],v[4]) && ((v[6] == R && v[7] == R) || inside(v[6],v[7])))) outl(v),exit(-1);
		assert(v[0] != v[5]);

		bool ok = 0;
		// auto ans = f;
		int x,y,nx,ny,dx,dy,c,ot;
		x = v[1],y = v[2],nx = v[3],ny = v[4],dx = v[6],dy = v[7],c = v[0],ot = v[5];
		if(make_pair(x,y) == make_pair(nx,ny)) {
			if(p != 1) return false;
			if(f.att(x,y) != 0) return false;

			f.att(x,y) = c;
			if(line(x,y)) ok = 1;
			f.att(x,y) = 0;
		} else {
			if(p != 2) return false;
			if(f.att(x,y) != c || f.att(nx,ny) != 0) return false;
			if(count(v[0]) > 3) {
				int rx = abs(x - nx);
				int ry = abs(y - ny);

				if(!(rx == 0 || ry == 0)) return false;
				if(ry == 0) if(!(rx == dd[y])) return false;
				if(rx == 0) if(!(ry == dd[x])) return false;
			}

			f.att(x,y) = 0;
			f.att(nx,ny) = c;
			if(line(nx,ny)) ok = 1;
			f.att(nx,ny) = 0;
			f.att(x,y) = c;
		}

		if(ok) {
			if(!inside(dx,dy) || f.att(dx,dy) != ot) return false;
			if(line(dx,dy)) {
				if(anylone(ot)) return false;
			}
		} else {
			if(!(dx == R && dy == R)) return false;
		}

		return true;
	}

	inline bool anylone(int c) {
		re(i,R) re(j,R) if(f.att(i,j) == c && !line(i,j)) return 1;
		return 0;
	}

	vc<vc<int>> move(vc<int>v) {
		if(v == vector<int>({0,0,0,0,0,0,0,0})) return f;
		assert(v.size() == 8);
		auto ans = f;

		assert(inside(v[1],v[2]) && inside(v[3],v[4]) && ((v[6] == R && v[7] == R) || inside(v[6],v[7])));
		if(v[1] == v[3] && v[2] == v[4]) {
			assert(f.at(v[1]).at(v[2]) == 0);
			ans.at(v[1]).at(v[2]) = v[0];
		} else {
			assert(f.at(v[1]).at(v[2]) == v[0] && f.at(v[3]).at(v[4]) == 0);
			swap(ans.at(v[1]).at(v[2]),ans.at(v[3]).at(v[4]));
			// swap(f.att(v[1],v[2]),f.att(v[3],v[4]));
		}

		if(!(v[6] == R && v[7] == R)) {
			assert(inside(v[6],v[7]) && f.att(v[6],v[7]) == v[5]);

			if(line(v[6],v[7])) assert(!anylone(v[5])) ;
			ans.att(v[6],v[7]) = 0;
		}

		return ans;
	}

	pair<int,int> ck(vc<vc<int>>f,int c,int ot,int d,int p) {
		box_E24124723 tb = box_E24124723(f,c,ot,p);
		if(d == 0) {
			int ans = 0;
			re(i,R) re(j,R) if(tb.line(i,j)) {
				if(f.att(i,j) == c) ans++;
				if(f.att(i,j) == ot) ans--;
			}
			// if(ans != 0) repo(&i,f) {
			// 	repo(&j,i) {
			// 		if(j == -1) out("  ");
			// 		else outs(j);
			// 	}
			// 	nl;
			// }
			// if(ans != 0) {debug(ans);}
			return {ans,1};
		}

		vc<pair<int,int>>l,r,e;
		re(i,R) re(j,R) {
			if(f.att(i,j) == c) l.emplace_back(i,j);
			if(f.att(i,j) == ot) r.emplace_back(i,j);
			if(f.att(i,j) == 0) e.emplace_back(i,j);
		}
		
		map<long double,pair<int,int>>mark;
		if(p == 1) {
			r.emplace_back(R,R);
			repo(&i,e) repo(&j,r) {
				auto now = {c,i.fs,i.sd,i.fs,i.sd,ot,j.fs,j.sd};
				if(tb.valid(now,p)) {
					auto tmp = ck(box_E24124723(f,c,ot,p).move(now),ot,c,d - 1,p);
					if(tmp == make_pair(0,0)) continue;
					long double found = tmp.first / tmp.second;
					if(mark.find(found) == mark.end()) mark.insert({found,tmp});
					else mark.find(found)->second = mark.find(found)->second + tmp;
				}
			}
		}
		if(p == 2) {
			r.emplace_back(R,R);
			repo(&i,l) re(k,4) repo(&j,r) {
				int x = i.fs;
				int y = i.sd;

				int nx = x + (xx[k] * dd[y]);
				int ny = y + (yy[k] * dd[x]);

				if(!inside(nx,ny)) continue;
				auto now = {c,x,y,nx,ny,ot,j.fs,j.sd};
				if(tb.valid(now,p)) {
					auto tmp = ck(box_E24124723(f,c,ot,p).move(now),ot,c,d - 1,p);
					if(tmp == make_pair(0,0)) continue;
					long double found = tmp.first / tmp.second;
					if(mark.find(found) == mark.end()) mark.insert({found,tmp});
					else mark.find(found)->second = mark.find(found)->second + tmp;
				}
			}
		}
		if(mark.empty()) return {0,0};
		pair<int,int> ans({prev(mark.end())->second.first,prev(mark.end())->second.second});
		return {-ans.first,-ans.second};
	}

	vc<int> check() {
		debug(p);
		vc<pair<int,int>>l,r,e;
		re(i,R) re(j,R) {
			if(f.att(i,j) == c) l.emplace_back(i,j);
			if(f.att(i,j) == ot) r.emplace_back(i,j);
			if(f.att(i,j) == 0) e.emplace_back(i,j);
		}

		vc<pair<vc<int>,vc<vc<int>>>>ans;
		if(p == 1) {
			r.emplace_back(R,R);
			repo(&i,e) repo(&j,r) {
				auto now = {c,i.fs,i.sd,i.fs,i.sd,ot,j.fs,j.sd};
				if(valid(now,p)) ans.push_back({now,move(now)});
			}
		}
		if(p == 2) {
			r.emplace_back(R,R);
			repo(&i,l) re(k,4) repo(&j,r) {
				int x = i.fs;
				int y = i.sd;

				int nx = x + (xx[k] * dd[y]);
				int ny = y + (yy[k] * dd[x]);

				if(!inside(nx,ny) || f.att(nx,ny) != 0) continue;
				auto now = {c,x,y,nx,ny,ot,j.fs,j.sd};
				if(valid(now,p)) ans.push_back({now,move(now)});
			}
		}

		if(ans.empty()) return {0,0,0,0,0,0,0,0};

		long double mmax = -INFINITY;
		vc<vc<int>>aans;
		repo(&i,ans) {
			auto tmp = ck(i.sd,ot,c,2,p);
			m.insert({i.fs,-tmp.first * 1.0 / tmp.second});
		}
		repo(&j,m) mmax = max(mmax,j.sd);
		repo(&k,m) if(k.second == mmax) aans.push_back(k.first);

		random_shuffle(all(aans));
		return aans.back();
	}

	vc<int>parseout(vc<int>f) {
		assert(f.size() == 8);
		if(f[6] == R && f[7] == R) f[6]++,f[7]++;
		return f;
	}
};

vector<int> Algorithm(vector<vector<int>>&f,int c,int ot,int p) {
	srand(time(NULL));
	auto now = box_E24124723(f,c,ot,p);
	auto ans = now.check();
	f = now.move(ans);	
	return now.parseout(ans);
}

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

    
// }