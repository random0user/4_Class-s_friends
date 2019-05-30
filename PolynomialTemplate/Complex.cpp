#include "stdafx.h"
#include "Complex.h"


Complex::Complex() //����������� ������
{
	re = 0;
	im = 0;
}

Complex::Complex(double x, double y) //����������� �2
{
	re = x;
	im = y;
}

Complex::~Complex() //����������
{

}


//===================������ Complex=========================//

void Complex::AssignRe()//����������� re � ����������� ��� �������
{
	std::cout << "Enter Re: " << std::endl;
	std::cin >> re;
}

void Complex::AssignIm()
{
	std::cout << "Enter Im: " << std::endl;
	std::cin >> im;
}

double Complex::ReturnRe() //���������� re
{
	return re;
}

double Complex::ReturnIm() //���������� im
{
	return im;
}



//==========================����������=======================//

Complex Complex::operator + (const Complex& B)
{
	//�������� ����������� �����
	
	return Complex(re + B.re, im + B.im);
}

Complex Complex::operator - (const Complex& B)
{
	//��������� �����������
	return Complex(re - B.re, im - B.im);
}

Complex Complex::operator + (double fl)
{
	//�������� ������������ � ������������
	return Complex(re + fl, im);
}

Complex Complex::operator - (double fl)
{
	//��������� ���. �����
	return Complex(re - fl, im);
}

Complex Complex::operator * (const Complex& B)
{
	//��������� ����� �� �����.
	return Complex(re*B.re - im*B.im, re*B.im + im*B.re);
}

Complex operator + (double fl,const Complex& B)
{
	//�������� �������. � �����
	return Complex(fl + B.re, B.im);
}

Complex operator - (double fl,const Complex& B)
{
	//��������� �� ���. ������������
	return Complex(fl - B.re, 0 - B.im);
}

Complex Complex::operator / (double fl)
{
	//��������� ����� �� ���.
	if (fl != 0)
		return Complex(re / fl, im / fl);
	//else
		//return;
}

Complex Complex::operator*(double fl)
{
	//��������� ������������ �� �����
	return Complex(re*fl, im*fl); 
}

Complex operator/(double fl,const Complex& B)
{
	//������� f/C
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
	//���������� � �������
	/*Complex RESULT = *this;
	for (int i = 1; i < n; i++)
	{
		RESULT = RESULT*RESULT;
	}
	return RESULT;*/	//��� ������ ��������� ������ ��������� ����� � ����������� �������

	//����� ������� ������, ���� �������� � ����� ������������ ��������
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
