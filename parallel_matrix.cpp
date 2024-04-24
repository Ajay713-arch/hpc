#include<iostream>
#include<omp.h>
#include<math.h>
using namespace std;
int main()
{
    cout<<"Number of rows in first matrix: ";
    int row1;
    cin>>row1;

    cout<<"Number of columns in first matrix: ";
    int col1;
    cin>>col1;

    int row2 = col1;

    cout<<"Number of columns in second matrix: ";
    int col2;
    cin>>col2;

    cout<<endl;
    cout<<"Matrix 1:"<<endl;
    int mat1[row1][col1];
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col1; j++)
        {
            mat1[i][j] = rand()%10;
            cout<<mat1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"Matrix 2:"<<endl;
    int mat2[row2][col2];
    for(int i=0; i<row2; i++)
    {
        for(int j=0; j<col2; j++)
        {
            mat2[i][j] = rand()%10;
            cout<<mat2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"Multiplication: "<<endl;
    int mat3[row1][col2];
    #pragma omp parallel for
	for(int i=0;i<row1;i++)
	{
		#pragma omp parallel for
		for(int j=0;j<col2;j++)
		{
			mat3[i][j]=0;
            int arr[col1];

            #pragma omp parallel for
			for(int k=0;k<col1;k++) arr[k] = mat1[i][k]*mat2[k][j];

            int sum = 0;
            #pragma omp parallel for reduction(+: sum)
            for (int l = 0; l < col1; l++) sum += arr[l];

            mat3[i][j] = sum;
		}
	}

    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col2; j++) cout<<mat3[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
/*
Number of rows in first matrix: 5
Number of columns in first matrix: 5
Number of columns in second matrix: 6

Matrix 1:
1 7 4 0 9
4 8 8 2 4
5 5 1 7 1
1 5 2 7 6
1 4 2 3 2

Matrix 2:
2 1 6 8 5 7
6 1 8 9 2 7
9 5 4 3 1 2
3 3 4 1 1 3
8 7 4 2 7 7

Multiplication:
152 91 114 101 86 127
166 86 144 138 74 134
78 43 106 97 50 100
119 79 106 78 66 109
69 38 66 57 32 62

Process returned 0 (0x0)   execution time : 4.553 s
Press any key to continue.

If Matrix A has dimensions 5 x 5 (5 rows and 5 columns),
and Matrix B has dimensions 5 x 6 (5 rows and 6 columns),
the resultant matrix after multiplication will have dimensions 5 x 6 (5 rows and 6 columns).
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