#include<bits/stdc++.h>
using namespace std;
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
		n(0), m(0), f(nullptr) {ct++;};

	template<typename T>	
	matrix<T>::matrix(int a,int b) {
		ct++;
		n = a;
		m = b;
		this->f = new T*[n];
		re(i,n) this->f[i] = new T[m];
		re(i,n) re(j,m) f[i][j] = T(0);
	}

	template<typename T>	
	matrix<T>::matrix(const matrix &a) {
		ct++;
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
		ct--;
		re(i,n) delete[](f[i]);
		delete[] f;
		// delete &f;
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
	matrix<T> matrix<T>::operator+(int a) {
		matrix now(n,m);
		re(i,n) re(j,m) now.set(i,j,get(i,j) + a);
		return now;
	}

	template<typename T>	
	matrix<T> matrix<T>::operator+=(matrix a) {
		assert(n == a.get_x() && m == a.get_y());
		matrix now(*this + a);
		return *this = now;
	}
	
	template<typename T>	
	matrix<T> matrix<T>::operator+=(int a) {
		matrix now(*this + a);
		return *this = now;
	}
	
	template<typename T>	
	matrix<T> matrix<T>::operator++(int x = 0) {
		matrix now(*this + 1);
		return *this = now;
	}

	template<typename T>	
	matrix<T> matrix<T>::operator()() {
		matrix now(this->trans());
		return *this = now;
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
	istream& operator>>(istream& in,matrix<T> &x) {
		re(i,x.get_x()) {re(j,x.get_y()) in>>x.f[i][j];}
		return in;
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
	inline bool matrix<T>::operator==(matrix<T> a) {
		if(n != a.n || m != a.m) return false;
		re(i,n) re(j,m) if(f[i][j] != a.get(i,j)) return 0;
		return 1;
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

	template<typename T>
	inline int matrix<T>::count() {
		return ct;
	}
// };
	template<typename T>
	int matrix<T>::ct = 0;

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