#include <iostream>
#include <cstdlib>
#include <time.h>

#define MAX 524288 // 524288 = 2^19

using namespace std ;

void print_elapsed(clock_t start, clock_t stop)
{
	double elapsed = ((double)(stop - start)) / CLOCKS_PER_SEC ; // elapsed = how much time goes on
	cout << "Elapsed time : " << elapsed << "sec" << endl ; // print time (sec)
}

void change(int a[], int p, int q) // change among a[p] <-> a[q]
{
	int temp ;

	temp = a[p] ;
	a[p] = a[q] ;
	a[q] = temp ;
}

void MTQuickSort(int a[], int l, int r)
{
	int i, j, m, v ;
	if( r - l > 1 ) // if right > left
	{
		m = (l + r) / 2 ; // middle = (left + right) / 2
		
		if( a[l] > a[m] ) // if left > middle
		{
			change(a, l, m) ; // change left <-> middle
		}

		if( a[l] > a[r] ) // if left > right
		{
			change(a, l, r) ; // change left <-> right
		}

		if( a[m] > a[r] ) // if middle > right
		{
			change(a, m, r) ; // change middle <-> right
		}

		change(a, m, r-1) ; // change middle <-> right-1

		v = a[r-1] ;
		i = l ; // i = left index
		j = r - 1 ; // j = right-1 index

		for(;;)
		{
			while( a[++i] < v ) ; // left increase
			while( a[--j] > v ) ; // right decrease
			if( i >= j ) break ; // break if i>=j
			change(a, i, j) ; // change i <-> j
		}

		change(a, i, r-1) ; // change i <-> right-1
		MTQuickSort(a, l, i-1) ; // i-1 -> right
		MTQuickSort(a, i+1, r) ; // i+1 -> left

	}else if( a[l] > a[r] ) // if left > right
	{
		change(a, l, r) ; // change left <-> right
	}
}

int main()
{
	clock_t start, stop ;

	int *p = new int[MAX] ; // Make array that the number of room is MAX

	srand((unsigned)time(NULL)) ; // Different values are occured at every time

	for( int i = 0 ; i < MAX ; i++ )
	{
		p[i] = rand() ; // Put random number into p array
	}

	start = clock() ; // time start
	MTQuickSort(p, 0, MAX - 1) ; // execute MedianofThreeQuickSort
	stop = clock() ; // time stop

	cout << "12141680 MedianQuick-Sort\n" << endl ;

	print_elapsed(start, stop) ; // print elapsed time

	for( int i = 0 ; i < MAX ; i++)
	{
		cout << p[i] << " " ;
	}

	cout << endl ;

	delete p ;

	return 0 ;
}