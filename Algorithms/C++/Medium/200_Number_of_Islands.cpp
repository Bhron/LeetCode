// DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        n = grid.size();
        m = grid[0].size();

        int counter = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    counter++;
                    remove_island(grid, i, j);
                }
            }
        }

        return counter;
    }
private:
    int n, m;

    void remove_island(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';

        static const int dx[4] = { -1, 1, 0, 0 };
        static const int dy[4] = { 0, 0, -1, 1 };

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && grid[nx][ny] == '1') {
                remove_island(grid, nx, ny);
            }
        }
    }
};

// Union Find
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int id = get_id(i, j, m);
                parents[id] = id;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    helper(grid, i, j, n, m);
                }
            }
        }

        unordered_set<int> hash;
        int counter = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    int id = get_id(i, j, m);
                    int parent = find(id);

                    if (hash.find(parent) == hash.end()) {
                        counter++;
                        hash.insert(parent);
                    }
                }
            }
        }

        return counter;
    }
private:
    unordered_map<int, int> parents;

    void helper(vector<vector<char>>& grid, int x, int y, int n, int m) {
        int id = get_id(x, y, m);

        static const int dx[4] = { -1, 1, 0, 0 };
        static const int dy[4] = { 0, 0, -1, 1 };

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && grid[nx][ny] == '1') {
                int nid = get_id(nx, ny, m);
                merge(id, nid);
            }
        }
    }

    int get_id(int x, int y, int m) {
        return x * m + y;
    }

    int find(int x) {
        int parent = x;
        while (parent != parents[parent]) {
            parent = parents[parent];
        }

        int root = parent, tmp;
        parent = x;
        while (parent != parents[parent]) {
            tmp = parents[parent];
            parents[parent] = root;
            parent = tmp;
        }

        return root;
    }

    void merge(int a, int b) {
        int parent_a = find(a);
        int parent_b = find(b);

        if (parent_a != parent_b) {
            parents[parent_b] = parent_a;
        }
    }
};
