
/*
Theory : 

1. Breadth-First Search (BFS):
   - BFS is a graph traversal algorithm that explores nodes in levels, starting from the 
   root node and moving to adjacent nodes before traversing deeper.
   
2. Data Structure in BFS:
   - queue (FIFO) ensuring all nodes are visited 

3. BFS and Shortest Path:
   - BFS guarantees the shortest path in an unweighted graph by exploring nodes level by level.


6. OpenMP:
   - OpenMP is an API for parallel programming that provides directives for parallelizing code 
   across multiple threads. It simplifies parallel programming by adding pragmas to C/C++ code.

7. Parallelization with OpenMP:
   - Parallelization in this code is achieved using the `#pragma omp parallel for` directive, 
   which distributes the loop iterations among multiple threads, speeding up the BFS traversal.


8. Benefits of Parallelizing BFS:
   - Parallelizing BFS can significantly reduce traversal time, especially for large graphs 
   with many vertices and edges. It's useful in scenarios where performance is crucial and 
   when exploiting multiple CPU cores can provide speedups.

9. Execution Time Measurement:
   - The program measures execution time using clock ticks (`clock_t`). It records the 
   starting time before BFS traversal begins and the ending time after traversal completes, 
   calculating the difference to determine the elapsed time.

10. Optimizations:
   - Possible optimizations include using more efficient data structures, such as an 
   adjacency list instead of an adjacency matrix, and optimizing memory access patterns 
   to reduce cache misses.

11. Limitations of Implementation:
    - This implementation's main limitations lie in its memory usage, particularly for 
	large graphs, as it utilizes an adjacency matrix which consumes memory proportional 
	to the square of the number of vertices. Additionally, it doesn't handle disconnected graphs or cycles.

12. Handling Disconnected Graphs or Cycles:
    - To handle disconnected graphs, you could modify the BFS function to start from any 
	unvisited vertex and perform BFS until all vertices are visited. For cycles, you could 
	implement cycle detection mechanisms to avoid infinite loops.

13. Time complexity & Space complexity:
  - Time complexity of BFS in a serial & parallel execution is \( O(V + E) \).
  - Parallelization using OpenMP doesn't change the fundamental time complexity of the algorithm.  
    However, parallel execution may reduce the time by distributing the workload among 
	multiple threads, but the overall computational complexity remains unchanged.

  - Space complexity in serial & parallel execution is ( O(V)) for storing the `visit` array 
  and  O(V^2) for the adjacency matrix and for queue in BFS traversal O(V)

  - Space complexity for adjacenecy list is O(V+E)

### Extra : 
  - `<omp.h>`: OpenMP library for parallel programming.
  - `queue<int> q`: A queue to store vertices during BFS traversal.
  - `start`: Starting vertex for BFS traversal.
  - `arr`: Pointer to the adjacency matrix representing the graph.
  - `n`: Number of vertices in the graph.
  - `visit[]`: Array to keep track of visited vertices.

### Function `bfs` (Continued):
- The function traverses the graph in BFS manner starting from the vertex `start`.
- It uses OpenMP parallelization (`#pragma omp parallel for ordered`) to parallelize 
  the loop over vertices.

### Adjacency matrix :

- Advantages :
1. Simplicity 
2. Constant Time Edge Queries: With an adjacency matrix, determining whether an edge exists between two vertices can be done in constant time (O(1).
3. Space Efficiency for Dense Graphs 

- Disadvantages : 
1. Space Inefficiency for Sparse Graphs
2. Inefficient for Dynamic Graphs
3. Cache Inefficiency*

### Adjacency list : 

- Advantages:
1. Space Efficiency for Sparse Graphs: 
2. Efficient Iteration Over Neighbors: 
3. Dynamic Graphs: Adjacency lists are well-suited for dynamic graphs where edges are frequently added or removed.

- Disadvantages:
1. Space Inefficiency for Dense Graphs: In dense graphs, where most vertices are connected to many other vertices, adjacency lists can be less space-efficient compared to adjacency matrices. 
2. Slower Edge Existence Checking: Determining whether an edge exists between two vertices time complexity of (O(V)
3. Less Cache-Friendly

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

/*
Theory : 

1. DFS: Depth-First Search (DFS) is a graph traversal algorithm that explores as far 
as possible along each branch before backtracking. It starts at a selected node and 
explores as far as possible along each branch before backtracking.

2. Difference between DFS and BFS:
   - DFS explores as far as possible along each branch before backtracking, while BFS 
   explores neighbor nodes before moving to the next level.
   - DFS typically uses a stack for traversal, whereas BFS uses a queue.
   - BFS is generally more suitable for finding shortest paths in unweighted graphs, 
   while DFS is useful for tasks like topological sorting and finding connected components.

3. DFS Traversal:
   - DFS explores a graph by recursively traversing each branch as deeply as possible.
   - It commonly uses a stack data structure for implementation, either explicitly 
   or through recursion.

4. Recursion in DFS:
   - Recursion is utilized in the DFS function to explore each adjacent vertex of the 
   current vertex.
   - When exploring an adjacent vertex, DFS recursively calls itself with the adjacent 
   vertex as the new starting point.

5. Benefits of Parallelizing DFS:
   - Parallelizing DFS using OpenMP can potentially speed up traversal for large graphs
    by distributing workload among multiple threads.
   - It can leverage multi-core processors to explore different branches of the graph
    concurrently.

6. Considerations for Parallelizing DFS:
   - When parallelizing DFS, careful synchronization is needed to ensure correctness, 
   especially when updating shared data structures like visited vertices.
   - Load balancing may be a concern to ensure that work is evenly distributed among threads.

6. OpenMP:
   - OpenMP is an API for parallel programming that provides directives for parallelizing code 
   across multiple threads. It simplifies parallel programming by adding pragmas to C/C++ code.

7. Limitations of Implementation:
   - High space compleity O(V^2) also  not efficient in handling disconnected graphs or cycles.

8. Handling Disconnected Graphs or Cycles:
   - To handle disconnected graphs, the program could modify the DFS function to start 
   from unvisited vertices until all vertices are visited.
  
10. Adjacency Matrix Representation:
    - An adjacency matrix is chosen for its simplicity and ease of implementation.
    - Advantages include constant-time lookup for edge existence and straightforward 
    representation of dense graphs.
    - Disadvantages include high memory usage for sparse graphs and inefficiency in 
    storing large graphs due to its \(O(V^2)\) space complexity.

11. Time & Space Complexity :
  - Time complexity of DFS in a serial & parallel execution is O(V + E). 
  - In summary, while parallelizing DFS doesn't alter the time or space complexity of the 
  algorithm itself. The primary benefits of parallelization lie in improved performance 
  through concurrency and better utilization of computational resources.

  - Space complexity in serial & parallel execution is O(V^2) for the adjacency matrix and O(V) 
  for the visited array and stack used for DFS traversal.
  - The space complexity of DFS remains O(V + E) when using an adjacency list representation 
  for the graph

### Adjacency matrix :

- Advantages :
1. Simplicity 
2. Constant Time Edge Queries: With an adjacency matrix, determining whether an edge exists between two vertices can be done in constant time (O(1).
3. Space Efficiency for Dense Graphs 

- Disadvantages : 
1. Space Inefficiency for Sparse Graphs
2. Inefficient for Dynamic Graphs
3. Cache Inefficiency*

### Adjacency list : 

- Advantages:
1. Space Efficiency for Sparse Graphs: 
2. Efficient Iteration Over Neighbors: 
3. Dynamic Graphs: Adjacency lists are well-suited for dynamic graphs where edges are frequently added or removed.

- Disadvantages:
1. Space Inefficiency for Dense Graphs: In dense graphs, where most vertices are connected to many other vertices, adjacency lists can be less space-efficient compared to adjacency matrices. 
2. Slower Edge Existence Checking: Determining whether an edge exists between two vertices time complexity of (O(V)
3. Less Cache-Friendly

*/


