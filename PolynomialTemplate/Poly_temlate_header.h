#pragma once


#include "Complex.h"
#include "iostream"

using namespace std;

template <typename Coef>
class Polynomial
{

private:
	Coef* coef_arr; //Адрес массива коэффициентов
	int power;
public:
	friend class Complex;

	//Конструктор по умолчанию
	Polynomial();

	//Для инициализации единственным числом
	template<typename T>
	Polynomial(const T& T_object);

	//Деструктор
	~Polynomial();

	//Конструктор 2
	Polynomial(Coef* input, int length);

	//Конструктор копирования
	Polynomial(const Polynomial<Coef>& P);

	//Убрать нули в старших коэф.
	Polynomial<Coef>& Normalize();


	//Вычислить
	template<typename T>
	Coef Calculate(T x);

	//Присвоение
	Polynomial<Coef>& operator = (const Polynomial<Coef>& B);

	//Доступ к i коэффициенту
	Coef& operator[](int i);

	//Унарный - (было А, стало -А)
	Polynomial operator-() const;

	//Вывод на экран
	void Show();

	//Тест
	void TEST();

	//Сложение полиномов
	Polynomial operator + (const Polynomial<Coef>& P) const;

	//Вычитание полиномов
	Polynomial operator - (const Polynomial<Coef>& P) const;

	//Сложение полинома с любым типом
	/*template<typename T>
	Polynomial<Coef> operator + (const T& op) const;*/

	//Сложение любого типа с полиномом
	template<typename T>
	friend Polynomial<Coef> operator + (const T& op, const Polynomial<Coef>& P);

	//Вычитание любого типа из полинома
	/*template<typename T>
	Polynomial<Coef> operator - (const T& op) const;*/

	//Вычитание из любого типа полинома
	template<typename T>
	friend Polynomial<Coef> operator-(const T& op, const Polynomial<Coef>& P);

	//Умножение полиномов	A*B, или умножение А на приведенный к Polynomial<Coef> аргумент
	Polynomial<Coef> operator*(const Polynomial<Coef>& P);

	//Умножение типа на полином
	template<typename T>
	friend Polynomial<Coef> operator*(const T& op, const Polynomial<Coef>& P);


	//Деление полиномов, ну или на тип, приводимый к полиному конструктором Polynomial(const T& type_obj)
	Polynomial<Coef> operator/ (const Polynomial<Coef>& divider) const;

	//Передача в объект cout
	friend ostream& ::operator << (ostream& os, const Polynomial<Coef> P);

	Complex Calculate(Complex x);

	/*template<typename T2>
	Polynomial<Coef> Polynomial(const Polynomial<T2>& T2_POLY);*/
};


//=========================================Определения методов===========================================


//Test !constructor!
/*template<typename T1>
template<typename T2>
Polynomial<T1> Polynomial<T1>::Polynomial(const Polynomial<T2>& T2_POLY)
{
	return Polynomial<T1>();
}*/


//Конструктор по умолчанию
template<typename Coef>
Polynomial<Coef>::Polynomial()
{
	power = 0; //Порядок полинома равен 0, значит полином - просто число
	coef_arr = new Coef[1]; //Выделить память для единственного коэффициента
	coef_arr[0] = 0; //Тот самый коэф. равен 0
	//В итоге вышло  P(x) = 0
}


//Инициализация полинома с коэф. типа Coef каким то типом Т
//Тип Т приводится к типу Coef
template<typename Coef>
template<typename T>
Polynomial<Coef>::Polynomial(const T& T_object)
{
	power = 0; //Порядок полинома равен 0, значит полином - просто число
	coef_arr = new Coef[1];
	coef_arr[0] = Coef(T_object);//приведение к coef
}

//Деструктор
template<typename Coef>
Polynomial<Coef>::~Polynomial()
{
	delete[] coef_arr;
}

