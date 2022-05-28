//U19CS009
//Brijesh Rohit

#include <bits/stdc++.h>
using namespace std;

int complexCalc(int a, int b)
{
	int c = pow(a, b);
	c = pow(c,c);
	return c;
}

int main()
{
	int a, b;
	cout << "Enter Value a and b : ";
	cin >> a >> b;

	try {
		int n = complexCalc(a, b);
		cout << "The result of complexCalc() : " << n << endl;
	}
//catching bad alloc
	catch (bad_alloc & b) {
		cerr << "Bad memory allocation : " << b.what() << endl;
	}
//catching std exception
	catch (exception & e)
	{
		cerr << "Standard Exception Caught : " << e.what() << endl;
	}
//catching other exception
	catch (...)
	{
		cerr << "Other Exception" << endl;
	}
	return 0;
}
