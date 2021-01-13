#include <iostream>
#include <queue>

using namespace std;
#define m 4
#define n 5
int zombie(int grid[][n])
{
    // initialize the queue &amp;amp; count people
    int people = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0)
                people++;
            else if (grid[i][j] == 1)
                q.push({ i, j });
        }
    }
    // corner case
    if (people == 0) {
        return 0;
    }
    int deltaX[4] = { 1, 0, 0, -1 };
    int deltaY[4] = { 0, 1, -1, 0 };
    // bfs
    int days = 0;
    while (!q.empty()) {
        days++;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            pair<int,int> zb = q.front();
            q.pop();
            for (int direction = 0; direction < 4; direction++) {
                pair<int,int> adj = { zb.first + deltaX[direction], zb.second + deltaY[direction] };
                // If adj neighbour is valid index and a human
                // Then change the person to zombie
                // Decrement count of people who are left by one
                // Add new Zombie formed to the queue for further coversions
                if (adj.first >= 0 && adj.first < m && adj.second >= 0 && adj.second < n && grid[adj.first][adj.second] == 0) {
                    grid[adj.first][adj.second] = 1;
                    people--;
                    if (people == 0)
                        return days;
                    q.push(adj);
                }
            }
        }
    }
    return -1; // Return -1 if can not turn all people into zombies.
}
int main()
{
    int grid[][n] = { { 0, 1, 1, 0, 1 }, { 0, 1, 0, 1, 0 }, { 0, 0, 0, 0, 1 }, { 0, 1, 0, 0, 0 } };
    cout << zombie(grid);
    return 0;
}
