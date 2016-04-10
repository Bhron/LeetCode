class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> island_nums;

        if (n <= 0 || m <= 0 || positions.empty()) {
            return island_nums;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int id = get_id(i, j, n);
                parents[id] = id;
            }
        }

        vector<vector<int>> islands;
        for (int i = 0; i < m; i++) {
            vector<int> row(n, 0);
            islands.push_back(row);
        }

        int counter = 0;
        for (int i = 0; i < positions.size(); i++) {
            int x = positions[i].first;
            int y = positions[i].second;
            if (islands[x][y] != 1) {
                helper(islands, x, y, m, n, counter);
            }

            island_nums.push_back(counter);
        }

        parents.clear();

        return island_nums;
    }
private:
    unordered_map<int, int> parents;

    void helper(vector<vector<int>>& islands, int x, int y, int m, int n, int& counter) {
        counter++;
        islands[x][y] = 1;

        int id = get_id(x, y, n);
        int parent = find(id);

        static const int dx[4] = { -1, 1, 0, 0 };
        static const int dy[4] = { 0, 0, -1, 1 };

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < m && 0 <= ny && ny < n && islands[nx][ny] == 1) {
                int nid = get_id(nx, ny, n);
                int parent_n = find(nid);
                if (parent != parent_n) {
                    merge(id, nid);
                    counter--;
                }
            }
        }
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

    int get_id(int x, int y, int n) {
        return x * n + y;
    }
};
