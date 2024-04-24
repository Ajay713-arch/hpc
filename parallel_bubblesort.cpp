#include<omp.h>
#include<iostream>
#include<time.h>
using namespace std;
int main()
{

	// freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
	
	int n;
	cout<<"Enter the number of elements : ";
	cin>>n;
	cout<<endl;

	int array[n] = {0};

	for(int i=0;i<n;i++) array[i]=rand()%32;
	
	cout<<"Original Array: ";
	for(int i=0; i<n; i++) cout<<array[i]<<" ";
	cout<<endl;
	
	clock_t start=clock();
	int var = 0;

	for(int i=0; i<n; i++)
	{
		#pragma omp parallel for
		for(int j=var; j<n-1; j+=2)
		{
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
		
		if(var == 0) var = 1;
		else var = 0;

	}	

	clock_t stop=clock();
	
	
	cout<<"\nFinal Array: ";
	for(int i=0; i<n; i++) cout<<array[i]<<" ";
	cout<<endl;	
	
	cout<<"\nTime required : "<<(double)(stop-start)<<" ms"<<endl;
	return 0;
}

// 5 minute example : form pair with immediate right adjacent and compare if small swap
// 3 2 3 8 5 6 4 1 // start index from 1 to 8 // if single element in pair leave 

/*
PS D:\C++> g++ -fopenmp parallel_bub.cpp
PS D:\C++> ./a out
Enter the number of elements : 15

Original Array: 9 3 30 4 1 12 22 14 18 16 9 17 17 27 9 

Final Array: 1 3 4 9 9 9 12 14 16 17 17 18 22 27 30 

Time required : 0 ms

*/

/*
Theory : 

1. Bubble sort is stable and we can make it adaptive(i.e both min-O(n) & max-O(n^2) 
   time complexity)

2. While parallelization may lead to faster sorting times in practice, it does not 
   alter the fundamental time and space complexity characteristics of the Bubble Sort algorithm.
   - Best Case: (O(n)
   - Average Case: (O(n^2)
   - Worst Case: O(n^2)
   - Both sequential and parallel implementations of Bubble Sort have a 
    space complexity of O(1) since they do not require any additional data structures
	proportional to the size of the input array.

3. Libraries Included:
	`<omp.h>`: OpenMP library for parallel programming.
	`<iostream>`: Input/output stream.
	`<time.h>`: Header for time-related functions.

4. **Bubble Sort Algorithm**:
   - Starts a clock to measure execution time.
   - Uses a variable `var` to alternate between odd and even passes of the Bubble Sort 
   algorithm.
   - In each pass:
    - Parallel loop using `#pragma omp parallel for` to distribute the work among 
	multiple threads. Each thread performs the comparison and swapping of adjacent elements.
    - If an element at an even index (`array[j]`) is greater than the next element 
	(`array[j+1]`), they are swapped.
    - After each pass, toggles the value of `var` to switch between odd and even passes.
    - Stops the clock after sorting is complete.

5. Summary:
   This code demonstrates the parallel implementation of the Bubble Sort algorithm 
   using OpenMP directives, which allows for parallelization of the sorting process. 
   However, more efficientsorting algorithms like Quick Sort or Merge Sort 
   are commonly preferred for large datasets due to their better time complexity 
   characteristics.
 
6. Parallel Sorting:
   - Within each pass, the sorting process is parallelized using OpenMP directives.
   - A parallel loop is started using `#pragma omp parallel for`, which distributes 
   the work among multiple threads. Each thread performs the comparison and swapping 
   of adjacent elements.
   
7. Benefits of Odd-Even Bubble Sort:
   - Odd-even Bubble Sort is suitable for parallelization because it divides the sorting 
   process into independent phases (odd-phase and even-phase), allowing parallel execution.
   - Parallelization can lead to improved performance, especially for larger arrays, 
   by utilizing multiple processor cores effectively.

8. Limitations:
   - While parallelization can improve performance, the overhead associated with managing 
   threads and synchronization may affect the efficiency of the algorithm, particularly 
   for small arrays.
   - Bubble Sort, including its parallel version, has a time complexity of O(n^2), making it 
   inefficient for large datasets compared to more efficient sorting algorithms like 
   Quick Sort or Merge Sort.

*/
/*
Extra : 
1. OpenMP Directives:
   - OpenMP is an API for parallel programming. `#pragma omp parallel for` 
   directive distributes loop iterations among threads. There may be overheads 
   and issues related to thread management and synchronization.

2. Odd-Even Bubble Sort:
   - Odd-even Bubble Sort compares and swaps adjacent elements in two phases: odd and even.
   It's suitable for parallelization because it divides the sorting process into 
   independent phases.

3. Optimizations and Alternatives:
   - Optimization ideas may include reducing synchronization overhead and optimizing 
   memory access patterns. 

4. Use Cases and Considerations:
   -  Factors to consider include dataset size, hardware resources, and desired sorting speed.

5. Real-world Applications:
    - Data analytics, scientific computing, and financial analysis, where sorting 
	large datasets efficiently is crucial.

6. Issues and Overhead:
   - Potential issues include overhead from thread creation, synchronization, and 
   managing parallel execution.

7. Limitations and Bottlenecks:
   - Scalability may be limited by factors such as memory bandwidth, cache contention,
    synchronization overhead and no.of processors
*/
