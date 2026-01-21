#include <iostream>
#include <vector>
using namespace std;

// Directions for each cluster type
// Index 0: unused; index 1..5 correspond to types
vector<vector<pair<int,int>>> DIRS = {
    {}, // dummy
    {{0, -1}, {0, 1}},                         // Type 1: Horizontal
    {{-1, 0}, {1, 0}},                         // Type 2: Vertical
    {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}},     // Type 3: Diagonal
    {{0, -1}, {0, 1}, {-1, 0}, {1, 0}},       // Type 4: H + V (4-connect)
    {{0, -1}, {0, 1}, {-1, 0}, {1, 0},
     {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}      // Type 5: H + V + D (8-connect)
};

void dfs(int i, int j, const vector<vector<int>>& grid, vector<vector<bool>>& visited, const vector<pair<int,int>>& dirs) {
    visited[i][j] = true;
    int n = grid.size();
    int m = grid[0].size();

    for (auto [dx, dy] : dirs) {
        int ni = i + dx;
        int nj = j + dy;
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1 && !visited[ni][nj]) {
            dfs(ni, nj, grid, visited, dirs);
        }
    }
}

int countClusters(const vector<vector<int>>& grid, int type) {
    if (grid.empty() || grid[0].empty()) return 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int count = 0;

    const auto& dirs = DIRS[type];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                dfs(i, j, grid, visited, dirs);
                ++count;
            }
        }
    }
    return count;
}

int main() {
    int type;
    cin >> type;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << countClusters(grid, type) << endl;
    return 0;
}