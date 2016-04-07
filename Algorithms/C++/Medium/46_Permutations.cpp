// Recursion
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;

        if (nums.empty()) {
            return permutations;
        }

        vector<bool> selected(nums.size(), false);
        vector<int> init;

        helper(permutations, selected, init, nums);

        return permutations;
    }
private:
    void helper(vector<vector<int>>& permutations, vector<bool>& selected, vector<int>& cur, vector<int>& nums) {
        if (cur.size() == nums.size()) {
            permutations.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!selected[i]) {
                cur.push_back(nums[i]);
                selected[i] = true;
                helper(permutations, selected, cur, nums);
                selected[i] = false;
                cur.pop_back();
            }
        }
    }
};

// Non-Recursion
class Solution {
public:
    vector<vector<int> > permute(vector<int> nums) {
        vector<vector<int>> permutations;

        if (nums.size() == 0) {
            return permutations;
        }

        vector<bool> selected(nums.size(), false);
        vector<int> stack;

        int n = nums.size();
        stack.push_back(-1);

        while (!stack.empty()) {
            int last = stack.back();
            stack.pop_back();
            if (last != -1) {
                selected[last] = false;
            }

            // Find the next avaiable number
            int next = -1;
            for (int i = last + 1; i < n; i++) {
                if (!selected[i]) {
                    next = i;
                    break;
                }
            }
            if (next == -1) {
                continue;
            }

            // Get the next permutation
            stack.push_back(next);
            selected[next] = true;
            for (int i = 0; i < n; i++) {
                if (!selected[i]) {
                    stack.push_back(i);
                    selected[i] = true;
                }
            }

            vector<int> permutation;
            for (int i = 0; i < n; i++) {
                permutation.push_back(nums[stack[i]]);
            }
            permutations.push_back(permutation);
        }

        return permutations;
    }
};
