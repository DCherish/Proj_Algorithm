#include <iostream>
#include <cstdlib>
#include <time.h>

#define MAX 1048576 // 1048576 = 2^20
#define Asc 1 // Ascending order (1)
#define Des 0 // Descending order (0)

using namespace std ;

void print_elapsed(clock_t start, clock_t stop)
{
	double elapsed = ((double)(stop - start)) / CLOCKS_PER_SEC ; // elapsed = how much time goes on
	cout << "Elapsed time : " << elapsed << "sec" << endl ; // print time (sec)
}

class BTNSort
{
private :
	int *a = new int[MAX] ;

public :
	void cmp_swp(int a[], int i, int j, int dir) // compare and swap (in ascending or descending order)
	{
		int g = 0 ;
		int temp = 0 ;

		if( a[i] > a[j] ) // if now a[i] > a[j] (ex, 10 > 1 (Descending order))
		{
			g = 1 ; // g is 1
		}

		if( dir == g ) // if now -> descending order, but user's want order is Ascending order
		{
			temp = a[i] ;
			a[i] = a[j] ;
			a[j] = temp ; // so, swap each other, it will be ascending order
		}
	}

	/// BitonicSort -> do bitonicSort & bitonicMerge

	void bitonicMerge(int a[], int low, int cnt, int dir) // bitonicMerge
	{
		if( cnt > 1 )
		{
			int k = cnt / 2 ;
			for( int i = low ; i < low + k ; i++ )
			{
				cmp_swp(a, i, i + k, dir) ;
			}
			bitonicMerge(a, low, k, dir) ;
			bitonicMerge(a, low + k, k, dir) ;
		}
	}

	void bitonicSort(int a[], int low, int cnt, int dir) // bitonicSort
	{
		if( cnt > 1 )
		{
			int k = cnt / 2 ;

			bitonicSort(a, low, k, Asc) ;
			bitonicSort(a, low + k, k, Des) ;
			bitonicMerge(a, low, cnt, dir) ;
		}
	}

	void sort(int a[], int N, int dir)
	{
		bitonicSort(a, 0, N, dir) ; // sort in user's want order (now, user's want order -> Asc, so dir = Asc)
	}
} ;

int main()
{
	clock_t start, stop;

	int *p = new int[MAX] ; // Make array that the number of room is MAX

	srand((unsigned int)time(NULL)) ;; // Different values are occured at every time

	for( int i = 0 ; i < MAX ; i++ ) // put random number into array
	{
		p[i] = rand() ;
	}

	BTNSort Bit ;

	start = clock() ; // time start
	Bit.sort(p, MAX, Asc) ; // execute BitonicSort (Ascending order)
	stop = clock() ; // time stop

	cout << "12141680 Bitonic-Sort\n" << endl ;

	print_elapsed(start, stop) ; // print elapsed time
	
	for( int i = 0 ; i < MAX ; i++ )
	{
		cout << p[i] << " " ; // Print sorted all number in p array
	}

	cout << endl ;

	delete p ;
	
	return 0 ;
}