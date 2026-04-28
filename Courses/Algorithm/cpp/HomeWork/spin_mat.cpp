#include<iostream>
#include<fstream>


using namespace std;

int mat[801][801];
int main()
{
    ifstream fin("in.txt");
    if (!fin) {
    cout << "file open failed\n";
    return 0;
}
    
    int n;
    fin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int temp;
            fin>>temp;
        mat[j][i]=temp;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            swap(mat[i][j],mat[i][n-j-1]);
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
}