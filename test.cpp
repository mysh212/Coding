// Author : ysh
// 2023/12/20 Wed 23:09:31
// AC(0.86)
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#define fs first
#define sd second
#ifndef LOCAL
#undef assert
#define assert(...)
#endif

#ifdef LOCAL
#define RAND_SEED 10
#else
#define RAND_SEED time(NULL)
#endif

#define DEEP_P1 2
#define DEEP_P2 2
#define AUTO_GAP 5
#define ALLOW_RANDOM 1
#define LINE_SCORE 0
#define DC_SCORE 3
#define BL_SCORE 0
#define SL_SCORE 0
#define CR_COUNT 10
#define WIN_SCORE 20
#define ALLOW_GAP 10
#define MAX 3

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

	bool canremove(pair<int,int>a,pair<int,int>b,int c,int op) {
		assert(inside(a.first,a.second) && inside(b.first,b.second));
		bool ok = false;
		if(a == b) {
			assert(f.att(a.first,a.second) == 0);

			f.att(a.first,a.second) = c;
			if(line(a.first,a.second)) ok = true;
			f.att(a.first,a.second) = 0;
		} else {
			assert(f.att(a.first,a.second) == c && f.att(b.first,b.second) == 0);

			f.att(a.first,a.second) = 0;
			f.att(b.first,b.second) = c;
			if(line(b.first,b.second)) ok = true;
			f.att(a.first,a.second) = c;
			f.att(b.first,b.second) = 0;
		}
		return ok;
	}

	inline int beline(int x,int y,int c) {
		assert(inside(x,y));
		assert(c != 0 && c != -1);
		if(f.att(x,y) != 0 || f.att(x,y) == -1) return -1;

		re(i,4) {
			re(j,1,3) {
				int nx = x + (xx[i] * dd[y] * j);
				int ny = y + (yy[i] * dd[x] * j);

				if(!inside(nx,ny)) break;
				if(f.att(nx,ny) != c) break;
				if(j == 2) return i;
			}
		}

		re(i,2) {
			re(j,0,3,2) {
				int nx = x + (xx[i + j] * dd[y]);
				int ny = y + (yy[i + j] * dd[x]);

				if(!inside(nx,ny)) break;
				if(f.att(nx,ny) == -1 || f.att(nx,ny) == 0) break;
				if(!(f.att(nx,ny) == c)) break;
				if(j == 2) return i;
			}
		}
		return -1;
	}

	int countline(int x,int y,int c,int gap) {
		int ans = 0;
		assert(inside(x,y));
		if(c == 0 || c == -1) return 0;

		re(i,4) {
			int now = 0;
			re(j,0,3) {
				int nx = x + (xx[i] * dd[y] * j);
				int ny = y + (yy[j] * dd[x] * j);

				if((!inside(nx,ny)) || (!(f.att(nx,ny) == c || f.att(nx,ny) == 0))) {
					now = 0;
					break;
				}
				if(f.att(nx,ny) == c) now++;
			}
			if(now >= gap) ans++;
		}
		return ans;
	}

	inline int strictline(int x,int y,int c,int t = -1) {
		int now = beline(x,y,c);
		if(t == -1) t = c;
		if(now == -1) return -1;

		now = (now + 1) & 1;
		re(i,0,3,2) {
			int nx = x + (xx[now + i] * dd[y]);
			int ny = y + (yy[now + i] * dd[x]);

			if(!inside(nx,ny)) continue;
			if(f.att(nx,ny) == t) return now + i;
		}
		return -1;
	}

	pair<int,int> getremove(int op) {
		if(anylone(op)) {
			re(i,R) re(j,R) if(strictline(i,j,op) != -1) {
				int ans = strictline(i,j,op);
				int nx = i + (xx[ans] * dd[j]);
				int ny = j + (yy[ans] * dd[i]);

				assert(inside(nx,ny));
				return {nx,ny};
			}
			re(i,R) re(j,R) if(f.att(i,j) == op && !line(i,j)) return {i,j};
		} else {
			for(int k = 2;k>0;k--) re(i,R) re(j,R) if(countline(i,j,op,3) >= k) return {i,j};
			re(i,R) re(j,R) if(f.att(i,j) == op) return {i,j};
		}
		return {R,R};
	}

	vector<int> autoplace(int now) {
		assert(now == 1);

		const int x = 3,y = 3;
		re(l,2) {
			re(k,3) {
				const int pre[] = {2,1,3};
				int j = pre[k];
				re(i,4) {
					if(l == 1) i = i + 4;
					int nx = x + (xx[i] * j);
					int ny = y + (yy[i] * j);

					assert(inside(nx,ny));
					if(f.att(nx,ny) != 0) continue;
					pair<int,int> ans({R,R});
					if(canremove({nx,ny},{nx,ny},c,ot)) ans = getremove(ot);
					return {c,nx,ny,nx,ny,ot,ans.first,ans.second};
				}
			}
		}

		return fool(now);
	}

	vc<int>fool(int p) {
		assert(p == 1 || p == 2);
		if(p == 1) re(i,R) re(j,R) {
			re(k,R) re(l,R) {
				if(valid({c,i,j,i,j,ot,k,l},p)) return {c,i,j,i,j,ot,k,l};
			}
			if(valid({c,i,j,i,j,ot,R,R},p)) return {c,i,j,i,j,ot,R,R};
		}
		if(p == 2) re(i,R) re(j,R) re(k,R) re(l,R) {
			re(m,R) re(n,R) if(valid({c,i,j,k,l,ot,m,n},p)) return {c,i,j,k,l,ot,m,n};
			if(valid({c,i,j,k,l,ot,R,R},p)) return {c,i,j,k,l,ot,R,R};
		}
		// outl(c);
		// repo(&i,f) outl(i);
		return {c,0,0,0,0,ot,R,R};
		assert(0);
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
		// if(count(c) <= 2) return {-WIN_SCORE,1};
		if(d == 0) {
			int ans = 0;
			re(i,R) re(j,R) if(tb.line(i,j)) {
				if(f.att(i,j) == c) ans += LINE_SCORE;
				if(f.att(i,j) == ot) ans -= LINE_SCORE;
			}
			re(i,R) re(j,R) if(tb.double_corner(i,j,c)) ans += DC_SCORE;
			re(i,R) re(j,R) if(tb.double_corner(i,j,ot)) ans -= DC_SCORE;
			re(i,R) re(j,R) if(tb.beline(i,j,c)) ans += BL_SCORE;
			re(i,R) re(j,R) if(tb.beline(i,j,ot)) ans -= BL_SCORE;
			re(i,R) re(j,R) if(tb.strictline(i,j,c)) ans += SL_SCORE;
			re(i,R) re(j,R) if(tb.strictline(i,j,ot)) ans -= SL_SCORE;
			ans += tb.count(c) * CR_COUNT;
			ans -= tb.count(ot) * CR_COUNT;
			if(count(ot) <= 2) ans += WIN_SCORE;
			if(count(c) <= 2) ans -= WIN_SCORE;
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
			if(count(c) <= 3) {
				// throw "incompleteexception";

				repo(&i,l) repo(&j,e) repo(&k,r) {
					int x = i.fs;
					int y = i.sd;
					int nx = j.fs;
					int ny = j.sd;
					int dx = k.fs;
					int dy = k.sd;

					vc<int> now = {c,x,y,nx,ny,ot,dx,dy};
					if(tb.valid(now,p)) {
						auto tmp = ck(box_E24124723(f,c,ot,p).move(now),ot,c,d - 1,p);
						if(tmp == make_pair(0,0)) continue;
						long double found = tmp.first / tmp.second;
						if(mark.find(found) == mark.end()) mark.insert({found,tmp});
						else mark.find(found)->second = mark.find(found)->second + tmp;
					}
				}
			}

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
		pair<int,int> ans;
		int mmax = prev(mark.end())->first;
		for(auto i = prev(mark.end());abs(i->first - mmax) <= ALLOW_GAP;i = prev(i)) {
			// debug(i->first);
			ans = ans + i->second;
			if(i == mark.begin()) break;
		}
		// debug(mark.begin()->first);
		return {-ans.first,-ans.second};
	}

	bool double_corner(int x,int y,int c) {
		assert(inside(x,y));
		if(f.att(x,y) != c) return false;

		bool ans = 0;
		re(i,4) {
			re(j,1,3) {
				int nx = x + (xx[i] * dd[y] * j);
				int ny = y + (yy[i] * dd[x] * j);

				if(!inside(nx,ny) || f.att(nx,ny) != c) break;
				if(j == 2 && ans) return true;
				if(j == 2) ans = 1;
			}
		}
		return false;
	}

	vc<int> check() {
		// debug(p);
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

		if(ans.empty()) return fool(p);

		long double mmax = -INFINITY;
		vc<vc<int>>aans;
		repo(&i,ans) {
			auto tmp = (p == 1 ? ck(i.sd,ot,c,DEEP_P1,p) : ck(i.sd,ot,c,DEEP_P2,p));
			m.insert({i.fs,-tmp.first * 1.0 / tmp.second});
		}
		repo(&j,m) mmax = max(mmax,j.sd);
		repo(&k,m) if(k.second == mmax) aans.push_back(k.first);
		if(aans.size() > AUTO_GAP && p == 1) return autoplace(p);

		if(ALLOW_RANDOM) random_shuffle(all(aans));
		return aans.back();
	}

	vc<int>parseout(vc<int>f) {
		assert(f.size() == 8);
		if(f[6] == R && f[7] == R) f[6]++,f[7]++;
		return f;
	}
};

int t_E24124723 = 0;
vector<int> Algorithm(vector<vector<int>>&f,int c,int ot,int p) {
	srand(RAND_SEED + t_E24124723++);
	auto now = box_E24124723(f,c,ot,p);
	auto ans = now.check();
	f = now.move(ans);	
	return now.parseout(ans);
}

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

    
// }