#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &g,int u,int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}

bool isCycle(vector<vector<int>> &g,vector<bool> &visited,int u,int parent)
{
    visited[u]=true;

    for(int v:g[u])
    {
        if(!visited[v])
        {
            if(isCycle(g,visited,v,u))
            {
                return true;
            }
        }
        else if(parent!=v)
        {
            return true;
        }
    }
    return false;
}

bool dfs(vector<vector<int>> &g,int V)
{
    vector<bool> visited(V,false);

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            if(isCycle(g,visited,i,-1))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int V,E;
    cin>>V>>E;
    vector<vector<int>> g(V);

    int a,b;
    for(int i=0;i<E;i++)
    {
        cin>>a>>b;
        addEdge(g,a,b);
    }
    if(dfs(g,V))
    {
        cout<<"There is a cycle"<<endl;
    }
    else
    {
        cout<<"There is no cycle"<<endl;
    }
}