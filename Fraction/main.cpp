
# pragma warning (disable:4326)

#include<iostream>
using std::cin;
using std::cout; 
using std::endl;


class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

bool operator==(Fraction left, Fraction right);
bool operator!=(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator>(Fraction left, Fraction right);
bool operator>=(Fraction left, Fraction right);
bool operator<=(Fraction left, Fraction right);


class Fraction
{
	int integer; //целая часть
	int numerator;//Числитель
	int denominator;//Знаменатель

public:

	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}

	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;	//Отфильтровываем 0
		this->denominator = denominator;
	}
	//         Constructor:

	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << " DefaultConstruct:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "lagrConstructor:\t" << this << endl;
	}

	/*explicit Fraction(double fraction)
	{
		this->integer = 0;
		this->numerator = fraction*100;
		this->denominator = 100;
		to_proper();
		reduce();
		cout << "lagrConstructor:\t" << this << endl;
	}*/
	explicit Fraction(double dicimal)
	{
		dicimal += 1e-11;
		integer = dicimal;
		denominator = 1e+9;
		dicimal -= integer;
		numerator = dicimal * denominator;
		reduce();
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);// Чтобы не обойти фильтрацию данных
		cout << "Constructor:\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denomenator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denomenator;
		cout << "Constructor;\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << endl;
	}
	//     Operators:

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}//          A    =    A   *  B
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	//     Type-cast operatops:

	explicit operator int()const
	{
		return integer;
	}
	explicit operator double()const
	{					
		return integer + (double)numerator / denominator;			
	}
			

	//        Methods:
	Fraction& to_improper()//переводит дробь в неправильную
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()//Переводит дробь в правильную
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}


	std::ostream& print(std::ostream&os = cout)const
	{
		if (integer)os << integer;//Если есть целая часть, выводим ее на экран
		if (numerator)
		{
			if (integer)os << "(";
			os << numerator << "/" << denominator;
			if (integer)os << ")";
		}
		else if (integer == 0)os << 0;
		return os ;
	}

	Fraction inverted()
	{
		to_improper();
		return Fraction(this->denominator, this->numerator);
	}
	Fraction& reduce()
	{
		int more, less;
		int rest;
		if (numerator > denominator )
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			less = numerator;
			more = denominator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;
		numerator /= GCD;
		denominator /= GCD;	
		return *this;		
	}	
	
	friend std::ostream& operator<< (std::ostream& os, const Fraction& obj);
	friend std::istream& operator>> (std::istream& in, Fraction& obj);
};
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	os << "Fraction: " << obj.numerator << "/" << obj.denominator << "\n";
	return os;
}

