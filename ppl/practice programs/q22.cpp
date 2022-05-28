#include <iostream>
using namespace std;
struct CandyBar
{
    string brand_name;
    double weight;
    int calories;
};
void init(CandyBar &candyBar,
          const char *brand_name = "Millenium Munch",
          const double weight = 2.85,
          const int calories = 350)
{
    candyBar = (CandyBar){brand_name, weight, calories};
}
void print(const CandyBar &candyBar)
{
    cout << "Brand name: " << candyBar.brand_name << "\n";
    cout << "Weight: " << candyBar.weight << "\n";
    cout << "Calories: " << candyBar.calories << "\n";
}
int main()
{
    CandyBar candyBar;
    init(candyBar);
    print(candyBar);
    return 0;
}