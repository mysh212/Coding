#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;

#define DEBUG
#include "matrix.hpp"

#define displayData print
#define setData set
#define getData get
#define transpose trans
#define getRow get_x
#define getCol get_y
#define getCount count

using Matrix = matrix<double>;

int main()
{
	Matrix m1;

	double d[9] = {1,2,3,4,5,6,7,8,9};

	Matrix m2(3,3,d,9);
	Matrix m3(m2);

	cout<<"Matrix m1 is : "<<endl;
	m1.displayData();
	cout<<"Matrix m2 is : "<<m2<<endl;
	cout<<"Matrix m3 is : "<<m3<<endl;

	if(m2==m3)
		cout<<"m2 and m3 are the same.";
	else
		cout<<"m2 and m3 are different";

	m3.setData(1,1,99);
	cout<<"m3 after setup is : "<<m3<<endl;
	if(m2==m3)
		cout<<"m2 and m3 are the same.";
	else
		cout<<"m2 and m3 are different";

	Matrix m4(3,3);
	cout<<"Please enter 9 doubles for matrix m4:"<<endl;
	cin>>m4;
	cout<<"Matrix m4 is : "<<m4<<endl;
	
	Matrix m5 = m2+m3;
	cout<<"m2+m3 is : "<<m5<<endl;
	m5 = m2 + 3;
	cout<<"m2 + 3 is : "<<m5<<endl;
	m5 += m2;
	cout<<"m2 + m2 + 3 is : "<<m5<<endl;
	m5++;
	cout<<"m2 + m2 + 4 is : "<<m5<<endl;
	m5 = m2 * m3;
	cout<<"m2 * m3 is : "<<m5<<endl;
	m5 = m4();
	cout<<"transpose of m4 is : "<<m5<<endl;

	cout<<"number of matrices now is : "<<Matrix:: getCount() <<endl;

	return 0;
}

