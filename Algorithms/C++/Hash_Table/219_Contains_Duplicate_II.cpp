class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty()) {
            return false;
        }

        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = i;
            } else {
                int index = map[nums[i]];
                if (i - index <= k) {
                    return true;
                } else {
                    map[nums[i]] = i;
                }
            }
        }

        return false;
    }
};
