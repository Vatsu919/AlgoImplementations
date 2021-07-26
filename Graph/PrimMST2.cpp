#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<pair<int,int>> adj[],int u,int v,int wt)
{
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
}

void primMST(vector<pair<int,int>> adj[],int V)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    bool mstset[V];
    int parent[V];
    int key[V];
    for(int i=0;i<V;i++)
    {
        mstset[i]=false;
        key[i]=INT_MAX;
    }
    key[0]=0;
    pq.push({0,0});
    while(!pq.empty())
    {
        int u=pq.top().second;
    
        pq.pop();

        if(mstset[u])
        {
            continue;
        }
        mstset[u]=true;
        for(pair<int,int> vp:adj[u])
        {
            int v=vp.first;
            int wt=vp.second;

            if(!mstset[v] && wt<key[v])
            {
                parent[v]=u;
                key[v]=wt;
                pq.push({wt,v});
            }
        }
    }

    for(int i=1;i<V;i++)
    {

        cout<<i<<" - "<<parent[i]<<endl;
    }
}

int main()
{
    int V=9;
    vector<pair<int,int>> adj[V];

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);
 
    primMST(adj, V);
}