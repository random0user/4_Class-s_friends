//Лабараторная с шаблоном класса полинома.
//Задача - научить полином работать с комплексными коэффициентами.
//	1) Как это будет выглядеть?
//		Polynomial<ТИПКОЭФИЦИЕНТА> ИМЯОБЪЕКТА
//	2)Это значит, что в классе будет только один определитель типа.




#include "stdafx.h"
#include "Complex.h"
#include "Poly_temlate_header.h"

using namespace std;


int main()
{
	/*Complex A(1, 2); Complex B(2, 5); Complex C(5, -1);

	Complex FFF[] = { A,B,C };

	Complex III[] = { Complex(2,14), Complex(1,2),  Complex(0,-1),  Complex(4,2) };

	Polynomial<Complex> R(FFF, 3);

	Polynomial<Complex> D(III, 4);
	//cout << R.Calculate(Complex(14)) << endl;
	//cout << R.Calculate(14.01) << endl;
	//Polynomial<Complex> K(R);
	//const Polynomial<Complex>& T1 = R;
	//R = K;
	//K = R;
	//K.Show(); cout << std::endl;
	R.Show();cout << endl;
	D.Show(); cout << endl;
	double d[] = { 1,4,8,8 };
	Polynomial<double> DBL(d, 4);

	int i[] = { 2,2,8,0 };
	Polynomial<int> INT(i, 4);
	Polynomial<int> INT2(i, 4);
	(INT / INT2).Show();

	Polynomial<int>(i, -10);


	//(1488.0 - R).Show(); cout << endl;

	cout << endl;
	//(INT + DBL).Show();*/
	

	double arr1[] = {5,6,1,10,23,4,0,1};
	double arr2[] = { -1,-2,-3,-4,-5,-6,-7,-8 };
	double arr3[] = { 1,2,3,4,5,6,7,8,9,10 };
	double arr4[] = { 2,5,10,7,3 };
	Polynomial<double> A(arr1, 8);
	Polynomial<double> B(arr2, 8);
	Polynomial<double> C(arr3, 10);
	Polynomial<double> D(arr4, 5);
	A.Show(); cout << endl;
	B.Show(); cout << endl;
	C.Show(); cout << endl;
	D.Show(); cout << endl;
	cout << endl << endl << endl;

	double arr5[] = { 1,5,0,3 };
	Polynomial<double> E(arr5, 4);
	cout << A << endl << D << endl;
	cout << A / D << endl;

	double a[] = { 1,2, 4 };
	double b[] = { 1, 2 };
	Polynomial<double> F(a, 3), K(b, 2);
	cout << K.Calculate(Complex(1, 1));
	cout << K.Calculate(int(23));
	//cout << F/K;
    return 0;

}

