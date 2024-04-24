#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
#include<omp.h>
using namespace std;

void quicksort(int arr[], int st, int end)
{
    if(st < end)
    {
        int pivot = arr[end];
        int i = st-1;
        int j = st;

        for(int var = j; var<end; var++)
        {
            if(arr[var] < pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[var];
                arr[var] = temp;
            }
        }

        // swap i+1 and end
        int temp = arr[i+1];
        arr[i+1] = arr[end];
        arr[end] = temp;

        i++;

        #pragma omp parallel sections
        {
            #pragma omp section
            quicksort(arr,st,i-1);

            #pragma omp section
            quicksort(arr,i+1,end);
        }
    
    }

}

int main()
{
    int n;
    cout<<"Enter the number of elements: "; 
    cin>>n;

    int arr[n] = {0};
    for(int i=0; i<n; i++) arr[i] = rand()%30;

    cout<<"Array: ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;


    quicksort(arr,0,n-1);

    cout<<"Sorted Array: ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    return 0;
}

/*
Theory : 
1. Parallel quicksort is not cost optimal.

2. If partioing step is performed in time O(1) using O(n) process, then it is 
possible to get parallel runtime of O(log n)

3. Libraries Included:
- `<iostream>`: Input/output stream.
- `<bits/stdc++.h>`: Header file including all standard libraries.
- `<iomanip>`: Input/output manipulation.
- `<omp.h>`: OpenMP library for parallel programming.

4. Function: 
  - `arr[]`: The array to be sorted.
  - `st`: The starting index of the subarray.
  - `end`: The ending index of the subarray.

5. Algorithm:
  1. The function recursively sorts the subarray between indices `st` and `end`.
  2. It selects the last element of the subarray (`arr[end]`) as the pivot.
  3. It partitions the subarray into two sections: elements smaller than the pivot and 
  elements greater than or equal to the pivot.
  4. It swaps elements to place the pivot at its correct sorted position.
  5. It recursively calls itself in parallel for the left and right partitions of the 
  array using OpenMP sections.

6. Summary:
This code demonstrates the implementation of the Quick Sort algorithm with parallelization 
using OpenMP directives. Quick Sort is a widely-used sorting algorithm known for its 
efficiency, and parallelization enhances its performance, especially for large datasets. 

7 OpenMP Directives Used:
   **`#pragma omp parallel sections`**:
   - This directive initiates a parallel region where multiple sections of code can be 
   executed concurrently by different threads.
   - Within this parallel region, the subsequent code blocks marked with `#pragma omp section` 
   will be executed in parallel.

   **`#pragma omp section`**:
   - This directive specifies a section of code that will be executed concurrently 
   by one of the available threads within the parallel region

8. Benefits of OpenMP Parallelization:
- Reduce run time and improve the efficiency
*/

/*
1. Advantages of Quick Sort:
   - Less time and space compared to other sorting algorithms.
   - Simple implementation and ease of understanding.

2. OpenMP for Parallel Programming:
   - OpenMP is an API (Application Programming Interface) for parallel programming primarily 
   used with C, C++, and Fortran.
   - It facilitates parallel programming by providing compiler directives, runtime libraries, 
   and environment variables.
   - OpenMP allows developers to parallelize code easily by adding directives to 
   specify parallel regions, loop parallelization, and task parallelism.
   - It simplifies the creation and management of threads, enabling efficient u
   tilization of multicore processors and parallel computing resources.

3. OpenMP dynamically manages thread assignments to minimize idle time and 
maximize resource utilization.


4. Optimizations may include tuning the number of threads, minimizing synchronization overhead,
 optimizing memory access patterns, and implementing efficient partitioning strategies.

5. Thread synchronization refers to the coordination of multiple threads to ensure orderly 
and predictable execution of concurrent tasks. It involves controlling the access to 
shared resources or critical sections of code to prevent data races, ensure data consistency, 
and maintain program correctness. 

6. Addressing Issues such as Thread Synchronization Overhead and Resource Contention:
   - Techniques include minimizing critical sections, optimizing data access patterns, 
   reducing unnecessary thread synchronization, and ensuring efficient utilization of 
   hardware resources.

7. Alternative Parallelization Approaches or Frameworks for Sorting Algorithms:
   - Alternative approaches may include using MPI (Message Passing Interface) for 
   distributed memory systems, CUDA for GPU acceleration,

8. Time & Space complexity:
   Time Complexity:
  - Average Case: O(n log n)
  - Worst Case: O(n^2)

   Space Complexity:
  - Average: O(log n)
  - Worst: O(n)
  - Quick Sort's space complexity primarily depends on the depth of the recursion stack, 
  which corresponds to the number of recursive calls made during the sorting process.
  
*/

