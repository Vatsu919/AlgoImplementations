#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int> *adj;

    public:
        Graph(int V);
        void addEdge(int u,int v);
        void BFS(int u);

};


Graph::Graph(int V)
{
    this->V=V;
    this->adj = new list<int>[V];
}

void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::BFS(int u)
{
    vector<bool> visited(this->V,false);
    list<int> queue;

    queue.push_back(u);
    visited[u]=true;

    while(!queue.empty())
    {
        int f=queue.front();
        cout<<f<<" ";
        queue.pop_front();

        for(int it:adj[f])
        {
            if(!visited[it])
            {
                visited[it]=true;
                queue.push_back(it);
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

     cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
}


