//U19CS009
//Brijesh Rohit

#include<iostream>
using namespace std;

template <class T>
class AddElements {
	T data1;
	T data2;
public:
	AddElements(T x, T y)
	{
		this->data1 = x;
		this->data2 = y;
	}
	T add()
	{
		return this->data1 + this->data2;
	}
};

template<>

class AddElements <string> {
	string data1;
	string data2;
public:
	AddElements(string x, string y)
	{
		this->data1 = x;
		this->data2 = y;
	}
	string concatenate()
	{
		return this->data1.append(this->data2);
	}
};

int main()
{
	int choice;
	cout << "Enter the type\n1 : int\n2 : float\n3 : string\nEnter your choice : ";
	cin >> choice;
	if (choice == 1)
	{
		int ele1, ele2;
		cout << "Enter first integer  : ";
		cin >> ele1;
		cout << "Enter second integer : ";
		cin >> ele2;
		AddElements<int> obj(ele1, ele2);
		cout << "Result (Addition) : " << obj.add() << endl;
	}
	else if (choice == 2)
	{
		float ele1, ele2;
		cout << "Enter first floating number  : ";
		cin >> ele1;
		cout << "Enter second floating number : ";
		cin >> ele2;
		AddElements<float> obj(ele1, ele2);
		cout << "Result (Addition) : " << obj.add() << endl;
	}
	else if (choice == 3)
	{
		string ele1, ele2;
		cout << "Enter first string  : ";
		cin >> ele1;
		cout << "Enter second string : ";
		cin >> ele2;
		AddElements<string> obj(ele1, ele2);
		cout << "Result (Concatenation) : " << obj.concatenate() << endl;
	}
	else
		cout << "Invalid operation!!!" << endl;
	
	return 0;
}