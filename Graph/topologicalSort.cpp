#include<bits/stdc++.h>

using namespace std;

void dfsUtil(vector<int> adj[],vector<bool> &visited,int u,stack<int> &s)
{
    visited[u]=true;

    for(int v:adj[u])
    {
        if(!visited[v])
        {
            dfsUtil(adj,visited,v,s);
        }
    }
    s.push(u);
}


void tsort(vector<int> adj[],int V)
{
    vector<bool> visited(V,false);
    stack<int> s;

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfsUtil(adj,visited,i,s);
        }
    }

    while(!s.empty())
    {
        cout<<s.top() <<" ";
        s.pop();
    }
    cout<<endl;
}

int main()
{
    vector<int> adj[6];

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    tsort(adj,6);

}