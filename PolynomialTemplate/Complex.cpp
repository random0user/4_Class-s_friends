#include "stdafx.h"
#include "Complex.h"


Complex::Complex() //Конструктор класса
{
	re = 0;
	im = 0;
}

Complex::Complex(double x, double y) //Конструктор №2
{
	re = x;
	im = y;
}

Complex::~Complex() //Деструктор
{

}


//===================Методы Complex=========================//

void Complex::AssignRe()//Запрашивает re и присваивает его объекту
{
	std::cout << "Enter Re: " << std::endl;
	std::cin >> re;
}

void Complex::AssignIm()
{
	std::cout << "Enter Im: " << std::endl;
	std::cin >> im;
}

double Complex::ReturnRe() //Возвращает re
{
	return re;
}

double Complex::ReturnIm() //Возвращает im
{
	return im;
}



//==========================Перегрузки=======================//

Complex Complex::operator + (const Complex& B)
{
	//Сложение комплексных чисел
	
	return Complex(re + B.re, im + B.im);
}

Complex Complex::operator - (const Complex& B)
{
	//Вычитание комплексных
	return Complex(re - B.re, im - B.im);
}

Complex Complex::operator + (double fl)
{
	//Сложение комплексного с вещественным
	return Complex(re + fl, im);
}

Complex Complex::operator - (double fl)
{
	//Вычитание вещ. числа
	return Complex(re - fl, im);
}

Complex Complex::operator * (const Complex& B)
{
	//Умножение компл на компл.
	return Complex(re*B.re - im*B.im, re*B.im + im*B.re);
}

Complex operator + (double fl,const Complex& B)
{
	//Сложение веществ. и компл
	return Complex(fl + B.re, B.im);
}

Complex operator - (double fl,const Complex& B)
{
	//Вычитание из вещ. комплексного
	return Complex(fl - B.re, 0 - B.im);
}

Complex Complex::operator / (double fl)
{
	//Разделить Компл на вещ.
	if (fl != 0)
		return Complex(re / fl, im / fl);
	//else
		//return;
}

Complex Complex::operator*(double fl)
{
	//Умножение комплексного на флоат
	return Complex(re*fl, im*fl); 
}

Complex operator/(double fl,const Complex& B)
{
	//Деление f/C
	double divider = B.re*B.re + B.im*B.im;
	if (divider != 0)
		return Complex((fl*B.re) / divider, (fl*B.im) / divider);
	//else
		//return;
}

Complex Complex::operator / (const Complex& B)
{
	//Division C/C
	double divider = B.re*B.re + B.im*B.im;
	if (divider != 0)
		return Complex((re*B.re + im*B.im) / divider, (im*B.re - re*B.im) / divider);
	//else
		//return;
}

Complex operator*(double fl, const Complex& B)
{
	//Multiply f*C
	return Complex(fl * B.re, fl*B.im);
}

Complex Complex::operator ^ (double n)
{
	//Возвдеение в степень
	/*Complex RESULT = *this;
	for (int i = 1; i < n; i++)
	{
		RESULT = RESULT*RESULT;
	}
	return RESULT;*/	//Эта версия позволяет только возводить число в натуральную степень

	//Более сложная версия, зато работает с любой вещественной степенью
	double module = sqrt(re*re + im*im);
	double phi = acos(re / module);
	module = pow(module, n);
	return Complex(cos(phi*n)*module, sin(phi*n)*module);
}

std::ostream& operator<<(std::ostream& os, const Complex &B)
{
	os << B.re;
	if (B.im >= 0)
		os << "+";
	os << B.im << "i";
	return os;
}

Complex& Complex::operator=(double d)
{
	re = d; im = 0;
	return *this;
}

Complex& Complex::operator += (Complex B)
{
	re += B.re;
	im += B.im;
	return *this;
}

Complex& Complex::operator -= (Complex B)
{
	re -= B.re;
	im -= B.im;
	return *this;
}

bool Complex::operator == (Complex B)
{
	if (re == B.re && im == B.im)
		return true;
	else
		return false;
}

Complex Complex::operator-() const
{
	return Complex(-re, -im);
}