std::istream& operator>>(std::istream& in, Fraction& obj)
{
	in >> obj.numerator;	
	in >> obj.denominator;	
	return in;
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	//Fraction result
	//(
	//	left.get_numerator() * right.get_numerator(),
	//	left.get_denominator() * right.get_denominator()
	//	);
	//result.set_numerator(left.get_numerator() * right.get_numerator());
	//result.set_denominator(left.get_denominator() * right. get_denominator());
	//result.to_proper();
	//return result;
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(Fraction left, Fraction right)
{
	return left * right.inverted();
}

Fraction operator+(Fraction left, Fraction right)
{
	 left.to_improper();
	 right.to_improper();
	 return Fraction
		(left.get_numerator() * right.get_denominator()
		+ right.get_numerator() * left.get_denominator(),
			left.get_denominator() * right.get_denominator()
		).to_proper().reduce();	
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	 (left.get_numerator() * right.get_denominator()
		- right.get_numerator() * left.get_denominator(),
		 left.get_denominator() * right.get_denominator()
	 ).to_proper().reduce();
	
}	

bool operator==(Fraction left, Fraction right)
{      	
	left.to_improper();
	right.to_improper();
	return left.get_numerator()==right.get_numerator() &&
		left.get_denominator() == right.get_denominator();	
}
bool operator!=( Fraction left,  Fraction right)
{
	return !(left==right);
}
bool operator>(Fraction left, Fraction right)
{			
	return	left.get_numerator() > right.get_numerator() &&
		right.get_denominator() > left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{	
	return	left.get_numerator() < right.get_numerator() &&
		right.get_denominator() < left.get_denominator();
}
bool operator<=( Fraction left, Fraction right)
{
	return	left.get_numerator() <= right.get_numerator() &&
		left.get_denominator() <= right.get_denominator();
}
bool operator>=( Fraction left, Fraction right)
{		
	return	left.get_numerator() >= right.get_numerator() &&
		left.get_denominator() >= right.get_denominator();
}
//{
//	if (obj.get_integer())os <<obj.get_integer();//Если есть целая часть, выводим ее на экран
//		if (obj.get_numerator())
//		{
//			if(obj.get_integer())os << "(";
//			os << obj.get_numerator() << "/" <<obj.get_denominator();
//			if (obj.get_integer())os << ")";
//		}
//		else if (obj.get_integer() == 0)os << 0;
//		 return os;
//	
//}


//#define CONCTRUCTORS_CHEK
//#define OPERATORS_CHEK
//#define TYPE_CONVERSTIONS_BASICS
//#define CONVERSIONS_fROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OHER
//#define HOME_WORK


void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef CONCTRUKTORS_CHEK

	Fraction A;
	A.print();
	double b = 5;
	Fraction B = 5;
	B.print();
	Fraction C(3, 4);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
#endif // CONCTRUKTORS_CHEK

#ifdef OPERATORS_CHEK
	/*double a = 2.5;
double b = 3.4;
double c = a * b;
cout << c << endl;*/
//Fraction A(2, 1, 2);
//Fraction B(3, 2, 5);
//Fraction C = A * B;
//C.print();

/*Fraction D(840, 3600);
D.reduce();
D.print();*/
//C = A / B;
//C.print();
	Fraction A(2, 1, 2);
	Fraction B(3, 2, 5);
	A *= B;
	A.print();
	A /= B;
	A.print();

	A += B;
	A.print();
	A -= B;
	A.print();
	cout << (A == B) << endl;
	cout << (A != B) << endl;
	cout << (A > B) << endl;
	cout << (A < B) << endl;
	cout << (A >= B) << endl;
	cout << (A <= B) << endl;
#endif // OPERATORS_CHEK


#ifdef TYPE_CONVERSIONS_BASICS
	int a = 2;// нет преобразовании
	double b = 3;//преобразование от меньшего к большего
	int c = b;// преобразование от большего к меньшему
	int d = 4.5;// преобразовоние от большегок меньшему с потерей данных
	cout << d << endl;
#endif // TYPE_CONVERSIONS_BASICS

#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	double a = 2;//Преобразование из int в double
	Fraction A = (Fraction)5;//Преобразование из int в Fraction
	A.print();

	Fraction B;
	B = (Fraction)8;
	B.print();
	//explisit - явный спецификатор
	//Fraction C = 12;//explicit conctructor не возможно вызвать так
	Fraction C(12);// но explicit constructor всегда можно вызвать так	
	Fraction D{ 13 };// или так  
#endif //CONVERSIONS_FROM_OTHER_TO_CLASS

	//           Type-cast operatops:

#ifdef CONVERSIONS_FROM_CLASS_TO_OTHER

	double b = 2;
	int c = b; //from more to less
	//from 'double' to 'int'
	Fraction A(2);
	//int a = A;  From more to less
	//From 'Fraction' to 'int'
	int a(A);// Можно и так, явное преобразование
	cout << a << endl;
	int i = (int)A; //Явное преобразование

#endif // CONVERSIONS_FROM_CLASS_TO_OTHER


#ifdef HOME_WORK
	
	Fraction A(2, 3, 4);
	double a =(double) A;	
	cout << a << endl;
	
	double b = 2.75;
	cout << "n--------------------:\t" << endl;
	//Fraction B = (Fraction)b;
	Fraction B = b;
	B.print();
	cout << "n--------------------:\t" << endl;
#endif  HOME_WORK

	/*Fraction A(2, 3, 4);
	cout << A << endl;
	A.print();*/

	Fraction A;
 std:: cout << "Введите простую дробь: ";
 std:: cin >> A;
 std::cout << A << endl;

}	