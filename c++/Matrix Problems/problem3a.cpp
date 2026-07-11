// problem : Matrix Multiplication : 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r1,c1,r2,c2;

    cout << "Enter rows and cols of matrix A: ";
    cin >> r1 >> c1;

    cout << "Enter rows and cols of matrix B: ";
    cin >> r2 >> c2;

    if(c1 != r2)
    {
        cout << "Matrix multiplication not possible";
        return 0;
    }

    vector<vector<int>> A(r1, vector<int>(c1));
    vector<vector<int>> B(r2, vector<int>(c2));
    vector<vector<int>> C(r1, vector<int>(c2,0));

    cout << "Enter matrix A:\n";
    for(int i=0;i<r1;i++)
        for(int j=0;j<c1;j++)
            cin>>A[i][j];

    cout << "Enter matrix B:\n";
    for(int i=0;i<r2;i++)
        for(int j=0;j<c2;j++)
            cin>>B[i][j];

    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            for(int k=0;k<c1;k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Result matrix:\n";

    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
}