class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }

        unordered_set<int> hash;

        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) == hash.end()) {
                hash.insert(nums[i]);
            } else {
                return true;
            }
        }

        return false;
    }
};
