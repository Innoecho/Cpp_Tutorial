#include <iostream>
using namespace std;

int main()
{
   int a = 21;
   int c ;

   c =  a;
   cout << "Line 1  : c  = : " << c << endl ;

   c +=  a;
   cout << "Line 2  : c  = : " << c << endl ;

   c -=  a;
   cout << "Line 3  : c  = : " << c << endl ;

   c *=  a;
   cout << "Line 4  : c  = : " << c << endl ;

   c /=  a;
   cout << "Line 5  : c  = : " << c << endl ;

   c  = 200;
   c %=  a;
   cout << "Line 6  : c  = : " << c << endl ;

   c <<=  2;
   cout << "Line 7  : c  = : " << c << endl ;

   c >>=  2;
   cout << "Line 8  : c  = : " << c << endl ;

   c &=  2;
   cout << "Line 9  : c  = : " << c << endl ;

   c ^=  2;
   cout << "Line 10  : c  = : " << c << endl ;

   c |=  2;
   cout << "Line 11  : c  = : " << c << endl ;

   return 0;
}