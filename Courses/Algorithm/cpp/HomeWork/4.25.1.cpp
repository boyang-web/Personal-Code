#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    if(n!=m)
    {
        cout<<"false";
        return 0;
    }
    cout<<"true"<<"\n";
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
cout<<"\n";
    }

    return 0;
}