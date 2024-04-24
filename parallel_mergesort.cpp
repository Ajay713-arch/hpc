#include<iostream>
#include<cstdlib>
#include<omp.h>
#include<time.h>
using namespace std;

void merge(int array[],int low1, int high1,int low2,int high2, int n)
{
	int temp[n];
	int i=low1,j=low2,k=0;
	
	while(i<=high1 && j<=high2)
	{
		if(array[i]<array[j])
			temp[k++]=array[i++];
		else
			temp[k++]=array[j++];
	}
	
	while(i<=high1)
		temp[k++]=array[i++];
	
	while(j<=high2) 
		temp[k++]=array[j++];
		
	for(i=low1,j=0;i<=high2;i++,j++)
		array[i]=temp[j];
}

void mergesort(int array[], int low, int high, int n)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		#pragma omp parallel sections
		{
			#pragma omp section
			{
				mergesort(array,low,mid,n);
			}
			
			#pragma omp section
			{
				mergesort(array,mid+1,high,n);
			}
			
		}
		
        merge(array,low,mid,mid+1,high,n);


		// mergesort(array,low,mid,n);
		// mergesort(array,mid+1,high,n);
		// merge(array,low,mid,mid+1,high,n);
	}
}

void display(int array[], int n)
{
	for(int i=0;i<n;i++) cout<<array[i]<<" ";
}


int main()
{
	int n;
	cout<<"Enter the number of elements : ";
	cin>>n;
	
    int array[n] = {0};

	for(int i=0;i<n;i++)
	{
		array[i]=rand()%32;
	}
	
	cout<<"Original Array: ";
	display(array,n);
	cout<<endl;
	
	clock_t start = clock();
	mergesort(array,0,n-1,n);
	clock_t stop = clock();
	
	cout<<"Final Array: ";
	display(array,n);
	cout<<endl;

	cout<<"Time required : "<<(double)(stop-start)*1000/CLOCKS_PER_SEC<<" ms";
	
    return 0;
}

/*
PS D:\C++> g++ -fopenmp parallel_merge.cpp
PS D:\C++> ./a out
Enter the number of elements : 10
Original Array: 9 3 30 4 1 12 22 14 18 16 
Final Array: 1 3 4 9 12 14 16 18 22 30 
Time required : 0 ms
*/

/*
1. Parallelism:
   - Parallelism is the concept of performing multiple tasks simultaneously, 
   leveraging the capabilities of multiple processing units. 

2. OpenMP:
   - OpenMP is an API (Application Programming Interface) for parallel programming primarily 
   used in shared-memory multiprocessing environments.
   - It simplifies parallel programming by providing compiler directives, library routines, 
   and environment variables.

3. `merge()` Function:
   - The `merge()` function merges two sorted subarrays into a single sorted array.
   - It works by comparing elements from both subarrays and copying them into a 
   temporary array in sorted order.
   - Finally, it copies the sorted elements from the temporary array back into the 
   original array.

4. OpenMP in `mergesort()`:
   - OpenMP is used with `#pragma omp parallel sections` in the `mergesort()` function 
   to parallelize the sorting of the left and right halves of the array.
   - This facilitates parallelism by dividing the sorting task into independent sections 
   that can be executed concurrently by multiple threads.

5. Advantages and Disadvantages of OpenMP Parallelization:
   - Advantages: Improved performance by utilizing multiple processor cores, 
   scalability to different hardware configurations.
   - Disadvantages: Increased complexity, potential for overhead due to thread management, 
   and synchronization.

6. Precautions for Avoiding Race Conditions:
   - Ensure that shared data is protected using mechanisms like critical sections, 
   atomic operations, or locks.
   - Minimize the use of global variables to reduce the risk of race conditions.
   - Carefully analyze and design parallel algorithms to minimize dependencies among threads.

7. Optimizations for Parallel Merge Sort:
   - Load balancing
   - Cache optimization:
   - Fine-grained parallelism

8. Alternative Approaches to Parallelizing Merge Sort:
   - Task parallelism: Divide the sorting task into smaller tasks that can be executed concurrently by multiple threads or processes.
   - Distributed memory parallelism: Utilize message passing interfaces (MPI) to distribute data across multiple nodes in a cluster for parallel processing.
   - GPU parallelism: Offload the sorting task to graphics processing units (GPUs) for parallel execution using frameworks like CUDA or OpenCL.

*/

/*
1. `merge()` function:
   - This function merges two sorted subarrays into a single sorted array.
   - It takes six parameters: the array, indices of the low and high points of the 
   first subarray, indices of the low and high points of the second subarray, and the 
   size of the array.
   - It creates a temporary array `temp[]` to store the merged result.
   - It iterates through both subarrays and compares elements, copying them to `temp[]` 
   in sorted order.
   - Finally, it copies the sorted elements from `temp[]` back to the original array.

2. `mergesort()` function:
   - This function implements the merge sort algorithm recursively.
   - It takes four parameters: the array, indices of the low and high points of the 
   current subarray, and the size of the array.
   - It recursively divides the array into halves until the subarrays have only one element.
   - OpenMP directives are used to parallelize the sorting of the left and right halves 
   of the array (`#pragma omp parallel sections`).
   - After sorting both halves, the `merge()` function is called to merge the sorted halves.

3. Time & Space complexity :

**Space Complexity**:
   - O(n)
   - Parallel merge sort requires additional space for temporary arrays and potentially 
   for managing threads and synchronization. While the space complexity for temporary 
   arrays remains O(n), the overhead introduced by parallelism can vary depending on 
   the implementation and platform.


 **Time Complexity**:
   - Best Case: O(n log n)
   - Average Case: O(n log n)
   - Worst Case: O(n log n)
   - Parallel Merge Sort can achieve a time complexity of O(log n) in ideal conditions 
   with an unlimited number of processors.
*/

/*
CUDA stands for Compute Unified Device Architecture. It is a parallel computing platform
 and programming model developed by NVIDIA for enabling general-purpose processing on 
 NVIDIA GPUs (Graphics Processing Units). CUDA allows developers to harness the massive 
 parallel computing power of GPUs to accelerate computations in various domains such as 
 scientific simulations, deep learning, image processing, and more.

1. Parallel Computing Model:

2. CUDA Toolkit: The CUDA Toolkit includes a compiler, runtime libraries, debugging tools, 
			  and development libraries necessary for CUDA programming. 
	        It provides an integrated development environment for writing, compiling, 
			  and debugging CUDA applications.

3. Unified Memory: CUDA introduced unified memory, which allows the CPU and GPU to share 
a single address space. 
*/