#include<cuda.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<cuda_runtime.h>

using namespace std ;

#define THR 512 // 2^9
#define BLK 2048 // 2^11
#define NUM BLK*THR // 2^20

void print_elapsed(clock_t start, clock_t stop)
{
	double elapsed = ((double)(stop - start)) / CLOCKS_PER_SEC ; // elapsed = how much time goes on
	cout << "Elapsed time : " << elapsed << "sec" << endl ; // print time (sec) ;
}

__global__ void oddeven(int *arr, int cond)
{
	int index = blockIdx.x * blockDim.x + threadIdx.x ;
	int temp ;
	if (index >= (NUM / 2) - 1 && cond % 2 != 0) return ;

	if( cond % 2 == 0 ) // if cond is even
	{
		if( arr[index * 2] > arr[index * 2 + 1] ) // compare arr[0]<->arr[1], arr[2]<->arr[3], ... // (0, 2, 4, ... even)
		{
			temp = arr[index * 2] ;
			arr[index * 2] = arr[index * 2 + 1] ;
			arr[index * 2 + 1] = temp ; // if arr[0] > arr[1], arr[2] > arr[3], ... change each other
		}
	}
	else // if cond is odd
	{
		if( arr[index * 2 + 1] > arr[index * 2 + 2] ) // compare arr[1]<->arr[2], arr[3]<->arr[4], ... (1, 3, 5, ... even)
		{
			temp = arr[index * 2 + 1] ;
			arr[index * 2 + 1] = arr[index * 2 + 2] ;
			arr[index * 2 + 2] = temp ; // if arr[1] > arr[2], arr[3] > arr[4], ... change each other
		}
	}
}

int main()
{
	clock_t start, stop ;

	int *values ;
	int *deva_values ;
	int i ;
	int size = sizeof(int) * NUM ;

	values = (int *)malloc(size) ; // dynamic memory allocation

	cudaMalloc((void **)&deva_values, size) ; // using cuda memory allocation

	srand(unsigned(time(NULL))) ; // it occurs each random number at every each time

	for (i = 0; i < NUM; i++)
	{
		values[i] = rand(); // put random number into array
	}

	cudaMemcpy(deva_values, values, size, cudaMemcpyHostToDevice) ; // using cuda copy value -> dev_values (size) // Host to Device

	start = clock() ; // time start

	for (i = 0; i < NUM; i++)
	{
		oddeven << <NUM / 1024, 512 >> >(deva_values, i) ; //512 threads per block and total N/2/512 blocks
	}

	stop = clock() ; // time stop

	cudaMemcpy(values, deva_values, size, cudaMemcpyDeviceToHost) ; // using cuda copy dev_values -> values (size) // Device to Host

	cout << "12141680 GPU OddEven-Sort\n" << endl ;

	print_elapsed(start, stop) ; // print elapsed time

	cout << endl ;

	for (i = 0; i<NUM; i++)
	{
		printf("%d ", values[i]) ; // print sorted number
	}

	cudaFree(deva_values) ; // free memory

	delete values ;

	return 0;
}