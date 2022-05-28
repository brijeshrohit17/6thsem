#include <iostream>
using namespace std;

struct CandyBar
{
    string brand_name;
    float weight;
    int calories;
};

int main()
{
    CandyBar snack = {"Mocha Munch", 2.3, 350};
    cout << "Contents of snack variable:\n";
    cout << "snack.brand_name: " << snack.brand_name << "\n";
    cout << "snack.weight: " << snack.weight << "\n";
    cout << "snack.calories: " << snack.calories << "\n";
    return 0;
}