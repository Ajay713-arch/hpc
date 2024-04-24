#include<iostream>
#include<vector>
#include<omp.h>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

queue<int>q;

void bfs(int start, int* arr, int n, int visit[])
{
	#pragma omp parallel for ordered
	for(int i=0; i<n; i++)
	{
		#pragma omp ordered
		if( ( *(arr + (n*start) + i)  == 1 ) && (visit[i] == 0) )
		{
			cout<<i<<" ";
			q.push(i);
			visit[i] = 1;
		}
	}

	q.pop();

	if(!q.empty()) bfs(q.front(), (int*)arr, n, visit);
	
}

int main()
{

	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	//cout<<"BFS 0 1 2 3 4 5 6"<<endl;
    cout<<"Enter the number of vertices: ";
    int n;
    cin>>n;

    int arr[n][n] = {0};

    cout<<"Enter the number of edges: ";
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

	int visit[n] = {0};

    cout<<"Enter the start vertex: ";
    int start;
    cin>>start;
	
	
	clock_t strt = clock();

	visit[start] = 1;
	cout<<start<<" ";
	q.push(start);

	bfs(start, (int*)arr, n, visit);

    clock_t stop = clock();

	cout<<"\nTime required : "<<(double)(stop-strt)<<" ms"<<endl;

    return 0;
}

/*

"Parallel Execution"
PS D:\C++> g++ -fopenmp parallel_bfs.cpp
PS D:\C++> ./a out
Enter the number of vertices: 7
Enter the number of edges: 6
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
0 1 2 3 4 5 6
Time required : 3 ms

"Serial Execution"
PS D:\C++> g++ parallel_bfs.cpp
PS D:\C++> ./a out
Enter the number of vertices: 7
Enter the number of edges: 6
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
0 1 2 3 4 5 6
Time required : 11 ms


*/

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