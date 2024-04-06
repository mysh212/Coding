// #include<iostream>
using namespace std;

#ifndef MATRIX_H
#define MATRIX_H


template<typename T>
class matrix{
	private:
	T ** f;
	int n,m;
	static int ct;

	public:
	matrix();
	matrix(int a,int b);
	matrix(const matrix &a);
	matrix(int n,int m,T * f,int l);
	~matrix();
	inline void set(int a,int b,T x);
	inline void set(int a,int b);
	inline T get(int a,int b);
	inline int get_x();
	inline int get_y();
	template<typename R>
	friend ostream& operator<<(ostream& out,matrix<R> x);
	template<typename R>
	friend istream& operator>>(istream& out,matrix<R> &x);
	// friend bool operator!(matrix &a);
	matrix<T> operator+(matrix a);
	matrix<T> operator+(int a);
	matrix<T> operator+=(matrix a);
	matrix<T> operator+=(int a);
	matrix<T> operator++(int x = 0);
	matrix<T> operator()();
	matrix<T> operator*(matrix a);
	matrix<T> operator=(matrix a);
	matrix<T> operator^(int x);
	matrix<T> trans();
	matrix<T> add(matrix a);
	matrix<T> multiply(matrix a);
	inline bool operator==(matrix a);
	inline bool empty();
	inline void print();
	static inline int count();
};


#endif // !1