#include<bits/stdc++.h>

using namespace std;

int parent[60000];
int rank11[60000];

vector<pair<int,pair<int,int>>> edges;


int find(int x)
{
    if(parent[x]!=x)
    {
        parent[x]=find(parent[x]);
    }
    return parent[x];
}

void Union(int x,int y)
{
    int xroot=find(x);
    int yroot=find(y);

    if(rank11[xroot]<rank11[yroot])
    {
        parent[xroot]=yroot;
    }
    else
    {
        parent[yroot]=xroot;
    }
    if(rank11[xroot]==rank11[yroot])
    {
        rank11[xroot]+=1;
    }
}

int mst(int V)
{
    int e=0,it=0;
    int ans=0;
    while(e<V-1 && it<edges.size())
    {
        int x=find(edges[it].second.first);
        int y=find(edges[it].second.second);

        if(x!=y)
        {
            e++;
            // cout<<edges[it].second.first<<"    "<<edges[it].second.second<<endl;
            ans+=edges[it].first;
            Union(x,y);
        }
        it++;
    }

    return ans;
}

int main()
{
    int V=4;
   
    int B[][3]={{1,2,1},{2,3,4},{1,4,3},{4,3,2},{1,3,10}};

//Traverse the given 2D array B
    for(int i=0;i<4;i++)
    {
        edges.push_back({B[i][2],{B[i][0],B[i][1]}});
    }
    sort(edges.begin(),edges.end());
    for(int i=1;i<=V;i++)
    {
        rank11[i]=0;
        parent[i]=i;
    }
    cout<<mst(V)<<endl;

}