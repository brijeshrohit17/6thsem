#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter 2 integers : ";
    cin >> a >> b;
    int sum = b * (b + 1) / 2 - a * (a - 1) / 2;
    cout << "Sum : " << sum << "\n";
    return 0;
}