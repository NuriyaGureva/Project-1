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
 //           Optranors:
   void operator =(const Point& other)
   {
	   this->x = other.x;
	   this->y = other.y;
	   cout << "CopyAssignment:\t" << this << endl;
   } 

   ~Point()
   {
	   cout << "Destructor:\t" << this << endl;
   }
   //        Methods:

   double distance(Point other)
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
double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}

//Point G;    //Global object;
int g;       //  Global  variable;

//#define STRUCT_POINT
//#define CONSTRUCTOR_CHECK
// #define DISTANCE_CHECK
#define ASSIGNMENT_CHECK


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
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;

	cout << "Расстояние между точками А до точки В: " << distance(A, B) << endl;
	cout << "Расстояние между точками B до точки A: " << distance(B, A) << endl;
#endif // DISTANCE-CHECK



#ifdef  ASSIGNMENT_CHECK	

	Point A, B, C;	
	A = Point(2, 3);
	A.print();	

	B = Point(2, 3);
	B.print();	

	C = Point(2, 3);	
	C.print();

#endif  ASSIGNMENT_CHECK

} 
