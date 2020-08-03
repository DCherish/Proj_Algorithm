#include<cuda.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<cuda_runtime.h>

using namespace std ;

#define THREADS 512 // 2^9
#define BLOCKS 2048 // 2^11
#define NUM_VALS THREADS*BLOCKS // 2^20

void print_elapsed(clock_t start, clock_t stop)
{
	double elapsed = ((double)(stop - start)) / CLOCKS_PER_SEC ; // elapsed = how much time goes on
	cout << "Elapsed time : " << elapsed << "sec" << endl ; // print time (sec) ;
}

int random_int()
{
	return (int)rand() ; // return random number
}

void array_print(int *arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << arr[i] << " " ; // print sorted number
	}

	cout << endl ;
}

void array_fill(int *arr, int length)
{
	srand(unsigned(time(NULL))) ; // it occurs each random number at every each time

	for( int i = 0 ; i < length ; ++i )
	{
		arr[i] = random_int() ; // put random number into array
	}
}

__global__ void bitonic_sort_step(int *dev_values, int j, int k) // bitonicSorting
{
	unsigned int i, itj ; // Sorting partners, i and itj and it can't be negative number
	i = threadIdx.x + blockDim.x * blockIdx.x ;
	itj = i^j ;

	if( (itj) > i )
	{
		if( (i&k) == 0 ) // Sort ascending
		{
			if( dev_values[i] > dev_values[itj] ) // if v[i] > v[itj]
			{
				int temp = dev_values[i] ;
				dev_values[i] = dev_values[itj] ;
				dev_values[itj] = temp ; // exchange(i,itj) 
			}
		}

		if( (i&k) != 0 )// Sort descending 
		{
			if( dev_values[i] < dev_values[itj] ) // if v[i] < v[itj]
			{
				int temp = dev_values[i] ;
				dev_values[i] = dev_values[itj] ;
				dev_values[itj] = temp ; // exchange(i,itj)
			}
		}
	}
}

void bitonic_sort(int *values) // bitonicSort
{
	int *dev_values ;
	size_t size = NUM_VALS * sizeof(int) ;

	cudaMalloc((void**)&dev_values, size) ; // using cuda memory allocation
	cudaMemcpy(dev_values, values, size, cudaMemcpyHostToDevice) ; // using cuda copy values -> dev_values (size) // Host to Device

	dim3 blocks(BLOCKS, 1) ; // Number of blocks  
	dim3 threads(THREADS, 1) ; // Number of threads

	int j, k ; // in device, do sort

	for( k = 2 ; k <= NUM_VALS ; k <<= 1 )
	{
		for( j = k >> 1 ; j > 0 ; j = j >> 1 )
		{
			bitonic_sort_step << <blocks, threads >> >(dev_values, j, k) ;
		}
	}
	cudaMemcpy(values, dev_values, size, cudaMemcpyDeviceToHost) ; // using cuda copy dev_values -> values (size) // Device to Host
	cudaFree(dev_values) ; // free memory
}

int main(void)
{
	clock_t start, stop ;

	int *values = (int*)malloc(NUM_VALS * sizeof(int)) ; // dynamic memory allocation

	array_fill(values, NUM_VALS) ; // execute array fill (put random number into array)

	start = clock() ; // time start
	bitonic_sort(values) ; // execute bitonic sort
	stop = clock() ; // time stop

	cout << "12141680 GPU Binotic-Sort\n" << endl ;

	print_elapsed(start, stop) ; // print elapsed time

	cout << endl ;

	array_print(values, NUM_VALS) ; // print sorted number

	delete values;
}