/*
Dense Matrix - a matrix in which there are minimum no.of zeros

Matrix Vector Multiplication (Row wise 1D partitioning) - 
1. One row per process
2. All to all broadcast
3. Computation
4. Result
5. Process time product is O(N^2)
6. It is cost optimal 

Matrix Vector Multiplication (Row wise 1D partitioning) - 
1. One element per process
2. One to one communication
3. One to all broadcast
4. All to one reduction
5. Process time product is O(n^2 logn)
6. It is not cost optimal as for sequential O(n^2)



Matrix-Vector Multiplication: 
   - Parallelizes the matrix-vector multiplication using OpenMP.
   - Uses a parallel loop (`#pragma omp parallel for`) to distribute the 
   rows of the matrix among multiple threads.
   - Inside the parallel region, another parallel loop is used to compute 
   the element-wise product of each row of the matrix and the vector.
   - Each thread computes the partial sum of the products using a reduction 
   clause (`reduction(+: sum)`) to ensure correct summation across threads.
   - The resulting partial sums are stored in the output vector `rvec`.

Partitioning Analysis:
- This code uses 1D partitioning because it distributes the rows of the 
matrix among multiple threads. 
Each thread computes the products of a subset of rows with the vector and 
accumulates the partial sums independently. 
*/
/*
1. Purpose of OpenMP: OpenMP is used to parallelize the matrix-vector 
multiplication algorithm, allowing it to run faster by utilizing multiple 
threads.

2. OpenMP Facilitation: OpenMP provides directives for parallelization 
(`#pragma omp`) and clauses for managing parallel execution, such as 
reduction.

3. Significance of `#pragma omp parallel for`: It parallelizes the outer 
loop of the matrix-vector multiplication algorithm, distributing row 
computations among multiple threads.

4. 1D Partitioning: The operation is parallelized using 1D partitioning 
because it distributes the rows of the matrix among threads, with each 
thread handling a subset of rows.

5. Reduction Clause: The `reduction(+: sum)` clause ensures correct 
summation of partial results across threads during the computation of 
the matrix-vector multiplication.

7. Drawbacks of 1D Partitioning: Overhead and potential load imbalance 
may occur with 1D partitioning, limiting scalability and performance gains.

8. Optimal Thread Count: The optimal number of threads depends on factors 
like the hardware configuration, size of the matrices, and overhead of 
parallelization.

9. Considerations for Parallelization: Factors include matrix size, 
available resources, communication overhead, and potential load balancing 
issues.

11. Data Dependency Management: Data dependencies are managed by 
ensuring that each thread operates on independent portions of the matrices
 and vector, avoiding conflicts.

14. Hardware Considerations: Different hardware architectures may have
 varying capabilities and constraints, impacting performance and 
 scalability of OpenMP parallelization.
*/

