//U19CS009
//Brijesh Rohit

#include<bits/stdc++.h>
using namespace std;

class users {
	int count;
	vector<string> unames;
public:
	users()
	{
		count = 0;
	}

	bool checkuser(string uname)
	{
		auto isUser = find(this->unames.begin(), this->unames.end(), uname);
		if (isUser == unames.end())return true;
		return false;
	}

	int verify_username(string uname)
	{
		//MIN LENGTH IS 5
		if (uname.length() < 5)
		{
			return -1;
		}
		if (!isalpha(uname[0]) && uname[0] != '_')
		{
			return 0;
		}
		for (int i = 1; i < uname.length(); i++)
		{
			if (!isalnum(uname[0]) && uname[0] != '_' && uname[0] != '.')
			{
				return 0;
			}
		}
		if (!checkuser(uname))
		{
			return 0;
		}
		return 1;
	}

	void adduser(string uname)
	{
		if (this->verify_username(uname) == 0 || this->verify_username(uname) == -1)
		{
			return;
		}
		this->count++;
		this->unames.push_back(uname);

	}

};

int main()
{

	users u;

	string s[5] = {"brijesh", "birju", "B@1234", "Bw_12__231"};
	for (int i = 0; i < 5; i++)
		u.adduser(s[i]);

	//USER INPUT
	string s1;
	cout << "Enter an username : ";
	cin >> s1;
	if (u.verify_username(s1) == -1)
	{
		cout << "Too Short : " << s1.length() << endl;
	}
	else if (u.verify_username(s1) == 0)
	{
		cout << "Invalid" << endl;
	}
	else
	{
		cout << "Valid" << endl;
	}
	return 0;
}