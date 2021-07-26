#include<bits/stdc++.h>

using namespace std;
#define V 5

int getMin(bool mstset[],int keys[])
{
    int min=INT_MAX,minindex;

    for(int i=0;i<V;i++)
    {
        if(!mstset[i] && keys[i]<min)
        {
            min=keys[i];
            minindex=i;
        }
    }
    return minindex;
}

void printMST(int parent[], int graph[V][V]) 
{ 
    cout<<"Edge \tWeight\n"; 
    for (int i = 1; i < V; i++) 
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
} 

void primMST(int graph[V][V])
{
    int parent[V];
    int keys[V];
    bool mstset[V];

    for(int i=0;i<V;i++)
    {
        mstset[i]=false;
        keys[i]=INT_MAX;
    }
    keys[0]=0;
    
    for(int count=0;count<V-1;count++)
    {
        int u=getMin(mstset,keys);

        mstset[u]=true;

        for(int v=0;v<V;v++)
        {
            if(graph[u][v] && !mstset[v] && graph[u][v]<keys[v])
            {
                parent[v]=u;
                keys[v]=graph[u][v];
            }
        }
    }
    printMST(parent,graph);
}

int main() 
{ 
    /* Let us create the following graph 
        2 3 
    (0)--(1)--(2) 
    | / \ | 
    6| 8/ \5 |7 
    | / \ | 
    (3)-------(4) 
            9     */
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 
  
    // Print the solution 
    primMST(graph); 
  
    return 0; 
} 