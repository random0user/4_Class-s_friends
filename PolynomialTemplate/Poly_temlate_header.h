#pragma once


#include "Complex.h"
#include "iostream"

using namespace std;

template <typename Coef>
class Polynomial
{

private:
	Coef* coef_arr; //����� ������� �������������
	int power;
public:
	friend class Complex;

	//����������� �� ���������
	Polynomial();

	//��� ������������� ������������ ������
	template<typename T>
	Polynomial(const T& T_object);

	//����������
	~Polynomial();

	//����������� 2
	Polynomial(Coef* input, int length);

	//����������� �����������
	Polynomial(const Polynomial<Coef>& P);

	//������ ���� � ������� ����.
	Polynomial<Coef>& Normalize();


	//���������
	template<typename T>
	Coef Calculate(T x);

	//����������
	Polynomial<Coef>& operator = (const Polynomial<Coef>& B);

	//������ � i ������������
	Coef& operator[](int i);

	//������� - (���� �, ����� -�)
	Polynomial operator-() const;

	//����� �� �����
	void Show();

	//����
	void TEST();

	//�������� ���������
	Polynomial operator + (const Polynomial<Coef>& P) const;

	//��������� ���������
	Polynomial operator - (const Polynomial<Coef>& P) const;

	//�������� �������� � ����� �����
	/*template<typename T>
	Polynomial<Coef> operator + (const T& op) const;*/

	//�������� ������ ���� � ���������
	template<typename T>
	friend Polynomial<Coef> operator + (const T& op, const Polynomial<Coef>& P);

	//��������� ������ ���� �� ��������
	/*template<typename T>
	Polynomial<Coef> operator - (const T& op) const;*/

	//��������� �� ������ ���� ��������
	template<typename T>
	friend Polynomial<Coef> operator-(const T& op, const Polynomial<Coef>& P);

	//��������� ���������	A*B, ��� ��������� � �� ����������� � Polynomial<Coef> ��������
	Polynomial<Coef> operator*(const Polynomial<Coef>& P);

	//��������� ���� �� �������
	template<typename T>
	friend Polynomial<Coef> operator*(const T& op, const Polynomial<Coef>& P);


	//������� ���������, �� ��� �� ���, ���������� � �������� ������������� Polynomial(const T& type_obj)
	Polynomial<Coef> operator/ (const Polynomial<Coef>& divider) const;

	//�������� � ������ cout
	friend ostream& ::operator << (ostream& os, const Polynomial<Coef> P);

	Complex Calculate(Complex x);

	/*template<typename T2>
	Polynomial<Coef> Polynomial(const Polynomial<T2>& T2_POLY);*/
};


//=========================================����������� �������===========================================


//Test !constructor!
/*template<typename T1>
template<typename T2>
Polynomial<T1> Polynomial<T1>::Polynomial(const Polynomial<T2>& T2_POLY)
{
	return Polynomial<T1>();
}*/


//����������� �� ���������
template<typename Coef>
Polynomial<Coef>::Polynomial()
{
	power = 0; //������� �������� ����� 0, ������ ������� - ������ �����
	coef_arr = new Coef[1]; //�������� ������ ��� ������������� ������������
	coef_arr[0] = 0; //��� ����� ����. ����� 0
	//� ����� �����  P(x) = 0
}


//������������� �������� � ����. ���� Coef ����� �� ����� �
//��� � ���������� � ���� Coef
template<typename Coef>
template<typename T>
Polynomial<Coef>::Polynomial(const T& T_object)
{
	power = 0; //������� �������� ����� 0, ������ ������� - ������ �����
	coef_arr = new Coef[1];
	coef_arr[0] = Coef(T_object);//���������� � coef
}

//����������
template<typename Coef>
Polynomial<Coef>::~Polynomial()
{
	delete[] coef_arr;
}

//����������� 2
template<typename Coef>
Polynomial<Coef>::Polynomial(Coef* input_arr, int length)
{
	if (length<0)//���� ������ � ����� �������
	{
		//������� ����������� �����������
		power = 0;
		coef_arr = new Coef[1];
		coef_arr[0] = 0;
		return;
	}
	power = length - 1; //������� �������� ������ �� 1, ��� ���-�� �������������
	coef_arr = new Coef[length];//������ �� ��� ��������
	for (int i = 0; i<length; i++)
	{
		//TODO ����������� ������� ������������� ������������ ����� ��� �� ���.
		coef_arr[i] = input_arr[i];
	}
	return;
}

//����������� �����������
template<typename Coef>
Polynomial<Coef>::Polynomial(const Polynomial<Coef>& P)
{
	power = P.power; //����������� �������
	coef_arr = new Coef[power + 1]; //�������� ����� ��� ������ ����.
	for (int i = 0; i <= power; i++)
		coef_arr[i] = P.coef_arr[i]; //������������ ����.
}

