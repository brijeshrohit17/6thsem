#include <iostream>
using namespace std;
int main()
{
    double arr[10];
    double avg = 0;
    int index = 0;
    int count = 0;
    while (index < 10 && (cin >> arr[index++]))
    {
        avg += arr[index - 1];
    }
    if (index == 10)
        index++;
    avg /= index - 1;
    for (int i = 0; i < index; i++)
    {
        count += avg < arr[i];
    }
    cout << "Average is: " << avg;
    cout << " and the number of elements greater than average is " << count
         << endl;
    return 0;
}