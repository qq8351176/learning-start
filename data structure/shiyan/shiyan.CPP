//20软工二康文迪
#include <iostream>
#include <random>
#include <time.h>
using namespace std;
int main()
{   
    int a[10];
    default_random_engine dre(time(0));          
    uniform_int_distribution<unsigned> u(1, 20); 
    int max, min, count = 0;
    for (int z = 0; z < 10; z++)
    {
        for (int i = 0; i < 10; i++)
        {
            a[i] = u(dre);
        }

        max = min = a[0];
        for (int i = 1; i < 10; i++)
        {
            if (a[i] >= max)
            {
                max = a[i];
                count++;
            }
            else if (a[i] <= min)
            {
                min = a[i];
                count++;
            }
            else
                count += 2;
        }
    }
    cout << "平均"<<count/10;
    return 0;
}
