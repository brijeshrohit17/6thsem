#include<iostream>
using namespace std;
int main()
{
    int num1, num2;
    printf("Please enter two integers : ");
    cin >> num1 >> num2;
    if(num1 > num2)
    {
        num1 += num2;
        num2 = num1-num2;
        num1 -= num2;
    }
    int sum = 0;
    for(int i = num1 ; i <= num2 ; i++)
        sum+=i;
    cout << "Sum : " << sum << "\n";
    return 0;
}