//���������
template<typename Coef>
	template<typename T>
Coef Polynomial<Coef>::Calculate(T x)
{
	//����� �������
	Coef k(0); //�������� ����������� �� ������ ���������
	//��� ����� ������� ������� �������������� ���� � ������? // operator type()
	//Coef k; k = 0; ????
	for (int i = 0; i < power; i++)
	{
		k = (k + coef_arr[i])* x;
	}
	return k += coef_arr[power];
}

//��������� ��� �����������
template<typename Coef>
Complex Polynomial<Coef>::Calculate(Complex x)
{
	
	Complex k(0);
	for (int i = 0; i < power; i++)
	{
		k = (k + coef_arr[i])* x;
	}
	return k += coef_arr[power];
}



//������������ �������� �������� OPERATOR =
template<typename Coef>
Polynomial<Coef>& Polynomial<Coef>::operator = (const Polynomial<Coef>& B)
{
	if (this == &B) //���� ������������ ������ ����(2 ��������� �����)
		return *this; //������� ������ ����
	delete[] coef_arr; // ���������� ������ ��� ������ ����.
	power = B.power; 
	coef_arr = new Coef[power + 1]; //�������� ������ ��� ����.
	for (int i = 0; i <= power; i++)
		coef_arr[i] = B.coef_arr[i]; //����������� 
	return *this;//�������, ��� ����������
}

//������ � i �������� OPERATOR[]
template<typename Coef>
Coef& Polynomial<Coef>::operator[](int i)
{
	if (i >= 0 and i <= power)
		return coef_arr[i];
	else
		return 0;
} 


//����� �� �����
template<typename Coef>
void Polynomial<Coef>::Show()
{
	std::cout <<"("<< coef_arr[0] << ")x^" << power;
	for (int i = 1; i < power; i++)
	{
		//if (coef_arr[i] >= 0)
			std::cout << " +(" << coef_arr[i] << ")x^" << power-i;
		//else
			//cout << coef_arr[i];
	}
	if (power !=0)
	std::cout << " +(" << coef_arr[power] << ")";
}

//TEST
template<typename Coef>
void Polynomial<Coef>::TEST()
{
//	cout << (int(coef_arr[0]) == 0);
}

//������� - 
template<typename Coef>
Polynomial<Coef> Polynomial<Coef>::operator-() const
{
	Polynomial<Coef> Temp(*this); //�������� ���������� �����������, ������ �������� �����
	for (int i = 0; i <= power; i++)
		Temp.coef_arr[i] = -Temp.coef_arr[i];
	return Temp;
}

//�������� ���������, ��� �������� + ���	A+B //��� ���������� ������� �������������� � ���� Polynomial<Coef>
template<typename Coef>
Polynomial<Coef> Polynomial<Coef>::operator + (const Polynomial<Coef>& P) const
{
	int i = this->power; // "���������" �� ����� 1�� ����������, ������� � �����
	int j = P.power; // "���������" �� ����� 2�� ����������, ������� � �����

	Polynomial<Coef> Temp_Poly; //��� ����� ���������� �� ��������
	int counter = Temp_Poly.power = i > j ? i : j; //������� ���������� ��� �������
	delete[] Temp_Poly.coef_arr; //���������� ������, ���������� ��� 0;
	Temp_Poly.coef_arr = new Coef[Temp_Poly.power+1]; //������� ������ ��� ��� �������� ������ ��������


	while (i >= 0 && j >= 0) //������ �� ����� �� �������� ����� ����������
	{
		Temp_Poly.coef_arr[counter] = this->coef_arr[i] + P.coef_arr[j]; //������� ��������
		counter--; i--; j--;
	}

	//������ ������� ���������� �����.(�������� � 0)
	if(i>j)
		while (counter >= 0)
			Temp_Poly.coef_arr[counter--] = this->coef_arr[i--];
	else
	{
		while (counter >= 0)
			Temp_Poly.coef_arr[counter--] = P.coef_arr[j--];
	}
	Temp_Poly.Normalize();
	return Temp_Poly;
}

//��������� ���������, ��� ������� - ���	 A-B
template<typename Coef>
Polynomial<Coef> Polynomial<Coef>::operator - (const Polynomial& P) const
{
	//Polynomial<Coef> temp = -P;
	return *this + (-P);
}

//�������� �������� � ����� �����	 A+type //�� ����� ���� �� �����
/*template<typename �oef> //������ � �������
	template<typename T>
Polynomial<�oef> Polynomial<�oef>::operator + (const T& op) const
{
	//�������� T � ���� ��������
	Polynomial<�oef> Temp(op);
	return *this + Temp;
}*/

