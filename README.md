# Competitive-Programming
A repository for algorithms and solutions to competitive programming problems

Summary of different algorithms and their time complexity

- Single-source shortest path:\\
    . If the graph is a DAG it can be done in O(V+E) with topological sort
    . Graph with non-negative edges use Dijkstra O((E+V)*LogV) o O(VLogV)
    . With negative edges use Bellman-Ford O(V*E)

- All-pair shortest path:\\
    . Floyd Warshall O(V^3)
    . Dijkstra from every node in sparse graph and non-negative edges O(V²*LogV)
    . Johnson's algorithm in sparse graph O(V²LogV+VE)


  
