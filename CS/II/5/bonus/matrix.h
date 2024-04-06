// #include<iostream>
using namespace std;

#ifndef MATRIX_H
#define MATRIX_H


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
	// friend ostream& operator<<(ostream& out,matrix<T> x);
	// friend bool operator!(matrix &a);
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


#endif // !1