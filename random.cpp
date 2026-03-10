#include <cstddef>
#include <iostream>
#include <vector>
#include <cstdint>
#include <math.h>

using namespace std;

//https://github.com/jtulak/RdRand/
int RDRAND16_STEP(uint16_t *x)
{
  unsigned char err = 1;
  asm volatile (".byte 0x66; .byte 0x0f; .byte 0xc7; .byte 0xf0; setc %1"
                      : "=a" (*x), "=qm" (err));
  if(err == 1)
  {
    return 1;
  }
  return 0;
}

double trurand()
{
  uint16_t seed;
  if (RDRAND16_STEP(&seed))
  {
    return abs(sin(seed));
  }

  return 0;
}

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
        int rando = (int)(trurand() * (double)(ceiling-bottom) + bottom);
        for (auto& c : blacklist)
        {
            if (rando == c)
            {
                yesorno = false;
                break;
            }
        }

        if (yesorno)
        {
            if (rando < bottom && rando > ceiling) continue;
            cout << rando << endl;
            blacklist.push_back(rando);
            j++;
            continue;
        }
        yesorno = true;
    }
}
