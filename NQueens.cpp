#include<iostream>
using namespace std;
void printBoard(char board[20][20],int n)
{
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cout<<board[i][j]<<" ";
    }
    cout<<endl;
}
cout<<endl;
}
bool isSafe(char board[20][20],int row,int col,int n)
{
    for(int j=0;j<n;j++)
    {
        if(board[row][j]=='Q')
        {
            return false;
        }
    }
    for(int i=0;i<row;i++)
    {
        if(board[i][col]=='Q')
        {
            return false;
        }
    }
    for(int i=row-1, j=col-1;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    return true;
}
void nQueens(char board[20][20],int row,int n)
{
    if(row==n)
    {
        printBoard(board,n);
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(isSafe(board,row,j,n))
        {
            board[row][j]='Q';
            nQueens(board,row+1,n);
            board[row][j]='.';
        }
    }
}
int main()
{
    int n;
    char board[20][20];
    cout<<"Enter n: "<<endl;
    cin>>n;
    if(n<1||n>20)
    {
        cout<<"Invalid."<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j]='.';
        }
    }
    nQueens(board,0,n);
    return 0;
}