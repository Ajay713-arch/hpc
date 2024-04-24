#include<iostream>
#include<omp.h>
using namespace std;
int main()
{
    cout<<endl;
    cout<<"Enter the number of elements in the vector: ";
    int nvec;
    cin>>nvec;

    int vec[nvec] = {0};
                                          
    for(int i=0; i<nvec; i++) vec[i] = rand()%10;
    cout<<endl;

    cout<<"Vector: ";
    for(int i=0; i<nvec; i++) cout<<vec[i]<<" ";
    cout<<endl;

    cout<<endl;
    cout<<"Enter the number of rows in the matrix: ";
    int rows;
    cin>>rows;

    int mat[rows][nvec];
    for(int i=0; i<rows; i++) for(int j=0; j<nvec; j++) mat[i][j] = rand()%10;
    cout<<endl;

    cout<<"Matrix: "<<endl;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<nvec; j++) cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    cout<<"Multiplication: "<<endl;
    int rvec[nvec];

    #pragma omp parallel for
    for(int i=0; i<rows; i++)
    {
        rvec[i] = 0;
        int arr[nvec] = {0};

        #pragma omp parallel for
        for(int j=0; j<nvec; j++) arr[j] = mat[i][j] * vec[j];

        int sum = 0;

        #pragma omp parallel for reduction(+: sum)
        for(int k = 0; k < nvec; k++) sum += arr[k];

        rvec[i] = sum;
    }

    for(int i=0; i<nvec; i++) cout<<rvec[i]<<" ";
    cout<<endl;
    
    return 0;
}

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