#include <iostream>

using namespace std;

int biggerprime(int p)
{
   for (int i = p + 1; 1; i++)
   {
       int count = 0;
       for (int j = 2; j < i; j++)
       {
           if (i % j == 0) // found a divisor
           {
               count++;
               break;
           }
       }
       if (count == 0)
       {
           return i;
       }
   }
}

int main()
{
    int p = 21;

    p = biggerprime(p);

    cout << p << ' ';
    return 0;
}
