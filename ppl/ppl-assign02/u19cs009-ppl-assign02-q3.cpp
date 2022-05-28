//U19CS009
//Brijesh Rohit

#include<bits/stdc++.h>
using namespace std;

class Vector {
	int size;
	float *arr;
public:
	Vector(int size)
	{
		this->size = size;
	}

	void createVector()
	{
		this->arr = new float[this->size];
		cout << "\nMemory allocated Successfully!!\n";
		for (int i = 0; i < this->size; i++)
		{
			cout << "Enter the element : ";
			cin >> this->arr[i];
		}
		cout << "\n";
	}
	
	void displayVector()
	{
		int i;
		cout << "\nThe vector is : [ ";
		for ( i = 0; i + 1 < this->size; i++)
		{
			cout << this->arr[i] << ", ";
		}
		cout << this->arr[i] << " ]" << endl;
	}
	
	void modifyData(int index, int value)
	{
		if (index < 0 || index > this->size)
		{
			cout << "\nIndex is Invalid!!";
			return;
		}
		this->arr[index] = value;
		this->displayVector();
	}
	
	void multiplyVector(int scaler)
	{
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] *= scaler;
		}
		this->displayVector();
	}
	
	void deleteVector()
	{
		delete []this->arr;
	}
};

int main()
{
	int n;
	cout << "Enter the size of vector : ";
	cin >> n;
	Vector v(n);
	cout << "\nCreating Vector!!";
	v.createVector();
	v.displayVector();
	int ch = 0;
	while(1) {
		cout << "\nPlease enter vector operations according to following.";
		cout << "\n1 : Display vector.\t2 : Modify an element.";
		cout << "\n3.Multiply by scaler.\t4.Exit.\nEnter your choice : ";
		cin >> ch;
		if (ch < 0 || ch > 4)
		{
			cout << "\nInvalid Choice!!" << endl;
			cout << "\nDo you want to exit ?";
			cout << "\n1 : Yes.\n2 : No, continue service.\nEnter your choice : ";
			int exit;
			cin >> exit;
			if(exit)
			{
				cout << "\nThank You!!";
				cout << "\nHope you ENJOYED the service!!\n\n";
				break;
			}
			else
				continue;
		}
		if (ch == 1)
		{
			v.displayVector();
		}
		else if (ch == 2)
		{
			int i, val;
			cout << "Enter the index to be modified : ";
			cin >> i;
			cout << "Enter the new value : ";
			cin >> val;
			v.modifyData(i, val);
		}
		else if (ch == 3)
		{
			int sc;
			cout << "Enter the scalar value : ";
			cin >> sc;
			v.multiplyVector(sc);
		}
		if(ch == 4)
		{
			cout << "\nThank You!!";
			cout << "\nHope you ENJOYED the service!!\n\n";
			break;
		}
	}
	v.deleteVector();
	return 0;
}