#include<bits/stdc++.h>

using namespace std;


void createTree(vector<int> &segmenttree,vector<int> &A,int low,int high,int pos)
{
    if(low==high)
    {
        segmenttree[pos]=A[low];
        return ;
    }
    int mid = low + (high-low)/2;
    createTree(segmenttree,A,low,mid,2*pos+1);
    createTree(segmenttree,A,mid+1,high,2*pos+2);
    segmenttree[pos] = min(segmenttree[2*pos+1],segmenttree[2*pos+2]);
    return ;
}

int query(vector<int> &segmenttree,int qlow,int qhigh,int low,int high,int pos)
{
    if(qlow<=low && qhigh>=high)
    {
        return segmenttree[pos];
    }
    else if(qlow>high || qhigh<low)
    {
        return INT_MAX;
    }
    int mid=low+(high-low)/2;
    return min(query(segmenttree,qlow,qhigh,low,mid,2*pos+1),query(segmenttree,qlow,qhigh,mid+1,high,2*pos+2));
}

void update(vector<int> &segmenttree,int ind,int value,int low ,int high,int pos)
{
    if(ind>=low && ind<=high)
    {
        segmenttree[pos]=min(segmenttree[pos],value);
    }
    else
    {
        return ;
    }
    if(low!=high)
    {
        int mid = low + (high-low)/2;
        update(segmenttree,ind,value,low,mid,2*pos+1);
        update(segmenttree,ind,value,mid+1,high,2*pos+2);
    }


}


int main()
{
    vector<int> A;
    int n;
    cout<<"Enter the array size"<<endl;
    cin>>n;
    cout<<"Now enter the elements separated by space"<<endl;
    for(int i=0;i<n;i++)
    {
        int y;
        cin>>y;
        A.push_back(y);
    }

    int sz=2*pow(2,ceil(log2(n)))-1;
    vector<int> segmenttree(sz,INT_MAX);
    createTree(segmenttree,A,0,n-1,0);
    cout<<query(segmenttree,0,2,0,n-1,0)<<endl;

    cout<<"Now an update query"<<endl;
    update(segmenttree,1,-1,0,n-1,0);
    cout<<query(segmenttree,0,2,0,n-1,0)<<endl;
}