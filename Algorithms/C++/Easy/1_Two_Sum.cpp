class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indexes;

        if (nums.empty()) {
            return indexes;
        }

        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(target - nums[i]) != hash.end()) {
                indexes.push_back(hash[target - nums[i]]);
                indexes.push_back(i);
                sort(indexes.begin(), indexes.end());
                return indexes;
            }
            hash[nums[i]] = i;
        }

        return indexes;
    }
};
