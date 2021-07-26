#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool dfsUtil(vector<int> adj[],vector<bool> &visited,vector<int> &color,int u)
{
    visited[u]=true;

    for(int v:adj[u])
    {
        if(!visited[v])
        {
            color[v]=1-color[u];
            if(!dfsUtil(adj,visited,color,v))
            {
                return false;
            }
        }
        else if(color[v]==color[u])
        {
            return false;
        }
    }
    return true;
}


bool dfs(vector<int> adj[],int V)
{
    vector<bool> visited(V+1,false);
    vector<int> color(V+1);

    for(int i=1;i<=V;i++)
    {
        if(!visited[i])
        {
            color[i]=0;
            if(dfsUtil(adj,visited,color,i)==false)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int V=6;
    vector<int> adj[V+1];

    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 1);

    if(dfs(adj,V))
    {
        cout<<"Bipartite"<<endl;
    }
    else
    {
        cout<<"Not bipartite"<<endl;
    }
}

