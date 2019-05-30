#pragma once
#include <iostream>


class Complex
{
private:
	double re;
	double im;
public:
	Complex(); //Конструктор по умолчанию
	Complex(double x, double y = 0);//Конструктор для инициализации в коде в круглых скобках
	~Complex();
	void AssignRe();
	void AssignIm();
	double ReturnRe();
	double ReturnIm();
	

	//Методы перегруженных операций и фунцкции-друзья перегруженных операций
	Complex& operator = (double d);
	Complex operator + (const Complex& B); //Сложение C+C
	Complex operator + (double fl); //Сложение с числом C+f
	friend Complex operator + (double fl,const Complex& B); //Сложение ЧИСЛА с комплексным f+C
	Complex operator - (const Complex& B); //Вычитание C-C
	Complex operator - (double fl); //Вычитание числа C-f
	friend Complex operator - (double fl,const Complex& B); //Вычитание из числа float комплексного f-C
	Complex operator * (const Complex& B); //Умножение
	Complex operator * (double fl); //Умножить С на f
	friend Complex operator * (double fl,const Complex& B); //Умножение f*C
	Complex operator / (double fl); //Деление на float C/f
	friend Complex operator / (double fl, const Complex& B); //Деление f/C
	Complex operator / (const Complex& B); // Деление С/С
	Complex operator ^ (double fl); //Возведение в степень
	friend std::ostream & operator << (std::ostream & is, const Complex & c); //Перегрузка <<	
	Complex& operator += (Complex B); //+=
	Complex& operator -= (Complex B); //-=
	bool operator == (Complex B); // ==
	Complex operator - () const; // -
	
};

