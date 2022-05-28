#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ifstream file;
    file.open("empty.txt", ios::binary);
    char c;
    int n = 0;
    while(file)
    {
        file.get(c);
        n++;
    }
    n = n?n-1:0;
    file.close();
    cout << "Number of characters : " << n << "\n";
    return 0;
}