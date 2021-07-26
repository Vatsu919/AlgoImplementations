#include<bits/stdc++.h>
using namespace std;


class Graph{
    int V;
    list<int> *adj;

    public:

    Graph(int V);
    void addEdge(int u,int v);
    void dfs();
    void dfsUtil(vector<bool> &visited,int u);

};

Graph::Graph(int V)
{
    this->V=V;
    this->adj=new list<int>[V];
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::dfs()
{
    vector<bool> visited(this->V,false);

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfsUtil(visited,i);
        }
    }
}

void Graph::dfsUtil(vector<bool> &visited,int u)
{
    visited[u]=true;
    cout<<u<<" ";

    for(int i:adj[u])
    {
        if(!visited[i])
        {
            dfsUtil(visited,i);
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.dfs();
}