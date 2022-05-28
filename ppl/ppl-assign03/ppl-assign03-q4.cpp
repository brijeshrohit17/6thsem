//U19CS009
//Brijesh Rohit

#include<bits/stdc++.h>
using namespace std;

void display()
{
	ifstream in;
	in.open("file.txt");
	string s;
	while (in)
	{
		//fetching line in s.
		getline(in, s);
		int i;
		int flag = 0;
		string temp, temp1;
		//finding first word
		for ( i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ')
			{
				break;
			}
			temp += s[i];

		}
		temp[i] = '\0';
		//left align
		cout << setw(15) << left << temp;
		//finding phone number
		for (int j = i; j < s.length(); j++)
		{
			temp1 += s[j];

		}
		//right align
		cout << setw(15) << right << temp1 << endl;

	}
}

int main()
{
	display();
	return 0;
}