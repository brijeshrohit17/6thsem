//U19CS009
//Brijesh Rohit

#include <bits/stdc++.h>
using namespace std;

const float pi = 3.14159; //value of pi

class polar {
	float radius;	//in unit length
	float angle;	//in radians
public:

	polar(float r, float th)
	{
		this->radius = r;
		this->angle = th;
	}

	void setRadius(float r )
	{
		this->radius = r;
	}
	float getRadius()
	{
		return this->radius;
	}
	void setAngle(float t )
	{
		this->angle = t;
	}
	float getTheta()
	{
		return this->angle;
	}

	pair<float, float> ConvToRect()
	{
		float x = (this->radius) * cos(this->angle);
		float y = (this->radius) * sin(this->angle);
		return make_pair(x, y);
	}
	//operator overloading
	polar operator + (polar obj2)
	{
		pair<float, float> p1 = this->ConvToRect();
		pair<float, float> p2 = obj2.ConvToRect();
		float x, y;
//			cout<<"P1 : "<<p1.first<<" "<<p2.second<<endl;
//			cout<<"P2 : "<<p2.first<<" "<<p2.second<<endl;
		x = p1.first + p2.first;
		y = p1.second + p2.second;
		polar P(0, 0);
		float r, th;
		r = sqrt(x * x + y * y);

		th = float(atan2(y, x));

		P.setRadius(r);
		P.setAngle(th);
		return P;
	}
	void display()
	{
		cout << "Radius : " << this->getRadius();
		cout << "\tAngle : " << this->getTheta();
	}
};

int main()
{
	float r, th;
	
	cout << "Enter first Polar coordinates (r,th)): ";
	cin >> r >> th;
	polar p1(r, th);
	
	cout << "Enter second Polar coordinate (r,th)): ";
	cin >> r >> th;
	polar p2(r, th);
	
	polar p3(0, 0);
	cout << "The three polar coordinates are :\n";
	cout << "p1 : ";
	p1.display();
	cout << "\n";
	cout << "p2 : ";
	p2.display();
	cout << "\n";
	cout << "p3 : "; 
	p3.display();
	cout << "\n";
	
	cout << "p3 is changed to sum of p1 and p2.\n";
	p3 = p1 + p2;
	cout << "Addition of both coordinates : ";
	p3.display();
	cout << "\n";
	return 0;
}