/*
1. Issues in sorting of Parallel computers ? 
- where the i/p and o/p is stored 
- how comparisons are performed

2. Sorting in parallel computer :
	1. One element per process
	2. many elements per process


3. Sources of overhead in parallel computing :
	1. inter process communication
	2. ideal
	3. excess computation - redundancy 

4. Speedup = Execution Time (Sequential) / Execution Time (Parallel)

5. In parallel computing, scaling down refers to the process of using fewer processors than the maximum available or designed for a particular program.
   It's essentially the opposite of scaling up, which aims to leverage more processors for increased performance.
	1. Communication decreases by a factor N/P
	2. Compuation increases by a factor N/P 

6. Granularity plays a crucial role in the performance of parallel systems. It refers to the size or amount of work assigned to each individual task within the parallel program


7. Fine-grained: This refers to a system with many small, well-defined components. Each component handles a specific task or holds a smaller amount of data. Fine-grained systems offer greater control and flexibility but can be more complex to manage due to the numerous parts involved.

8. Coarse-grained: This refers to a system with fewer, larger components. Each component handles broader functionalities or holds more data. Coarse-grained systems are generally simpler to manage but might lack the detailed control offered by fine-grained approaches.

9. CUDA stands for Compute Unified Device Architecture. It is a parallel computing platform
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

/*
Matrix Multiplication: 

   - Performs matrix multiplication and stores the result in `mat3`.
   - Declares `mat3` as the result matrix with dimensions `row1 x col2`.
   - Parallelizes the matrix multiplication using OpenMP with the 
   outer loop (`#pragma omp parallel for`) to distribute rows among threads.
   - Inside the parallel region, another parallel region is used for 
   iterating over columns of the result matrix (`mat3`).
   - Within the inner parallel region, each element of the result 
   matrix (`mat3[i][j]`) is computed by multiplying corresponding elements 
   from `mat1` and `mat2`, and then summing them up.
   - Reduction clause (`reduction(+: sum)`) is used to compute the 
   sum of products in parallel, ensuring correct results across threads.

5. **Sum Reduction**: OpenMP handles sum reduction using the `reduction(+: sum)` clause, 
where each thread calculates its local partial sum, and these partial sums are combined by 
adding them together to compute the final sum across all threads.


*/
/*
1. Significance of `#pragma omp parallel for`: It parallelizes the outer loop
 of the matrix multiplication algorithm, distributing row computations among
  multiple threads.

2. Nested Parallel Regions: Nested parallel regions are used to parallelize 
the computation of individual elements in the result matrix, maximizing 
parallelism.

3. Reduction Clause: The `reduction(+: sum)` clause ensures correct 
computation of element-wise sums across threads during matrix multiplication.

4. Drawbacks of Nested Parallelism: Overhead and resource contention may 
occur with nested parallelism, potentially reducing performance gains.

5. Optimal Thread Count: The optimal number of threads depends on factors 
like the hardware configuration and the size of the matrices.

6. Considerations for Parallelization: Factors include the size of matrices, 
the number of available processing cores, and the overhead of parallelization.

7. Data Dependencies: Data dependencies are managed by ensuring that each 
thread operates on independent portions of the matrices, avoiding conflicts.

8. Performance Optimization: Strategies include load balancing, minimizing 
synchronization overhead, and optimizing memory access patterns.

9. Handling Larger Matrices: Use efficient memory management techniques 
and optimize the parallelization strategy to handle larger matrices.

10. Challenges on Different Architectures: Considerations include 
differences in thread management, memory access patterns, and hardware 
capabilities.

11. Pitfalls to Avoid: Pitfalls include excessive overhead from nested 
parallelism, incorrect synchronization, and improper load balancing.
*/

/*
In summary, the time complexity of the matrix multiplication algorithm 
remains O(n^3), and the space complexity is O(n^2)
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

