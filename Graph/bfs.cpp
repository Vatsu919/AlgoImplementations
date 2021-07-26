#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> graph[],int u,int v)
{
    graph[u].push_back(v);

}
void bfs(vector<int> graph[],int V)
{
    vector<bool> visited(V,false);
    queue<int> q;

    visited[0]=true;
    q.push(0);

    while(!q.empty())
    {
        int u=q.front();
        cout<<u<<" ";
        q.pop();

        for(int v:graph[u])
        {
            if(!visited[v])
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
}



int main()
{
    int V,E;
    cin>>V>>E;
    vector<int> graph[V];
    int a,b;
    for(int i=0;i<E;i++)
    {
        cin>>a>>b;
        addEdge(graph,a,b);
    }
    bfs(graph,V);
}