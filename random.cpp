#include <iostream>
#include <vector>
using namespace std;

bool yesorno = true;
int bottom, ceiling;

int main()
{
    cout << "Enter the floor: ";
    cin >> bottom;
    cout << "Enter the ceiling: ";
    cin >> ceiling;
    ceiling++;
    vector<int> blacklist;
    for (int j = 0; j < ceiling-bottom; j)
    {
        int rando = rand() % (ceiling-bottom) + bottom;
        for (auto& c : blacklist)
        {
            if (rando == c)
            {
                yesorno = false;
            }
        }
        if (yesorno)
        {
            cout << rando << endl;
            blacklist.push_back(rando);
            j++;
            continue;
        }
        yesorno = true;
    }
}