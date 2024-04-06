#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;

#define DEBUG
#include "matrix.hpp"
#include "complex.hpp"

#define displayData print
#define setData set
#define getData get
#define transpose trans
#define getRow get_x
#define getCol get_y

using Matrix = matrix<Complex>;


int main()
{
	Matrix m1;	
	Complex cs[9] ;
	Matrix m2(3, 3, cs, 9);
	Matrix m3(m2);

	cout << "\nMatrix m1 is : \n";
	m1.displayData();
	cout << "\nMatrix m2 is : \n";
	m2.displayData();
	cout << "\nMatrix m3 is : \n";
	m3.displayData();


	int r = 0, c = 2;
	Complex c1 = Complex(3, 4);
	m3.setData(r, c, c1);
	cout << "\n( " << r << "," << c << " ) of Matrix m3 is :  ";
	m3.getData(r, c).print();
	cout << "\nMatrix m3 after setup is : \n";
	m3.displayData();
	cout << "\ntranspose of Matrix m3 is :  \n";
	m3.transpose().displayData();


	Matrix m4(3, 3);
	cout << "\nrow of Matrix m4 is :  " << m4.getRow();
	cout << "\ncol of Matrix m4 is :  " << m4.getCol();


	cout << "\n\n m2 + m3 is : \n";
	m2.add(m3).displayData();

	cout << "\n m2 * (m3)^T is : \n";
	m2.multiply(m3.transpose()).displayData();

	return 0;
}

