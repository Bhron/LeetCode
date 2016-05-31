class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersections;

        if (nums1.empty() && nums2.empty()) {
            return intersections;
        }

        unordered_set<int> hash;
        for (int i = 0; i < nums1.size(); i++) {
            hash.insert(nums1[i]);
        }

        unordered_set<int> unique_result;
        for (int i = 0; i < nums2.size(); i++) {
            if (hash.find(nums2[i]) != hash.end()) {
                unique_result.insert(nums2[i]);
            }
        }

        for (auto const& elem: unique_result) {
            intersections.push_back(elem);
        }

        return intersections;
    }
};
