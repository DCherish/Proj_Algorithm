#include <iostream>
#include <cstdlib>
#include <time.h>

#define MAX 16384 // 16384 = 2^14

using namespace std ;

void print_elapsed(clock_t start, clock_t stop)
{
	double elapsed = ((double)(stop - start)) / CLOCKS_PER_SEC ; // elapsed = how much time goes on
	cout << "Elapsed time : " << elapsed << "sec" << endl ; // print time (sec)
}

int main(void)
{
   clock_t start, stop ;

   int s = 0 ; // Initialize value
   int u = 0 ; // Initialize value

   int *p = new int[MAX] ; // Make array that the number of room is MAX

   srand((unsigned)time(NULL)) ; // Different values are occured at every time
   
   for( int i = 0 ; i < MAX ; i++ )
   {
      p[i] = rand() ; // Put random number into p array
   }
   
   start = clock() ; // time start

   for( int i = 0 ; i < MAX ; i++ ) // OddEven Sort
   {
      s = i ; // OddEven Sort start with oddsort
      u = s % 2 ; // It determines whether is oddsort or evensort

      if ( u == 0 ) // Execute oddSort
      {
         for( int j = 0 ; j < MAX ; j = j + 2 ) // Compare 1<->2, 3<->4, 5<->6, ...
         {
            if ( p[j] > p[j+1] ) // If 1>2 (or 3>4, 5>6, ...) 
            {
               int temp = p[j] ;
               p[j] = p[j+1] ;
               p[j+1] = temp ; // Change 1<->2, 3<->4, 5<->6, ...
            }
         }
      }else // Execute evenSort
      {
         for( int j = 1 ; j < MAX - 1 ; j = j + 2 ) // Compare 2<->3, 4<->5, 6<->7, ...
         {
            if ( p[j] > p[j+1] ) // If 2>3 (or 4>5, 6>7, ...) 
            {
               int temp = p[j] ;
               p[j] = p[j+1] ;
               p[j+1] = temp ; // Change 2<->3, 4<->5, 6<->7, ...
            }
         }
      }
   }

   stop = clock() ; // time stop

   cout << "12141680 OddEven-Sort\n" << endl ;

   print_elapsed(start, stop) ; // print elapsed time

   for( int i = 0 ; i < MAX ; i++ )
   {
      cout << p[i] << " " ; // Print sorted all number in p array
   }

   cout << endl ;

   delete p ;

   return 0 ;
}