//U19CS009
//Brijesh Rohit

#include<iostream>
#include<chrono>
#include<unistd.h>
using namespace std::chrono;
using namespace std;

class Base {
public:
	int sum(int x) {
		return x + 2;
	}
	virtual int sum(int x, int y) {
		int a = x;
		int b = y;
		int result = a + b;
		return result;
	}
};

class Derived : public Base {
public:
	int sum(int x, int y) override {
		int a = x;
		int b = y;
		int result = a + b;
		return result;
	}
};

int main(int argc, char const *argv[])
{
	Base B;
	
	//overloading
	auto start = high_resolution_clock::now();
	for (int i = 0; i < 1000000000; i++)
		int ans = B.sum(2, 4);
	auto end = high_resolution_clock::now();
	
	auto duration = duration_cast<microseconds>(end - start);
	
	cout << "Time taken in Overloading : " << duration.count() << " microseconds." <<  endl;;
	auto time1 = duration.count();
	sleep(2);
	
	Derived d;
	Base *bsptr = &d;

	//overrinding
	start = high_resolution_clock::now();
	for (int i = 0; i < 1000000000; i++) {
		int ans = bsptr->sum(2, 4);
	}
	end = high_resolution_clock::now();
	
	duration = duration_cast<microseconds>(end - start);
	
	cout << "Time taken in Overriding  : " << duration.count() << " microseconds" << endl;
	auto time2 = duration.count();
	
	cout << "Difference in time : " << time2 - time1 << " microseconds" << endl;
	return 0;
}