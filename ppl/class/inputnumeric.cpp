#include<iostream>
#include<string>
#include<sstream>

using namespace std;

bool isNumeric(const string &str)
{
    int count = 0;
    for(const auto &c : str)
    {
        if(c == '.')
        {
            count++;
            if(count > 1)
            return false;
            continue;
        }
        if(isdigit(c)==0)
            return false;
    }
    return true;
}

int main()
{
    float arr[10];
    string s;
    int flag = 1;
    float sum = 0;
    cout << "Please enter 10 numeric values.\n";
    for(int i = 0; i < 10; i++)
    {
        cout << "Please enter " << i+1 << " th value : ";
        cin >> s;
        flag = isNumeric(s);
        if(flag)
        {
            arr[i] = stof(s);
            sum += arr[i];
            continue;
        }
        else
        {
            cout << "Program terminated with error!!" << "\n";
            break;
        }
    }
    if(flag)
    {
        sum /= 10;
        printf("Avg : %f", sum);
        int count = 0;
        for(int i = 0 ; i < 10 ; i++)
        {
            if(arr[i]>sum)
            count++;
        }
        cout << "\n" << count << " values are greater than " <<  sum << "\n";
    }
    return 0;
}