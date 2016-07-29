class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;

        if (nums.empty()) {
            return ranges;
        }

        int i = 0;
        while (i < nums.size()) {
            int begin = nums[i];
            int end = nums[i];

            for (i++; i < nums.size() && nums[i] == nums[i - 1] + 1; i++) {
                end = nums[i];
            }

            string range;
            if (begin == end) {
                range = to_string(begin);
            } else {
                range = to_string(begin) + "->" + to_string(end);
            }
            ranges.push_back(range);
        }

        return ranges;
    }
};
