#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
}
void dfsUtil(vector<bool> &visited,vector<int> adj[],int u)
{
    visited[u]=true;
    cout<<u<<" ";

    for(int v:adj[u])
    {
        if(!visited[v])
        {
            dfsUtil(visited,adj,v);
        }
    }
    
}



vector<int> *getRev(vector<int> adj[],int V)
{
    vector<int> *rev = new vector<int>[V];
    for(int i=0;i<V;i++)
    {
        for(int v:adj[i])
        {
            rev[v].push_back(i);
        }
    }
    return rev;
}
void fillStack(vector<bool> &visited,vector<int> adj[],int u,stack<int> &s)
{
    visited[u]=true;

    for(int v:adj[u])
    {
        if(!visited[v])
        {
            fillStack(visited,adj,v,s);
        }
    }
    s.push(u);
}

stack<int> getStack(vector<int> adj[],int V)
{
    vector<bool> visited(V,false);
    stack<int> s;

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            fillStack(visited,adj,i,s);
        }
    }

    return s;
}

void kosaRaju(vector<int> adj[],int V)
{
    stack<int> st = getStack(adj,V);

    vector<int> *transpose= getRev(adj,V);
    vector<bool> visited(V,false);

    while(!st.empty())
    {
        int u=st.top();
        if(!visited[u])
        {
            
            dfsUtil(visited,transpose,u);
            cout<<endl;
        }
        st.pop();
    }
    return ;
}

int main()
{
    int V=5;
    vector<int> adj[V];

    addEdge(adj,1,0);
    addEdge(adj,0,2);
    addEdge(adj,2,1);
    addEdge(adj,0,3);
    addEdge(adj,3,4);

    kosaRaju(adj,V);
}