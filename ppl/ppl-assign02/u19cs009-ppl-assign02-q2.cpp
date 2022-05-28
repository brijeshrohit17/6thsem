//U19CS009
//Brijesh Rohit

#include<bits/stdc++.h>
using namespace std;

class Hotel
{
public:
	int bedroom;
	int bathroom;
};

class HotelRoom : public Hotel
{
public:
	HotelRoom(int numOfBed, int numOfBath)
	{
		this->bedroom = numOfBed;
		this->bathroom = numOfBath;
	}
	int cost_of_Room()
	{
		return (this->bedroom * 50) + (this->bathroom * 100);
	}
};

class HotelApartment: public HotelRoom 
{
public:
	HotelApartment(int numOfBed, int numOfBath): HotelRoom(numOfBed, numOfBath) {}
	int cost_of_Apartment()
	{
		return (this->cost_of_Room()) + (int)100;
	}
};

int main()
{
	int n, ch, profit = 0;
	cout << "\nEnter Booking Details!!\n\n";
	cout << "Enter number of booking requests : ";
	cin >> n;
	while (n--)
	{
		cout << "\nPlease enter booking type!\n";
		cout << "1 : Standard Room.\t\t";
		cout << "2 : Apartment.\t\t";
		cout << "3 : Exit.\nEnter your choice : ";
		cin >> ch;
		if (ch > 3 || ch < 1)
		{
			cout << "\n\nEnter valid Choice!!";
			n++;
		}
		int numOfBed, numOfBath;
		cout << "Enter number of bedrooms  : ";
		cin >> numOfBed;
		cout << "Enter number of bathrooms : ";
		cin >> numOfBath;
		if (ch == 1)
		{
			HotelRoom hroom(numOfBed, numOfBath);
			profit += hroom.cost_of_Room();
		}
		else if (ch == 2)
		{
			HotelApartment hapart(numOfBed, numOfBath);
			profit += hapart.cost_of_Apartment();
		}
		else
		{
			cout << "\nThank You!!";
			cout << "\nHope you ENJOYED the service!!\n\n";
			break;
		}
		if(n==0)
		{
			cout << "\nThank You!!";
			cout << "\nHope you ENJOYED the service!!\n\n";
			break;
		}
	}
	cout << "The Gross profit is : " << profit;
	cout << "\n\n";
	return 0;
}