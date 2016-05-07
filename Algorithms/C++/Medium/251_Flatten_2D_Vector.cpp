class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        v = vec2d;
        row = 0;
        col = 0;
    }

    int next() {
        int val = v[row][col++];
        if (col >= v[row].size()) {
            row++;
            col = 0;
        }

        return val;
    }

    bool hasNext() {
        while (row < v.size() && v[row].size() == 0) {
            row++;
        }

        return row < v.size();
    }
private:
    vector<vector<int>> v;
    int row;
    int col;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
