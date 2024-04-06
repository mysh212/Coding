// Author : ysh 
// Pre-compiled : 2024/03/27 Wed 18:53:31 
 
// # 1 "ccb.cpp"
// # 1 "<built-in>"
// # 1 "<command-line>"
// # 1 "ccb.cpp"

// # 1 "matrix.h" 1

using namespace std;





template<typename T>
class matrix{
 private:
 T ** f;
 int n,m;

 public:
 matrix();
 matrix(int a,int b);
 matrix(const matrix &a);
 matrix(int n,int m,T * f,int l);
 ~matrix();
 inline void set(int a,int b,T x);
 inline T get(int a,int b);
 inline int get_x();
 inline int get_y();


 matrix<T> operator+(matrix a);
 matrix<T> operator*(matrix a);
 matrix<T> operator=(matrix a);
 matrix<T> operator^(int x);
 matrix<T> trans();
 matrix<T> add(matrix a);
 matrix<T> multiply(matrix a);
 inline bool empty();
 inline void print();
};
template<class T>
istream& operator>>(istream& fin,vector<T>&f) {
    for(auto &&i : f) fin>>i;
    return fin;
}
template<class T,class R>
istream& operator>>(istream& fin,pair<T,R>&x) {
    fin>>x.first>>x.second;
    return fin;
}
template<class T>
ostream& operator<<(ostream& fout,vector<T>&f) {
    for(auto &i : f) fout<<i<<" ";
    return fout;
}
template<class T,class R>
ostream& operator<<(ostream& fout,pair<T,R>&x) {
    fout<<x.first<<" "<<x.second;
    return fout;
}
 template<typename T>
 matrix<T>::matrix():
  n(0), m(0), f(nullptr) {};

 template<typename T>
 matrix<T>::matrix(int a,int b) {
  n = a;
  m = b;
  this->f = new T*[n];
  for(int i = 0;i<n;i++) this->f[i] = new T[m];
  for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) f[i][j] = T(0);
 }

 template<typename T>
 matrix<T>::matrix(const matrix &a) {
  n = a.n;
  m = a.m;
  this->f = new T*[n];
  for(int i = 0;i<n;i++) this->f[i] = new T[m];
  for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) f[i][j] = a.f[i][j];
  return;
 }

 template<typename T>
 matrix<T>::matrix(int n,int m,T * f,int l):
 matrix(n,m) {
  assert(n * m == l);
  int t = 0;
  for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) this->f[i][j] = f[t++];
 }

 template<typename T>
 matrix<T>::~matrix() {
  for(int i = 0;i<n;i++) delete[](f[i]);
  delete[] f;
//   delete &f;
  return;
 }

 template<typename T>
 inline void matrix<T>::set(int a,int b,T x) {
  assert(0 <= a && a < n && 0 <= b && b < m);
  f[a][b] = x;
  return;
 }

 template<typename T>
 inline T matrix<T>::get(int a,int b) {
  assert(0 <= a && a < n && 0 <= b && b < m);
  return f[a][b];
 }

 template<typename T>
 inline int matrix<T>::get_x() {
  return n;
 }

 template<typename T>
 inline int matrix<T>::get_y() {
  return m;
 }

 template<typename T>
 matrix<T> matrix<T>::operator+(matrix a) {
  assert(n == a.get_x() && m == a.get_y());
  matrix now(n,m);
  for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) now.set(i,j,get(i,j) + a.get(i,j));
  return now;
 }

 template<typename T>
 matrix<T> matrix<T>::operator*(matrix a) {
  assert(m == a.get_y());
  matrix now(m,a.get_y());

  {
   int tmp = a.get_y();
   for(int k = 0;k<m;k++) for(int i = 0;i<n;i++) for(int j = 0;j<tmp;j++) now.set(i,j,now.get(i,j) + (get(i,k) * a.get(k,j)));
  }
  return now;
 }

 template<typename T>
 matrix<T> matrix<T>::operator=(matrix a) {
  n = a.get_x();
  m = a.get_y();
  this->f = new T*[n];
  for(int i = 0;i<n;i++) this->f[i] = new T[m];
  for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) f[i][j] = a.get(i,j);
  return *this;
 }

 template<typename T>
 matrix<T> matrix<T>::operator^(int x) {
  if(x == 1) return *this;
  matrix tmp((*this) ^ (x >> 1));
  tmp = tmp * tmp;

  if(x & 1) tmp = tmp * (*this);
  return tmp;
 }

 template<typename T>
 ostream& operator<<(ostream& out,matrix<T> x) {
  for(int i = 0;i<x.get_x();i++) {for(int j = 0;j<x.get_y();j++) out<<x.get(i,j)<<" "; out<<"\n";}
  return out;
 }

 template<typename T>
 matrix<T> matrix<T>::trans() {
  matrix now(m,n);

  for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) now.set(j,i,f[i][j]);
  return now;
 }

 template<typename T>
 matrix<T> matrix<T>::add(matrix a) {
  return ((*this) + a);
 }
 template<typename T>
 matrix<T> matrix<T>::multiply(matrix a) {
  return ((*this) * a);
 }

 template<typename T>
 bool operator!(matrix<T> &a) {
  return !(a.empty());
 }

 template<typename T>
 inline bool matrix<T>::empty() {
  return (n == 0 || m == 0 || f == nullptr);
 }

 template<typename T>
 inline void matrix<T>::print() {
  for(int i = 0;i<n;i++) {for(int j = 0;j<m;j++) cout<<f[i][j]<<" "; cout<<"\n";}
  return;
 }




// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//  cout<<fixed<<setprecision(2);

//  matrix<double> f(3,3,new double[9] {1,2,3,4,5,6,7,8,9},9);
//  f.trans().print();
//  cout<<(f ^ 5);
//     return 0;
// }
/*  
// #include<bits/stdc++.h>
// using namespace std;
#include"matrix.h"
#include<slow>

// template<typename T>
// class matrix{
// 	private:
// 	T ** f;
// 	int n,m;

	// public:
	template<typename T>
	matrix<T>::matrix():
		n(0), m(0), f(nullptr) {};

	template<typename T>	
	matrix<T>::matrix(int a,int b) {
		n = a;
		m = b;
		this->f = new T*[n];
		re(i,n) this->f[i] = new T[m];
		re(i,n) re(j,m) f[i][j] = T(0);
	}

	template<typename T>	
	matrix<T>::matrix(const matrix &a) {
		n = a.n;
		m = a.m;
		this->f = new T*[n];
		re(i,n) this->f[i] = new T[m];
		re(i,n) re(j,m) f[i][j] = a.f[i][j];
		return;
	}

	template<typename T>	
	matrix<T>::matrix(int n,int m,T * f,int l):
	matrix(n,m) {
		assert(n * m == l);
		int t = 0;
		re(i,n) re(j,m) this->f[i][j] = f[t++];
	}

	template<typename T>	
	matrix<T>::~matrix() {
		re(i,n) delete[](f[i]);
		delete[] f;
		delete &f;
		return;
	}

	template<typename T>	
	inline void matrix<T>::set(int a,int b,T x) {
		assert(0 <= a && a < n && 0 <= b && b < m);
		f[a][b] = x;
		return;
	}

	template<typename T>	
	inline T matrix<T>::get(int a,int b) {
		assert(0 <= a && a < n && 0 <= b && b < m);
		return f[a][b];
	}

	template<typename T>	
	inline int matrix<T>::get_x() {
		return n;
	}

	template<typename T>	
	inline int matrix<T>::get_y() {
		return m;
	}

	template<typename T>	
	matrix<T> matrix<T>::operator+(matrix a) {
		assert(n == a.get_x() && m == a.get_y());
		matrix now(n,m);
		re(i,n) re(j,m) now.set(i,j,get(i,j) + a.get(i,j));
		return now;
	}

	template<typename T>	
	matrix<T> matrix<T>::operator*(matrix a) {
		assert(m == a.get_y());
		matrix now(m,a.get_y());

		{
			int tmp = a.get_y();
			re(k,m) re(i,n) re(j,tmp) now.set(i,j,now.get(i,j) + (get(i,k) * a.get(k,j)));
		}
		return now;
	}
	
	template<typename T>	
	matrix<T> matrix<T>::operator=(matrix a) {
		n = a.get_x();
		m = a.get_y();
		this->f = new T*[n];
		re(i,n) this->f[i] = new T[m];
		re(i,n) re(j,m) f[i][j] = a.get(i,j);
		return *this;
	}
	
	template<typename T>	
	matrix<T> matrix<T>::operator^(int x) {
		if(x == 1) return *this;
		matrix tmp((*this) ^ (x >> 1));
		tmp = tmp * tmp;
		
		if(x & 1) tmp = tmp * (*this);
		return tmp;
	}

	template<typename T>	
	ostream& operator<<(ostream& out,matrix<T> x) {
		re(i,x.get_x()) {re(j,x.get_y()) out<<x.get(i,j)<<" "; out<<"\n";}
		return out;
	}

	template<typename T>	
	matrix<T> matrix<T>::trans() {
		matrix now(m,n);

		re(i,n) re(j,m) now.set(j,i,f[i][j]);
		return now;
	}

	template<typename T>	
	matrix<T> matrix<T>::add(matrix a) {
		return ((*this) + a);
	}
	template<typename T>	
	matrix<T> matrix<T>::multiply(matrix a) {
		return ((*this) * a);
	}

	template<typename T>	
	bool operator!(matrix<T> &a) {
		return !(a.empty());
	}

	template<typename T>	
	inline bool matrix<T>::empty() {
		return (n == 0 || m == 0 || f == nullptr);
	}

	template<typename T>	
	inline void matrix<T>::print() {
		re(i,n) {re(j,m) outs(f[i][j]); nl;}
		return;
	}
// };

#ifndef DEBUG

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	cout<<fixed<<setprecision(2);

	matrix<double> f(3,3,new double[9] {1,2,3,4,5,6,7,8,9},9);
	f.trans().print();
	cout<<(f ^ 5);
    return 0;
}

#endif  
*/  