//Конструктор 2
template<typename Coef>
Polynomial<Coef>::Polynomial(Coef* input_arr, int length)
{
	if (length<0)//Если ошибка в длине массива
	{
		//Вызвать стандартный конструктор
		power = 0;
		coef_arr = new Coef[1];
		coef_arr[0] = 0;
		return;
	}
	power = length - 1; //Порядок полинома меньше на 1, чем кол-во коэффициентов
	coef_arr = new Coef[length];//Массив на все элементы
	for (int i = 0; i<length; i++)
	{
		//TODO Реализовать функцию инициализации комплексного числа чем то еще.
		coef_arr[i] = input_arr[i];
	}
	return;
}

//Конструктор копирования
template<typename Coef>
Polynomial<Coef>::Polynomial(const Polynomial<Coef>& P)
{
	power = P.power; //Присваиваем порядок
	coef_arr = new Coef[power + 1]; //Выделить место под массив коэф.
	for (int i = 0; i <= power; i++)
		coef_arr[i] = P.coef_arr[i]; //Присваивание коэф.
}

//Вычислить
template<typename Coef>
	template<typename T>
Coef Polynomial<Coef>::Calculate(T x)
{
	//Схема Горнера
	Coef k(0); //Работает конструктор от одного аргумента
	//Или лучше сделать функцию преобразования типа в объект? // operator type()
	//Coef k; k = 0; ????
	for (int i = 0; i < power; i++)
	{
		k = (k + coef_arr[i])* x;
	}
	return k += coef_arr[power];
}

//Вычислить для комплексных
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



//Присваивание полинома полиному OPERATOR =
template<typename Coef>
Polynomial<Coef>& Polynomial<Coef>::operator = (const Polynomial<Coef>& B)
{
	if (this == &B) //Если присваиваешь самому себе(2 побитовые копии)
		return *this; //Вернуть самого себя
	delete[] coef_arr; // Освободить память под массив коэф.
	power = B.power; 
	coef_arr = new Coef[power + 1]; //Выделить память под коэф.
	for (int i = 0; i <= power; i++)
		coef_arr[i] = B.coef_arr[i]; //Присваивать 
	return *this;//Вернуть, что получилось
}

//Доступ к i элементу OPERATOR[]
template<typename Coef>
Coef& Polynomial<Coef>::operator[](int i)
{
	if (i >= 0 and i <= power)
		return coef_arr[i];
	else
		return 0;
} 


//Вывод на экран
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

//Унарный - 
template<typename Coef>
Polynomial<Coef> Polynomial<Coef>::operator-() const
{
	Polynomial<Coef> Temp(*this); //Никакого побитового копирования, только реальная копия
	for (int i = 0; i <= power; i++)
		Temp.coef_arr[i] = -Temp.coef_arr[i];
	return Temp;
}

