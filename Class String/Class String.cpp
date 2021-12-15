// Class String.cpp : 
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;


class String
{	
	std::string str;
	std::string str1;
	std::string str2;
	std::string str3;
	std::string str4;
public: 
	std::string get_str()const
	{
		return str;
	}
	std::string get_str1()const
	{
		return str1;
	}
	std::string get_str2()const
	{
		return str2;
	}
	void set_str(std:: string str)
	{
		this->str = str;
	}
	void set_str1(std::string str1)
	{
		this->str1 = str1;
	}
	void set_str2(std::string str2)
	{
		this->str2 = str2;
	}
	String() 
	{
		this->str;
		this->str1;
		this->str2;
		
		cout << "DefaultConstruct:\t" << this << endl;
	}
	String(const char* str)
	{
		this->str = str;
		this->str1 = str1;
		this->str2 = str2;
		cout << "lagrConstructor:\t" << this << endl;
	}
	~String()
	{
		cout << "Destructor:\t" << endl;
	}
		
};  

	 std::ostream& operator<<(std::ostream& os, const String& str)
	 {		
		 return os;
	 }    

    std::string str;	
	std::string str1 = "Hello,";	
	std::string str2 = "World!";
	std::string str3 = str1 + str2 ;
	std::string str4; 


int main()
{   
	setlocale(LC_ALL, "Russian");

	String str("80");
    String str1 = "Hello";
	String str2 = "World";
	String str4("25");
	//String str3 = str1 + str2;
	std::cout << "str: " << endl;
	std::cout << "str1: " << "Hello," << endl;
	std::cout << "str2: " << "Word!" << endl;
	std::cout << str3 << endl;
	std::cout << "str4: " << endl;
}

