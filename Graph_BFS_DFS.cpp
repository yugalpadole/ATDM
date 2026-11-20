#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph
{
int n;
int matrix[10][10];
vector<int> adj[10];
bool visited[10];
void dfsUtil(int v)
{
visited[v] = true;
cout << char('A' + v) << " ";
for (int u : adj[v])
{
if (!visited[u])
dfsUtil(u);
}
}
public:
Graph(int vertices)
{
n = vertices;
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
matrix[i][j] = 0;
}
void addEdge(int u, int v)
{
matrix[u][v] = 1;
matrix[v][u] = 1;
adj[u].push_back(v);
adj[v].push_back(u);
}
void displayMatrix()
{
cout << "\nAdjacency Matrix:\n";
for (int i = 0; i < n; i++)
cout << char('A' + i) << " ";
cout << endl;
for (int i = 0; i < n; i++)
{
cout << char('A' + i) << " ";
for (int j = 0; j < n; j++)
cout << matrix[i][j] << " ";
cout << endl;
}
}


void displayList()
{
cout << "\nAdjacency List:\n";
for (int i = 0; i < n; i++)
{
cout << char('A' + i) << " -> ";
for (int u : adj[i])
cout << char('A' + u) << " ";
cout << endl;
}
}
void BFS(int start)
{
for (int i = 0; i < n; i++)
visited[i] = false;
queue<int> q;
visited[start] = true;
q.push(start);
cout << "\nBFS Traversal: ";
while (!q.empty())
{
int v = q.front();
q.pop();
cout << char('A' + v) << " ";
for (int u : adj[v])
{
if (!visited[u])
{
visited[u] = true;
q.push(u);
}
}
}
cout << endl;
}
void DFS(int start)
{
for (int i = 0; i < n; i++)
visited[i] = false;
cout << "\nDFS Traversal: ";
dfsUtil(start);
cout << endl;
}
};


int main()
{
Graph g(4);
g.addEdge(0, 1); // A-B
g.addEdge(0, 3); // A-D
g.addEdge(1, 2); // B-C
g.addEdge(1, 3); // B-D
g.displayMatrix();
g.displayList();

g.BFS(0);
g.DFS(0);
return 0;
}
