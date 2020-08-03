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

void shellsort(int p[], int n)
{
	int s = 0 ; // Initialize value
	int j = 0 ; // Initialize value

	for( int h = 1 ; h < n ; h = 3*h + 1 )
	{
		s = h ; // find h maxsize
	}

	for( int h = s ; h > 0 ; h = h / 3 ) // h size will decrease
	{
		for( int i = h + 1 ; i <= n ; i++ ) // each number (in p array) will be compared
		{
			int v = p[i] ; // designate arr where far from compared value (as h size // p[a]    ~  p[a+h] <- designate v) 
			
			j = i ;
			
			while( j > h && p[j-h] > v ) // compare arr[A] with arr[A+h], and index j can't be negative number
			{
				p[j] = p[j-h] ; // if p[a] > p[a+h], change p[a] with p[a+h] that smaller number can be located in front
				j = j - h ; // and decrease j (as h size) that can be compared front number
			}

			p[j] = v ; // v go to p[j]
		}
	}
}

int main(void)
{
	clock_t start, stop ;

	int *p = new int[MAX+1] ; // Make array that the number of room is MAX

	srand((unsigned)time(NULL)) ; // Different values are occured at every time

	for( int i = 1 ; i <= MAX ; i++ )
	{
		p[i] = rand() ; // Put random number into p array
	}

	start = clock() ; // time start
	shellsort(p, MAX) ; // Execute shellsort
	stop = clock() ; // time stop

	cout << "12141680 Shell-Sort\n" << endl;
	
	print_elapsed(start, stop) ; // print elapsed time

	for( int i = 1 ; i <= MAX ; i++ )
	{
		cout << p[i] << " " ; // Print sorted all number in p array
	}

	cout << endl ;

	delete p ;

	return 0 ;
}