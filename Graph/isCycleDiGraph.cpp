#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &g,int u,int v)
{
    g[u].push_back(v);
}

bool isCycle(vector<vector<int>> &g,vector<bool> &visited,vector<bool> &recStack,int u)
{
    visited[u]=true;
    recStack[u]=true;

    for(int v:g[u])
    {
        if(!visited[v] && isCycle(g,visited,recStack,v))
        {
            return true;
        }
        else if(recStack[v])
        {
            return true;
        }
    }
    recStack[u]=false;
    return false;
}

bool dfs(vector<vector<int>> &g,int V)
{
    vector<bool> visited(V,false);
    vector<bool> recStack(V,false);

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            if(isCycle(g,visited,recStack,i))
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
    if(dfs(g,V)){
        cout<<"There is a cycle"<<endl;
    }
    else{
        cout<<"No cycle"<<endl;
    }
}