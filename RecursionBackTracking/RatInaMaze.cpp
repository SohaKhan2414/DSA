
#include <iostream>
#include <string>
using namespace std;

#define N 4

void getAns(int mat[N][N], int r, int c, string ans, bool visited[N][N])
{
    // Base case 1: Out of bounds
    if (r < 0 || c < 0 || r >= N || c >= N)
        return;

    // Base case 2: Blocked cell or already visited
    if (mat[r][c] == 0 || visited[r][c] == true)
        return;

    // Base case 3: Destination reached
    if (r == N - 1 && c == N - 1)
    {
        cout << ans << endl;
        return;
    }

    // Mark current cell as visited
    visited[r][c] = true;

    // Move Down
    getAns(mat, r + 1, c, ans + "D", visited);

    // Move Up
    getAns(mat, r - 1, c, ans + "U", visited);

    // Move Left
    getAns(mat, r, c - 1, ans + "L", visited);

    // Move Right
    getAns(mat, r, c + 1, ans + "R", visited);

    // BACKTRACKING: Unmark current cell
    visited[r][c] = false;
}

int main()
{
    int mat[N][N] =
    {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    bool visited[N][N] = {false};

    if (mat[0][0] == 0 || mat[N - 1][N - 1] == 0)
    {
        cout << "No path exists" << endl;
        return 0;
    }

    getAns(mat, 0, 0, "", visited);

    return 0;
}
