//U19CS009
//Brijesh Rohit

#include<bits/stdc++.h>
using namespace std;

void update(int *a, int *b)
{
	int temp = *a;
	*a += *b;
	*b = abs(temp - (*b));
}

int main()
{
	int a, b;
	cout << "Enter values of 'a' : ";
	cin >> a ;
	cout << "Enter values of 'b' : ";
	cin >> b;
	int *p1 = &a;
	int *p2 = &b;
	update(p1, p2);
	cout << "\nNew value of 'a' : " << a;
	cout << "\nNew value of 'b' : " << b;
	cout << "\n";
	return 0;
}