//�������� ������ ������������ ���� � ��������	type+A
template<typename Coef, typename T> 
Polynomial<Coef> operator+(const T& op, const Polynomial<Coef>& P)
{
	return P+op;
}

//��������� ������ ���� �� ��������	 A-type (A+ (-type)) //���� �� �����
/*template<typename Coef>
template<typename T>
Polynomial<Coef> Polynomial<Coef>::operator - (const T& op) const
{
	return *this + Polynomial<Coef>(-op);
}
*/

//��������� �� ������-�� ���� ��������		type-A (type + (-A))
template<typename Coef, typename T>
Polynomial<Coef> operator-(const T& op, const Polynomial<Coef>& P)
{
	return Polynomial<Coef>(op) - P;
}

//��������� ��������� A*B, � ����� ��������� �������� �� ����� �� ���, ������ ���������� � Polynomial<Coef>
template<typename Coef>
Polynomial<Coef> Polynomial<Coef>::operator*(const Polynomial<Coef>& P)
{
	int composition_power = this->power + P.power; //������� ������������
	Polynomial<Coef> Result; //������� ������������ ������
	delete [] Result.coef_arr; //���������� ������ � ���������� �������
	Result.coef_arr = new Coef[composition_power + 1]; //�������� ������ ��� ������������ �������
	Result.power = composition_power; //C������ ��������
	//��������� ������
	for (int i = 0; i <= composition_power; i++)
		Result.coef_arr[i] = 0;

	int this_power = this->power; //������� �������� ����� �� *
	int P_power = P.power;// ������� �������� ������ �� *
	for (int i = 0; i <= this_power; i++)
	{
		for (int j = 0; j <= P_power; j++)
		{
			Result.coef_arr[i+j] += this->coef_arr[i]  * P.coef_arr[j];
		}
	}
	Result.Normalize();
	return Result;
}

//��������� ������-�� ���� �� ������� 
template<typename Coef, typename T>
Polynomial<Coef> operator*(const T& op, const Polynomial<Coef>& P)
{
	return P*op;
}

//������� ���������
template<typename Coef>
Polynomial<Coef> Polynomial<Coef>::operator/ (const Polynomial<Coef>& divider) const
{
	if (this->power < divider.power) //���� ������� �������� ������, ��� ������� ����� 0.
		return Polynomial<Coef>();

	//������ ���� ������� �������, ������� ����� �������. �������� ��� �������.
	int quotient_power = this->power - divider.power; //������� ��������
	//������� ������
	Coef* mem = new Coef[quotient_power + 1];
	//�������� ������ ��������, �������� ��� ���������� ������
	Polynomial<Coef> Quotient;
	delete[] Quotient.coef_arr;
	Quotient.coef_arr = mem;
	Quotient.power = quotient_power;
	//��������� ������ mem ������.
	for (int i = 0; i <= quotient_power; i++)
		mem[i] = 0;
	
	//����� ��������, ��� ����� ����������� � ������ ��������.
	Polynomial<Coef> Dividend = *this; //����� ����������� �����������
	//����, ����� �������� ������������ ��� �������� ���� ������� ����� ���� �� �����
	for (int i = 0; i <= quotient_power; i++)
	{
		if (Dividend.power < divider.power)
			Quotient.coef_arr[i] = 0;
		else
		{
			Quotient.coef_arr[i] = Dividend.coef_arr[0] / divider.coef_arr[0];//�������� ����.
			//cout << "Quotient: " << Quotient << endl << "Exch: " << Polynomial(mem + i, quotient_power - i + 1) << endl;
			Dividend = Dividend - (Polynomial(mem + i, quotient_power - i + 1) * divider); //��������� 
			//cout << "Dividend: " << Dividend << endl;
		}
	}
	return Quotient;
}


template<typename Coef>
Polynomial<Coef>& Polynomial<Coef>::Normalize()
{
	int i = 0;
	for (; i <= power && coef_arr[i] == 0; i++);
	if (i == 0)
		return *this;
	Coef* new_coef_arr = new Coef[this->power - i+1];//�������� ������� ������ 
	for (int j = i,k=0; j <= this->power; j++, k++)
		new_coef_arr[k] = coef_arr[j];
	this->power = this->power - i;
	delete[] coef_arr;
	coef_arr = new_coef_arr;
	return *this;
}

//���������� ��� �������� ostream <<
template<typename Coef>
ostream& operator << (ostream& os, const Polynomial<Coef> P) 
{
	os << "(" << P.coef_arr[0] << ")x^" << P.power;
	for (int i = 1; i < P.power; i++)
	{
		os << " +(" << P.coef_arr[i] << ")x^" << P.power - i;
	}
	if (P.power != 0)
		os << " +(" << P.coef_arr[P.power] << ")";
	return os;
}