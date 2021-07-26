#include<bits/stdc++.h>

using namespace std;


void addEdge(vector<vector<int>> &graph,int u,int v)
{
    graph[u].push_back(v);
    
}

void dfsUtil(vector<bool> &visited,int v,vector<vector<int>> &graph)
{
    visited[v]=true;
    cout<<v<<" ";

    for(int it:graph[v])
    {
        if(!visited[it])
        {
            dfsUtil(visited,it,graph);
        }
    }
}

void dfs(vector<vector<int>> &graph,int V)
{
    vector<bool> visited(V,false);

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfsUtil(visited,i,graph);
        }
    }
}



int main()
{
    int V,E;
    cin>>V>>E;

    vector<vector<int>> graph(V);
    int a,b;
    for(int i=0;i<E;i++)
    {
        cin>>a>>b;
        addEdge(graph,a,b);
    }
    dfs(graph,V);
    
}