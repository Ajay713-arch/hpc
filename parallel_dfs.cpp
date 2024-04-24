#include <iostream>
#include <vector>
#include <stack>
#include <omp.h>
#include <bits/stdc++.h>

using namespace std;

void dfs(int start, int* arr, int n, int visited[]) {

    //#pragma omp parallel for ordered
    for(int i = 0; i < n; i++) {
        //#pragma omp ordered
        if( (*(arr + (start*n) + i) == 1) && (!visited[i]) )
        {    
            visited[i] = 1;
            cout<<i<<" ";
            dfs(i, (int*)arr, n, visited);
        }
    }
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

	cout<<"Enter the number of vertices:";
    int n;
    cin>>n;
	
    int arr[n][n] = {0};

    cout<<"Enter the number of edges:";
    int edges;
    cin>>edges;
    

    for(int j=0; j<edges; j++)
    {
        int a, b;
        cout<<"Enter the two edges:"<<endl;
        cin>>a>>b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    int visited[n] = {0};

    cout<<"Enter the start vertex: ";
    int start;
    cin>>start;

    clock_t strt = clock();
    
    cout<<start<<" ";
    visited[start] = 1;
	dfs(start, (int *)arr, n, visited);
    
    clock_t stop = clock();

    cout<<"\nTime required : "<<(double)(stop-strt)<<" ms"<<endl;


    return 0;
}


/*

"Parallel Execution"
PS D:\C++> g++ -fopenmp parallel_dfs.cpp
PS D:\C++> ./a out
Enter the number of vertices:7 
Enter the number of edges:6
Enter the two edges:
0 1
Enter the two edges:
0 2
Enter the two edges:
1 3        
Enter the two edges:
1 4
Enter the two edges:
2 5
Enter the two edges:
2 6
Enter the start vertex: 0
0 1 3 4 2 5 6
Time required : 9 ms

"Serial Execution"
PS D:\C++> g++ parallel_dfs.cpp
PS D:\C++> ./a out
Enter the number of vertices:7
Enter the number of edges:6
Enter the two edges:
0 1
Enter the two edges:
0 2
Enter the two edges:
1 3
Enter the two edges:
1 4
Enter the two edges:
2 5
Enter the two edges:
2 6
Enter the start vertex: 0
0 1 3 4 2 5 6
Time required : 12 ms


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