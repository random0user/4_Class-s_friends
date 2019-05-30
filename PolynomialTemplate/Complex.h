#pragma once
#include <iostream>


class Complex
{
private:
	double re;
	double im;
public:
	Complex(); //����������� �� ���������
	Complex(double x, double y = 0);//����������� ��� ������������� � ���� � ������� �������
	~Complex();
	void AssignRe();
	void AssignIm();
	double ReturnRe();
	double ReturnIm();
	

	//������ ������������� �������� � ��������-������ ������������� ��������
	Complex& operator = (double d);
	Complex operator + (const Complex& B); //�������� C+C
	Complex operator + (double fl); //�������� � ������ C+f
	friend Complex operator + (double fl,const Complex& B); //�������� ����� � ����������� f+C
	Complex operator - (const Complex& B); //��������� C-C
	Complex operator - (double fl); //��������� ����� C-f
	friend Complex operator - (double fl,const Complex& B); //��������� �� ����� float ������������ f-C
	Complex operator * (const Complex& B); //���������
	Complex operator * (double fl); //�������� � �� f
	friend Complex operator * (double fl,const Complex& B); //��������� f*C
	Complex operator / (double fl); //������� �� float C/f
	friend Complex operator / (double fl, const Complex& B); //������� f/C
	Complex operator / (const Complex& B); // ������� �/�
	Complex operator ^ (double fl); //���������� � �������
	friend std::ostream & operator << (std::ostream & is, const Complex & c); //���������� <<	
	Complex& operator += (Complex B); //+=
	Complex& operator -= (Complex B); //-=
	bool operator == (Complex B); // ==
	Complex operator - () const; // -
	
};

