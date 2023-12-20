// Author : ysh
// 2023/12/15 Fri 23:26:30
#include<bits/stdc++.h>
#define att(i,j) at(i).at(j)
#define aat(i) i.first,i.second
using namespace std;
#include<slow>

#ifndef LOCAL
#undef assert
#define assert(...)
#endif

// upload:
// 1. pre-compile
// 2. include<vector,iostream,random,time.h>
// 3.pray

// action: [my_color, original_x, original_y, dest_x, dest_y, your_color, remove_x, remove_y]
/*

	vector<vector<int>> new_board =
    {
	    { 0,-1,-1, 0,-1,-1, 0},
	    {-1, 0,-1, 0,-1, 0,-1},
	    {-1,-1, 0, 0, 0,-1,-1},
	    { 0, 0, 0,-1, 0, 0, 0},
	    {-1,-1, 0, 0, 0,-1,-1},
	    {-1, 0,-1, 0,-1, 0,-1},
	    { 0,-1,-1, 0,-1,-1, 0}
    };

*/
vector<int> Algorithm(vector<vector<int>>&b, int my_color, int your_color, int phase) {
	class box_E24124723{
		public:
		const int xx[8] = {-1,0,1,0,1,-1,1,-1};
		const int yy[8] = {0,1,0,-1,1,1,-1,-1};
		const int dd[7] = {3,2,1,1,1,2,3};

		int c = 0,ot = 0,n;
		vector<vector<int>>f;
		box_E24124723(vector<vector<int>>&v,int c,int ot):
			f(v), c(c), ot(ot), n(v.size()) {};
		
		#define R 7
		#define got(i) (3 - i)
		#define inside(i,j) (i >= 0 && i <= R - 1 && j >= 0 && j <= R - 1)

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

		inline int anyline(int c) {
			re(i,R) re(j,R) {
				if(f.att(i,j) != c) continue;
				re(k,4) {
					re(l,1,3) {
						int nx = i + (xx[k] * dd[j] * l);
						int ny = j + (yy[k] * dd[i] * l);
						if(!inside(nx,ny)) break;
						if(f.att(nx,ny) != c) break;
						if(l == 2) return 1;
					}
				}
			}
			return 0;
		}

		inline bool anylone(int c) {
			re(i,R) re(j,R) if(f.att(i,j) == c && !line(i,j)) return 1;
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

		vc<vc<int>> move(vc<int>v) {
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

		bool canremove(pair<int,int>a,pair<int,int>b,int c,int op) {
			assert(inside(a.first,a.second) && inside(b.first,b.second));
			bool ok = false;
			if(a == b) {
				assert(f.att(a.first,a.second) == 0);

				f.att(a.first,a.second) = c;
				if(line(aat(a))) ok = true;
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

		inline bool corner(int x,int y,int c) {
			assert(inside(x,y));
			if(f.att(x,y) != 0) return false;

			int ans = 0;
			re(i,4) {
				bool now = false;
				re(j,1,3) {
					int nx = x + (xx[i] * dd[y] * j);
					int ny = y + (yy[i] * dd[x] * j);

					if(!inside(nx,ny)) break;
					if(!(f.att(nx,ny) == 0 || f.att(nx,ny) == c)) break;
					if(f.att(nx,ny) == c) now = true;

					if(j == 2 && now) ans++;
				}
			}
			if(ans >= 2) return true;
			return false;
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

		vector<int> check(int now) {
			if(now == 1) {
				re(i,R) re(j,R) {
					if(beline(i,j,ot) != -1) {
						pair<int,int> ans({R,R});
						if(canremove({i,j},{i,j},c,ot)) ans = getremove(ot);
						return {c,i,j,i,j,ot,ans.first,ans.second};
					}
				}
				re(i,R) re(j,R) {
					if(beline(i,j,c) != -1) {
						pair<int,int> ans({R,R});
						ans = getremove(ot);
						return {c,i,j,i,j,ot,ans.first,ans.second};
					}
				}
				re(i,R) re(j,R) if(corner(i,j,c)) {
					pair<int,int> ans({R,R});
					if(canremove({i,j},{i,j},c,ot)) ans = getremove(ot);
					return {c,i,j,i,j,ot,ans.first,ans.second};
				}
				return autoplace(now);
			}
			if(now == 2) {
				re(i,R) re(j,R) if(strictline(i,j,ot,c) != -1) {
					int ans = strictline(i,j,ot,c);
					pair<int,int> tmp({R,R});
					if(canremove({i + (xx[ans] * dd[j]),j + (yy[ans] * dd[i])},{i,j},c,ot)) tmp = getremove(ot);
					return {c,i + (xx[ans] * dd[j]),j + (yy[ans] * dd[i]),i,j,ot,tmp.first,tmp.second};
				}
				re(i,R) re(j,R) if(strictline(i,j,c) != -1) {
					int ans = strictline(i,j,c);
					debug(i,j,c);
					debug(beline(i,j,c));
					debug(ans);
					pair<int,int> tmp({R,R});
					tmp = getremove(ot);
					return {c,i + (xx[ans] * dd[j]),j + (yy[ans] * dd[i]),i,j,ot,tmp.first,tmp.second};
				}
				if(count(c) > count(ot)) return fool(now);
				else return rnd(now);
			}
			return rnd(now);
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
			return {c,0,0,0,0,ot,8,8};
			assert(0);
		}

		vc<int>rnd(int p) {
			assert(p == 1 || p == 2);
			int t = 49 * 49;
			if(p == 1) while(t--) {
				int i,j,k,l;
				i = rand() % R;j = rand() % R;
				k = rand() % R;k = rand() % R;
				if(valid({c,i,j,i,j,ot,k,l},p)) return {c,i,j,i,j,ot,k,l};
				if(valid({c,i,j,i,j,ot,R,R},p)) return {c,i,j,i,j,ot,R,R};
			}
			if(p == 2) while(t--) {
				int i,j,k,l,m,n;
				i = rand() % R;j = rand() % R;
				k = rand() % R;k = rand() % R;
				m = rand() % R;n = rand() % R;
				if(valid({c,i,j,k,l,ot,m,n},p)) return {c,i,j,k,l,ot,m,n};
				if(valid({c,i,j,k,l,ot,R,R},p)) return {c,i,j,k,l,ot,R,R};
			}
			return fool(p);
			assert(0);
		}

		int exp(int d,int p) {
			assert(d >= 0);
			if(d == 0) return this->score(p);
			if(p == 1 && (count(c) == 9 || count(ot) == 9)) return this->score(p);

			
			int ans = 0;
			vc<pair<int,int>>l,r,e;
			re(i,R) re(j,R) {
				if(f.att(i,j) == c) l.push_back({i,j});
				if(f.att(i,j) == ot) r.push_back({i,j});
				if(f.att(i,j) == 0) e.push_back({i,j});
			}

			if(p == 1) {
				repo(&i,e) {
					int x = i.first;
					int y = i.second;

					function<void(int,int,int,int)> add = [&] (int x,int y,int dx,int dy) {
						vector<int>now({c,x,y,x,y,ot,dx,dy});
						if(!valid(now,p)) return;
						auto tmp = move(now);
						ans = ans - box_E24124723(tmp,ot,c).exp(d - 1,p);
						return;
					};

					if(canremove({x,y},{x,y},c,ot)) repo(&j,r) add(x,y,j.first,j.second);
					else add(x,y,R,R);
				}
			}
			if(p == 2) {
				repo(&i,l) re(k,4) {
					int x = i.first;
					int y = i.second;

					int nx = x + (xx[k] * dd[y]);
					int ny = y + (yy[k] * dd[x]);

					if(!inside(nx,ny)) continue;
					if(f.att(nx,ny) != 0) continue;

					
					function<void(int,int,int,int,int,int)> add = [&] (int x,int y,int nx,int ny,int dx,int dy) {
						if(!valid({c,x,y,nx,ny,ot,dx,dy},p)) return;
						vector<int>now({c,x,y,nx,ny,ot,dx,dy});
						auto tmp = move(now);
						ans = ans - box_E24124723(tmp,ot,c).exp(d - 1,p);
						return;
					};

					if(canremove({x,y},{nx,ny},c,ot)) repo(&j,r) add(x,y,nx,ny,j.first,j.second);
					else add(x,y,nx,ny,R,R);
				}
			}
			// debug(ans);
			return ans;
		}

		vector<int> ck(int p) {
			vc<pair<int,int>>l,r,e;
			re(i,R) re(j,R) {
				if(f.att(i,j) == c) l.push_back({i,j});
				if(f.att(i,j) == ot) r.push_back({i,j});
				if(f.att(i,j) == 0) e.push_back({i,j});
			}
			// debug(l,r,e);

			vc<pair<vector<int>,box_E24124723>> nt;
			if(p == 1) {
				r.push_back({R,R});
				repo(&i,e) {
					repo(&j,r) {
						auto now = vector<int>({c,i.first,i.second,i.first,i.second,ot,j.first,j.second});
						if(!valid(now,p)) continue;
						auto tmp = move(now);
						nt.push_back({now,box_E24124723(tmp,ot,c)});
					}
				}
				if(nt.empty()) return autoplace(p);
			}
			if(p == 2) {
				repo(&i,l) re(j,4) {
					int nx = i.first + (xx[j] * dd[i.second]);
					int ny = i.second + (yy[j] * dd[i.first]);

					function<void(int,int,int,int,int,int)> add = [&] (int x,int y,int nx,int ny,int dx,int dy) {
						if(!valid({c,x,y,nx,ny,ot,dx,dy},p)) return;
						vector<int>now({c,x,y,nx,ny,ot,dx,dy});
						auto tmp = move(now);
						nt.push_back({now,box_E24124723(tmp,ot,c)});
						return;
					};

					if(!inside(nx,ny)) continue;
					if(f.att(nx,ny) != 0) continue;
					if(canremove({i.first,i.second},{nx,ny},c,ot)) repo(&k,e) add(i.first,i.second,nx,ny,k.first,k.second);
					else add(i.first,i.second,nx,ny,R,R);
				}
				if(nt.empty()) return rnd(p);
			}
			// debug(nt.size());
			// if(c == 1) outl(nt.size());
			return max_element(all(nt),[&](pair<vector<int>,box_E24124723> a,pair<vector<int>,box_E24124723> b) {
				return a.second.exp(3,p) > b.second.exp(3,p);
			})->first;
		}

		int score(int p) {
			int ans = 0;
			// re(i,R) {
			// 	re(j,R) {
			// 		if(f.att(i,j) == -1) out("  ");
			// 		else out(f.att(i,j)),out(" ");
			// 	}
			// 	nl;
			// }
			// ans = (count(c) - count(ot)) << 3;
			re(i,R) re(j,R) {
				if(line(i,j)) {
					if(f.att(i,j) == c) ans += 3;
					else ans -= 3;
				}
				// if(strictline(i,j,c) != -1) ans += 2;
				// if(strictline(i,j,ot) != -1) ans -= 2;
				// if(p == 1) {
				// 	if(beline(i,j,c) != -1) ans += 1;
				// 	if(beline(i,j,ot) != -1) ans -= 1;
				// 	if(corner(i,j,ot)) ans -= 2;
				// 	if(corner(i,j,c)) ans += 2;
				// }
			}
			// outl(ans);nl;
			return ans;
		}

		box_E24124723 operator=(box_E24124723 &a) {
			f = a.f;
			c = a.c;
			ot = a.ot;
			n = a.n;
			return *this;
		}

		int operator() (int p) {
			return score(p);
		}

		vc<int>parsein(vc<int>f) {
			assert(f.size() == 8);
			re(i,1,5) f[i]--;
			re(j,6,8) f[j]--;
			return f;
		}

		vc<int>parseout(vc<int>f) {
			assert(f.size() == 8);
			if(f[6] == R && f[7] == R) f[6]++,f[7]++;
			return f;
		}

		#undef got
	};

	// {
	// 	vc<vc<int>>tmp({
	// 		{ 0,-1,-1, 0,-1,-1, 0},
	// 		{-1, 1,-1, 0,-1, 0,-1},
	// 		{-1,-1, 0, 1, 0,-1,-1},
	// 		{ 0, 0, 0,-1, 1, 1, 0},
	// 		{-1,-1, 0, 0, 0,-1,-1},
	// 		{-1, 0,-1, 0,-1, 0,-1},
	// 		{ 0,-1,-1, 0,-1,-1, 0}
	// 	});
	// 	box_E24124723 op(tmp,1,2);
	// 	re(i,R) {
	// 		re(j,R) {
	// 			outs(op.corner(i,j,1));
	// 		}
	// 		outl("");
	// 	}
	// 	exit(2);
	// }

	// if(my_color == 1)
	// 		for (int i = 0; i < 7; i++) {
	// 			for (int j = 0; j < 7; j++) {
	// 					if (b[i][j] == -1)
	// 						cout << "  ";
	// 					else
	// 						cout << b[i][j] << " ";			
	// 			}
	// 			cout << endl;
	// 		}

	// srand(time(NULL));
	auto f = b;
	f.resize(10,vector<int>(10));
	re(i,R) re(j,R) f[i][j] = b[i][j];
	box_E24124723 t(f,my_color,your_color);
	// outl(t.count(my_color));outl(t.count(your_color));
	// debug(t.parseout(t.fool(phase)));

	auto tmp = t.ck(phase);
	auto ans = t.move(tmp);
	vc<vc<int>>aans(R,vc<int>(R));
	re(i,R) re(j,R) aans[i][j] = ans[i][j];
	b = aans;
	return t.parseout(tmp);
}

// int main() {
	
// 	vc<vc<int>>tmp({
// 	    { 0,-1,-1, 2,-1,-1, 0},
// 	    {-1, 0,-1, 1,-1, 0,-1},
// 	    {-1,-1, 1, 0, 1,-1,-1},
// 	    { 0, 0, 0,-1, 0, 0, 2},
// 	    {-1,-1, 0, 0, 0,-1,-1},
// 	    {-1, 0,-1, 0,-1, 0,-1},
// 	    { 0,-1,-1, 0,-1,-1, 2}
//     });

// 	debug(Algorithm(tmp,1,2,2));

// 	// vc<int>p(8);
// 	// box_E24124723 f = box_E24124723(tmp,1,2);
// 	// while(1) {
// 	// 	cin>>p;
// 	// 	f.f = f.move(f.parsein(p));
// 	// 	repo(&i,f.f) outl(i);
// 	// }
// }