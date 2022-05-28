#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    cout << "Enter words (to stop, type the word done):\n";
    string word;
    int count = 0;
    do
    {
        cin >> word;
        count++;
    } while (strcmp(word.c_str(), "done"));
    cout << "You entered a total of " << count - 1 << " words.\n";
    return 0;
}