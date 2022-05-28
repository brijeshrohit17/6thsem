#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream in("q1.cpp");
    char c;
    int count = 0;
    while (c = in.get())
    {
        if (c == -1)
            break;
        count++;
    }
    cout << "Number of characters: " << count << "\n";
    return 0;
}