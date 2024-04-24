#include <iostream>
#include <omp.h>
#include <climits>
using namespace std;
void min_reduction(int arr[], int n) {
  int min_value = INT_MAX;
  #pragma omp parallel for reduction(min: min_value)
  for (int i = 0; i < n; i++) {
	if (arr[i] < min_value) {
  	min_value = arr[i];
	}
  }
  cout << "Minimum value: " << min_value << endl;
}

void max_reduction(int arr[], int n) {
  int max_value = INT_MIN;
  #pragma omp parallel for reduction(max: max_value)
  for (int i = 0; i < n; i++) {
	if (arr[i] > max_value) {
  	max_value = arr[i];
	}
  }
  cout << "Maximum value: " << max_value << endl;
}

void sum_reduction(int arr[], int n) {
  int sum = 0;
   #pragma omp parallel for reduction(+: sum)
   for (int i = 0; i < n; i++) {
	sum += arr[i];
  }
  cout << "Sum: " << sum << endl;
}

void average_reduction(int arr[], int n) {
  int sum = 0;
  #pragma omp parallel for reduction(+: sum)
  for (int i = 0; i < n; i++) {
	sum += arr[i];
  }
  cout << "Average: " << (double)sum / (n-1) << endl;
}

int main() {
    int *arr,n;
    cout<<"\n enter total no of elements=>";
    cin>>n;
    arr=new int[n];
    cout<<"\n enter elements=>";
    for(int i=0;i<n;i++)
    {
   	 cin>>arr[i];
    }

//   int arr[] = {5, 2, 9, 1, 7, 6, 8, 3, 4};
//   int n = size(arr);

  min_reduction(arr, n);
  max_reduction(arr, n);
  sum_reduction(arr, n);
  average_reduction(arr, n);
}

/*
Output:
Method to run is 
unix@unix-HP-280-G1-MT:~/codes$ g++ -Fopenmp file_name.cpp -o file_name
unix@unix-HP-280-G1-MT:~/codes$ ./file_name

unix@unix-HP-280-G1-MT:~/codes$ g++ Para_merge.cpp
unix@unix-HP-280-G1-MT:~/codes$ g++ Min_max.cpp
unix@unix-HP-280-G1-MT:~/codes$ ./a.out

 enter total no of elements=>5

 enter elements=>2 3 4 5 2
Minimum value: 2
Maximum value: 5
Sum: 16
Average: 4


*/

/*

Theory : 

1. **`reduction(min: min_value)`**:
   - This clause specifies that each thread should have its private copy of the variable 
   `min_value`.
   - Inside the parallel loop, each thread independently finds the minimum value within 
   its assigned range of array elements.
   - After all threads complete their computations, OpenMP combines the thread-local 
   minimum values using the `min` operator to compute the final minimum value across all 
   threads.

2. **`reduction(max: max_value)`**:
   - Similar to the `min` clause, this clause specifies that each thread should have its 
   private copy of the variable `max_value`.
   - Inside the parallel loop, each thread independently finds the maximum value within 
   its assigned range of array elements.
   - After all threads complete their computations, OpenMP combines the thread-local 
   maximum values using the `max` operator to compute the final maximum value across 
   all threads.

3. **`reduction(+: sum)`**:
   - This clause specifies that each thread should have its private copy of the variable `sum`.
   - Inside the parallel loop, each thread independently calculates the partial sum of 
   array elements within its assigned range.
   - After all threads complete their computations, OpenMP combines the thread-local 
   partial sums by adding them together to compute the final sum across all threads.

4. **`reduction(+: sum)` for `average_reduction()`**:
   - Similar to the sum reduction, this clause specifies that each thread should have 
   its private copy of the variable `sum`.
   - Inside the parallel loop, each thread independently calculates the partial sum of 
   array elements within its assigned range.
   - After all threads complete their computations, OpenMP combines the thread-local 
   partial sums by adding them together to compute the final sum across all threads.
   - However, in the `average_reduction()` function, an additional step is taken to 
   compute the average by dividing the final sum by `(n-1)` (where `n` is the total number of elements in the array).

These OpenMP clauses ensure that each thread operates on its own private copy of the 
reduction variable, avoiding data races and ensuring correct results. 
After the parallel loop, OpenMP combines the thread-local results to compute the final reduction value.
*/

/*
1. **Purpose of OpenMP Clauses**: 
OpenMP clauses facilitate parallelization by providing directives for specifying how 
variables are shared or privatized among threads, allowing for efficient parallel execution.

2. **`reduction` Clause**: 
The `reduction` clause in OpenMP specifies that each thread should have a private 
copy of a variable, and the results from each thread are combined using a specified 
reduction operation (such as `min`, `max`, or `+`) to compute the final result.

3. **`min` Reduction**: In the provided code, the `min` reduction operation is 
implemented using the `reduction(min: min_value)` clause, where each thread finds its 
local minimum value, and these values are combined using the `min` operator to compute 
the final minimum value.

4. **`max` Reduction**: Similar to `min` reduction, the `max` reduction operation is 
performed using the `reduction(max: max_value)` clause, where each thread finds its local 
maximum value, and these values are combined using the `max` operator to compute the 
final maximum value.

5. **Sum Reduction**: OpenMP handles sum reduction using the `reduction(+: sum)` clause, 
where each thread calculates its local partial sum, and these partial sums are combined by 
adding them together to compute the final sum across all threads.

6. **`+` Reduction for Average**: In the `average_reduction()` function, the `reduction(+: sum)` clause is used to calculate the sum of array elements across all threads. The average is then computed by dividing the final sum by `(n-1)`.

7. **Advantages of OpenMP Reduction Clauses**: OpenMP reduction clauses simplify 
parallelization, ensure data consistency, and improve performance by handling synchronization
 and combining results automatically.

8. **Data Consistency**: OpenMP ensures data consistency during reduction operations 
by maintaining thread-local copies of reduction variables and combining the results in 
a controlled manner.

9. **Considerations for Parallelization**: Factors such as the size of the data, the 
number of available threads, and the overhead of parallelization should be considered 
when deciding to parallelize a loop using OpenMP reduction clauses.

10. **Efficiency**: The efficiency of reduction operations in OpenMP depends on factors such 
as the number of threads, the workload distribution, and the communication overhead between 
threads.

11. **Limitations and Pitfalls**: Common pitfalls include race conditions, improper variable 
scoping, and potential performance degradation due to excessive synchronization overhead.

12. **Performance Optimization**: Strategies for optimizing performance include load balancing,
 minimizing synchronization, and choosing appropriate reduction operations and chunk sizes.

13. **Non-Commutative Operations**: OpenMP handles non-commutative operations by ensuring 
proper order of operations during reduction, preserving data consistency across threads.

14. **Thread-Local Storage**: Thread-local storage refers to private copies of variables 
maintained by each thread, ensuring data isolation and preventing data races during 
parallel execution.

15. **Alternative Approaches**: Alternative approaches to parallel reduction include 
manual parallelization using threading libraries, GPU acceleration using CUDA or OpenCL, 
and distributed memory parallelism using MPI. These approaches may offer different 
trade-offs in terms of programming complexity, performance, and scalability.
*/