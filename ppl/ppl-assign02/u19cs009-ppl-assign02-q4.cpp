//U19CS009
//Brijesh Rohit

#include<bits/stdc++.h>
using namespace std;

class Book 
{
	int number_of_books;
	string *author;
	string *title;
	string *publisher;
	int *price;
	int *stock;
	static int successful_transaction;
	static int unsuccessful_transaction;
public:

	Book(int num)
	{
		this->number_of_books = num;
		this->author = new string[num];
		this->title = new string[num];
		this->price = new int[num];
		this->publisher = new string[num];
		this->stock = new int[num];
	}

	void listBook()
	{
		for (int i = 0; i < (this->number_of_books); i++)
		{
			cout << "\nEnter Details of Book " << i + 1 << " : \n";
			cout << "Enter title of the Book           : ";
			cin >> this->title[i];
			cout << "Enter author of the Book          : ";
			cin >> this->author[i];
			cout << "Enter publisher of the Book       : ";
			cin >> this->publisher[i];
			cout << "Enter the price of the Book       : ";
			cin >> this->price[i];
			cout << "Enter stock of the Book available : ";
			cin >> this->stock[i];
		}
	}

	void displayDetails()
	{
		cout << "Details:\n";
		for (int i = 0; i < (this->number_of_books ); i++)
		{
			cout << "\n----------------------------------------------------\n";
			cout << "----------------------------------------------------\n";
			cout << "Title           : "  << this->title[i];
			cout << "\nAuthor          : "  << this->author[i];
			cout << "\nPublisher       : "  << this->publisher[i];
			cout << "\nPrice           : "  << this->price[i];
			cout << "\nStock Available : "  << this->stock[i];
			cout << "\n----------------------------------------------------\n";
			cout << "----------------------------------------------------\n";
		}
	}

	int checkIndex(int index)
	{
		if (index < 0 || index > this->number_of_books)
		{
			return 0;
		}
		return 1;
	}

	int searchBook(string title, string author)
	{
		for (int i = 0; i < this->number_of_books; i++)
		{
			if (title.compare(this->title[i]) == 0 && author.compare(this -> author[i]) == 0)
			{
				return i;
			}
		}
		return -1;
	}

	void updatePrice(int i, int price)
	{
		if (!checkIndex(i)) {
			cout << "Inavlid index!!" << endl;
			return;
		}
		this->price[i] = price;
	}

	void bookDetail(int index)
	{
		if (!checkIndex(index)) {
			cout << "Inavlid index!!" << endl;
			return;
		}
		cout << "\n----------------------------------------------------\n";
		cout << "----------------------------------------------------\n";
		cout << "Title           : "  << this->title[index];
		cout << "\nAuthor          : "  << this->author[index];
		cout << "\nPublisher       : "  << this -> publisher[index];
		cout << "\nPrice           : "  << this->price[index];
		cout << "\nStock Available : "  << this->stock[index];
		cout << "\n----------------------------------------------------\n";
		cout << "----------------------------------------------------\n";
	}
	
	void buyBook(int index, int copies)
	{
		if (!checkIndex(index)) {
			cout << "Inavlid index!!" << endl;
			return;
		}
		if (copies > (this->stock[index]))
		{
			cout << "Transaction failed!!( Not enough in stock ) " << endl;
			this->unsuccessful_transaction++;
			return;
		}
		cout << "Transaction Successful!! " << endl;
		this->successful_transaction++;
		this->stock[index] -= copies;
	}
	
	void statistic()
	{
		cout << "\nTotal number of Successful transactions   : " << successful_transaction;
		cout << "\nTotal number of Unsuccessful transactions : " << unsuccessful_transaction << endl;
	}
	
	void deletelist()
	{
		delete []author;
		delete []title;
		delete []publisher;
		delete []price;
		delete []stock;
	}
};

int Book:: successful_transaction{0};
int Book:: unsuccessful_transaction{0};

int main()
{
	int n, ch;
	cout << "Enter number of books : ";
	cin >> n;
	Book b(n);
	b.listBook();
	system("CLS");
	while(1)
	{
		cout << "\nPlease enter vector operations according to following.";
		cout << "\n1 : Display List.\t2 : Search Book.\t3 : Display Book Details.";
		cout << "\n4 : Update Price.\t5 : Buy Book.   \t6 : Display Statistics.";
		cout << "\n7 : Exit\nEnter your choice : ";
		cin >> ch;
		system("CLS");
		string title, author;
		int index, price, copies;
		if ( ch == 1)
		{
			b.displayDetails();
		}
		else if (ch == 2)
		{
			cout << "Enter Title of the Book : ";
			cin >> title;
			cout << "Enter author of the Book : ";
			cin >> author;
			index = b.searchBook(title, author);
			if (index == -1)
			{
				cout << "\nBook Not found!!\n";
			}
			else
			{
				cout << "Index of book is : " << index << endl;
			}
		}
		else if ( ch == 3)
		{
			cout << "Enter the index of the Book : ";
			cin >> index;
			b.bookDetail(index);
		}
		else if ( ch == 4)
		{
			cout << "Enter the index of the Book : ";
			cin >> index;
			cout << "Enter the price of the Book : ";
			cin >> price;
			b.updatePrice(index, price);
		}
		else if ( ch == 5)
		{
			cout << "Enter the index of the Book : ";
			cin >> index;
			cout << "Enter number of copies of the Book : ";
			cin >> copies;
			b.buyBook(index, copies);
		}
		else if (ch == 6)
			b.statistic();
		else if (ch == 7)
		{
			b.deletelist();
			break;
		}	
		else
		{
			cout << "\nInvalid Choice!!" << endl;
			cout << "\nDo you want to exit ?";
			cout << "\n1 : Yes.\n2 : No, continue service.\nEnter your choice : ";
			int exit;
			cin >> exit;
			if(exit)
			{
				b.deletelist();
				cout << "\nThank You!!";
				cout << "\nHope you ENJOYED the service!!\n\n";
				break;
			}
			else
				continue;
		}
	}
	system("CLS");
	return 0;
} 