//Сложение полиномов, или полинома + тип	A+B //Тут происходит неявное преобразование к типу Polynomial<Coef>
template<typename Coef>
Polynomial<Coef> Polynomial<Coef>::operator + (const Polynomial<Coef>& P) const
{
	int i = this->power; // "указатель" на члены 1го многочлена, начиная с конца
	int j = P.power; // "указатель" на члены 2го многочлена, начиная с конца

	Polynomial<Coef> Temp_Poly; //Его будем возвращать по значению
	int counter = Temp_Poly.power = i > j ? i : j; //Счетчик показывает мах порядок
	delete[] Temp_Poly.coef_arr; //Освободить память, выделенную под 0;
	Temp_Poly.coef_arr = new Coef[Temp_Poly.power+1]; //Выделим память под все элементы нового полинома


	while (i >= 0 && j >= 0) //Покуда не дойдём до старшего члена многочлена
	{
		Temp_Poly.coef_arr[counter] = this->coef_arr[i] + P.coef_arr[j]; //Сложить почленно
		counter--; i--; j--;
	}

	//Теперь довнесём оставшиеся члены.(сложение с 0)
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

//Вычитание полиномов, или полином - тип	 A-B
template<typename Coef>
Polynomial<Coef> Polynomial<Coef>::operator - (const Polynomial& P) const
{
	//Polynomial<Coef> temp = -P;
	return *this + (-P);
}

//Сложение полинома с любым типом	 A+type //На самом деле не нужно
/*template<typename Сoef> //шаблон в шаблоне
	template<typename T>
Polynomial<Сoef> Polynomial<Сoef>::operator + (const T& op) const
{
	//Привести T к типу полинома
	Polynomial<Сoef> Temp(op);
	return *this + Temp;
}*/

//Сложение любого нешаблонного типа и полинома	type+A
template<typename Coef, typename T> 
Polynomial<Coef> operator+(const T& op, const Polynomial<Coef>& P)
{
	return P+op;
}

//Вычитание любого типа из полинома	 A-type (A+ (-type)) //Тоже не нужно
/*template<typename Coef>
template<typename T>
Polynomial<Coef> Polynomial<Coef>::operator - (const T& op) const
{
	return *this + Polynomial<Coef>(-op);
}
*/

//Вычитание из какого-то типа полинома		type-A (type + (-A))
template<typename Coef, typename T>
Polynomial<Coef> operator-(const T& op, const Polynomial<Coef>& P)
{
	return Polynomial<Coef>(op) - P;
}

//Умножение полиномов A*B, а также умножение полинома на какой то тип, неявно приводимый к Polynomial<Coef>
template<typename Coef>
Polynomial<Coef> Polynomial<Coef>::operator*(const Polynomial<Coef>& P)
{
	int composition_power = this->power + P.power; //Порядок произведения
	Polynomial<Coef> Result; //Создать возвращаемый объект
	delete [] Result.coef_arr; //Освободить память у созданного объекта
	Result.coef_arr = new Coef[composition_power + 1]; //Выделить память под возвращаемый полином
	Result.power = composition_power; //Cтепень полинома
	//Заполнить нулями
	for (int i = 0; i <= composition_power; i++)
		Result.coef_arr[i] = 0;

	int this_power = this->power; //Порядок полинома слева от *
	int P_power = P.power;// Порядок полинома справа от *
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

//Умножение какого-то типа на полином 
template<typename Coef, typename T>
Polynomial<Coef> operator*(const T& op, const Polynomial<Coef>& P)
{
	return P*op;
}

//Деление полиномов
template<typename Coef>
Polynomial<Coef> Polynomial<Coef>::operator/ (const Polynomial<Coef>& divider) const
{
	if (this->power < divider.power) //Если степень делителя больше, что частное равно 0.
		return Polynomial<Coef>();

	//Теперь надо создать полином, который будет частным. Вычислим его порядок.
	int quotient_power = this->power - divider.power; //Порядок частного
	//Выделим память
	Coef* mem = new Coef[quotient_power + 1];
	//Создадим объект полинома, присвоим ему выделенную память
	Polynomial<Coef> Quotient;
	delete[] Quotient.coef_arr;
	Quotient.coef_arr = mem;
	Quotient.power = quotient_power;
	//Заполнить массив mem нулями.
	for (int i = 0; i <= quotient_power; i++)
		mem[i] = 0;
	
	//Копия делимого, она будет уменьшаться с каждым делением.
	Polynomial<Coef> Dividend = *this; //Через конструктор копирования
	//Итак, будем получать коэффициенты для частного деля старшие члены друг на друга
	for (int i = 0; i <= quotient_power; i++)
	{
		if (Dividend.power < divider.power)
			Quotient.coef_arr[i] = 0;
		else
		{
			Quotient.coef_arr[i] = Dividend.coef_arr[0] / divider.coef_arr[0];//Записать коэф.
			//cout << "Quotient: " << Quotient << endl << "Exch: " << Polynomial(mem + i, quotient_power - i + 1) << endl;
			Dividend = Dividend - (Polynomial(mem + i, quotient_power - i + 1) * divider); //Уменьшить 
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
	Coef* new_coef_arr = new Coef[this->power - i+1];//Выделить меньшую память 
	for (int j = i,k=0; j <= this->power; j++, k++)
		new_coef_arr[k] = coef_arr[j];
	this->power = this->power - i;
	delete[] coef_arr;
	coef_arr = new_coef_arr;
	return *this;
}

//Перегрузка для объектов ostream <<
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