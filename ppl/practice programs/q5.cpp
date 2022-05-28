#include <iostream>
using namespace std;

int Fill_array(double arr[], int size)
{
    int i = 0;
    cout << "Enter double values to be entered in the array\n";
    while (i < size && (cin >> arr[i++]))
        ;
    return i - 1;
}

void Show_array(double arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " \n"[i == size - 1];
}

void Reverse_array(double arr[], int size)
{
    for (int i = 0; i < size - i - 1; i++)
        swap(arr[i], arr[size - i - 1]);
}

int main()
{
    int size;
    cout << "Enter the maxsize of array\n";
    cin >> size;
    double arr[size];
    size = Fill_array(arr, size);
    cout << "The array entered:\n";
    Show_array(arr, size);
    Reverse_array(arr, size);
    cout << "After reversing the array\n";
    Show_array(arr, size);
    if (size > 2)
        Reverse_array(arr + 1, size - 2);
    cout << "After reversing again accept first and last elements\n";
    Show_array(arr, size);
    return 0;
}