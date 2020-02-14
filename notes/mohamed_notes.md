j ============================================================================ #
#                       Graph data structurenote.                              #
# ============================================================================ #

##  the concept of Graph:
+ A graph is an orderd pair of set V if `vertices` ans set E of `edges`. G = (V, E)
	in other words, a Representation pair-wise relationshio between a set of objects.
+ directed (ie digraph) and undirected graph.
+ example of tasks that we can do with the graphs:
 	- web crawling  that is basicly graph traversal 
+ weighted and unweighted graphs
 	- unweighted graph is a graph were all edges having the weight == 1 unit.  
+ self-loop! : the same vertics have an edge with it self. 
+ multiedge/parallel edge  : 
+ max of edges : if (|v| == n) then 
		- 0 <= |E| <= n(n -1) , if directed
		- 0 <= |E| <= n(n -1)/2 , if undirected
+ a graph is calles a `dense` if he have too many edges. ~ max of edges
	- we typicaly store this in an Adjacency matrix. 
+ a graph is calles a `Sparse` if he have too few edges. ~ nbr of vertices
	- we typicaly store this in an Adjacency list. 
+ `Path` : (we normaly call this a `walk`)
	- simple path : no vetices repeated (we normaly call this a `path`)
	- trail : a walk in wich no edges are repeated.
+ strongly connected graphs : if there is a path from any vertex to any other one.
+ closed walk : starts and ends at same vertex.
+ Simple cycle : no repetition other than start and end.
+ acyclic Graph : a graph with no cycle.


+ Cost ::
	- Time-Cost Of Operations : time complexity.
	- Memory Usage : space Complexity.
+ Graph Representation :
	- Adjacency Matrix : time : O(v) for finding adjacent nodes
								O(1) for the acces time (constant)
						 space : O(v^2).
	- Adjacency List :	time : O(v) for finding adjacent nodes & O(|E|) for finding if 2 nodes are connected.
						space : O(|E| + |v|) << O(|v| ^2).
			ps : most graphs are sparse.
+ Problems in Graph Theory
	- strongly Connected components : Tarjan's and Kosaraju's algorithm
	- traveling salesman problem : Held-Karp, branch and bound and many approximation algos
	- Bridges and articulation points 
	- minimum spanning tree (MST) : Kruskal's, Prim's & Boruvka's algorithm
	- Network flow: max flow : Ford-Fulkerson, Edmonds-karp & dinic's algorithm
+ Depth First Search Algorithm (DFS)
	- simple traversal of a graph
	- connected components (identify and find connected components)
	- Compute a graph’s minimum spanning tree.
	- Detect and find cycles in a graph.
	- Check if a graph is bipartite.
	- Find strongly connected components.
	- Topologically sort the nodes of a graph.
	- Find bridges and articulation points.
	- Find augmenting paths in a flow network.
	- Generate mazes.
	- and many more applications

+ Breadth First Search Algorithm (find the shortest path in an weighted graph)
	- exercse : dungeon Problem Statement. 
+
+
