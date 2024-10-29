#include<bits/stdc++.h>
using namespace std;

bool is_safe(int row , int col ,vector<string>&board ,int n )
{
    int duprow = row;
    int dupcol = col;
    while(col>=0)
    {
        if(board[row][col] == 'Q')
        {
            return false;
        }
        col--;
    }
    row = duprow;
    col = dupcol;

    while(row>=0 && col>=0)
    {
        if(board[row][col] == 'Q')
        {
            return false;
        }
        col -- ;
        row--;
    }
    row = duprow;
    col = dupcol;

    while(row<n &&  col>=0)
    {
        if(board[row][col] == 'Q')
        {
            return false;
        }
        col--;
        row++;
    }

    return true;
}


void solve(int col , vector<string>&board,vector< vector<string>>&ans,int n)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++)
    {
        if(is_safe(row,col,board,n))
     {
        board[row][col] = 'Q';  //put Q in the (row,col)

        solve(col+1 , board , ans ,n);

        board[row][col] = '.';  // remove Q from (row,col)->backtracking
     }
    }
}

int main()
{
    int n;
    cout<<"Enter the number of queens"<<endl;
    cin>>n;

    vector<string>board(n);
    vector< vector<string>>ans;
    string s (n,'.');

    for(int i=0;i<n;i++)
    {
        board[i] = s;
    }

    solve(0,board,ans,n);

    for (const auto& solution : ans) {
        for (const auto& row : solution) {
            cout << row << endl;  // Print each row as a string
        }
        cout << endl;  // Separate solutions with a blank line
    }
    
    
    cout<<"Number of solutions:"<<ans.size();
    

}