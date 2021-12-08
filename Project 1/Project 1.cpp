// Project 1.cpp 

#include <iostream>
using namespace std;
#define tab "\t"
class Point
//struct Point 
{
	double x;
	double y;
public:
	//get_ методы должны быть константами
	//
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
   void	set_x(double x)
	{
		this-> x = x;
	} 
   void	set_y(double y)
	{
		this->y = y;
	}
   //              Constructors;

   /*Point()
   {
	   x = y = 0;
	   cout << "DefoltConstructor:\t" << this << endl;
   }*/
 /*  Point(double x)
   {
	   this->x = x;
       this->y = 0;
     cout << "largConstructor:\t" << this << endl;
   }*/
   Point(double x = 0 , double y = 0 )
   {
	   this->x = x;
	   this->y = y;
	   cout << "Constructor:\t" << this << endl;
   }
   Point(const Point& other)
   {
	   this->x = other.x;
	   this->y = other.y;
	   cout << "CopyConstructor:" << this << endl;
   }
   ~Point()
   {
	   cout << "Destructor:\t" << this << endl;
   }
 //           Optranors:
   Point& operator =(const Point& other)
   {
	   this->x = other.x;
	   this->y = other.y;
	   cout << "CopyAssignment:\t" << this << endl;
	   return *this;
   } 
   Point& operator++()//Prefix increment
   {
	   this->x++;
	   this->y++;
	   return *this;// Возвращаем измененное значение
   }
   Point operator++(int)//Postfix increment
   {
	   Point old = *this;//Сохраняем старое значение
	   x++;
	   y++;
	   return old;//Старое(не измененное) значение объекта
   }
   //        Methods:

   double distance(const Point& other)const
	   {
	   double x_distance = this->x - other.x;
	   double y_distance = this->y - other.y;
	   double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	   return distance;
	   }
   void print() const
   {
	   cout << "X = " << x << "\tY=" << y << endl ;
   }

};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}
Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

//Point G;    //Global object;
int g;       //  Global  variable;

//#define STRUCT_POINT
//#define CONSTRUCTOR_CHECK
 //#define DISTANCE_CHECK
//#define ASSIGNMENT_CHECK


void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT_POINT
	//type name;
	int a;//объявление переменной'a'типа'int'
	Point A;//объявление переменной'a'типа''Point'
	// Объявление объекта'A'структуры 'структуры 'Point'
	// Создание экземпляра 'A'структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;
	Point* pA = &A; // Объявляем указатель на Point'pA'и
	//инициализируем его адресом объекта 'a'
	
	cout << pA->x << tab << pA->y << endl
	cout << (*pA).x << tab << (*pA).y << endl;
		
#endif // STRUCT_POINT

#ifdef CONSTRUCTOR_CHECK
	Point A;
	/*A.set_x(2);
	A.set_y(3);*/
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();	

	Point B(4, 5);
	B.print();

	Point C = 5;       //Single-argument constructor
	C.print();
	//cout << C.get_x() << endl;

	Point D(8); // Single-argument constructor
	D.print(); 

	Point E = D; //Copyconstructor
	E.print();  

	Point F(B); //Copyconstructor
	F.print();
	/*cout << "\n-------------------------\n";
   cout << Point(123, 234).distance(Point(345, 456)) << endl;
   cout << "\n---------------------------\n";*/

	Point G;  //Default constructor
	G = F;   //CopyAssignment (operator=)
	G.print();
#endif 

#ifdef DISTANCE-CHECK
	Point A(2, 3);
	Point B(3, 4);
	cout << "\n---------------------------\n";
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << "\n---------------------------\n";
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << "\n---------------------------\n";
	cout << "Расстояние между точками А до точки В: " << distance(A, B) << endl;
	cout << "\n---------------------------\n";
	cout << "Расстояние между точками B до точки A: " << distance(B, A) << endl;
	cout << "\n---------------------------\n";
#endif //DISTANCE-CHECK

#ifdef  ASSIGNMENT_CHECK	
	int a, b, c;
	a = b = c = 0;
	cout << a << tab << b << tab << endl;
	//Point(2,3);явно вызываем конструктор,который создает временны безымянный объект
;	Point A, B, C;	
	cout << "\n---------------------------\n";
	A = C = B = Point(2,3);
	cout << "\n---------------------------\n";
	A.print();
	B.print();
	C.print();

#endif  ASSIGNMENT_CHECK

	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(4, 5);
	Point C = A + B;
	C.print();
	C++;
	C.print();


} 

