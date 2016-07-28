class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> missingRanges;

        if (lower > upper) {
            return missingRanges;
        }

        if (nums.empty()) {
            missingRanges.push_back(getRange(lower, upper));
            return missingRanges;
        }

        int left, right;
        string range;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            left = i == 0 ? lower : nums[i - 1] + 1;
            right = num - 1;

            range = getRange(left, right);
            if (!range.empty()) {
                missingRanges.push_back(range);
            }
        }

        if (nums[nums.size() - 1] < upper) {
            left = nums[nums.size() - 1] + 1;
            right = upper;

            range = getRange(left, right);
            if (!range.empty()) {
                missingRanges.push_back(range);
            }
        }

        return missingRanges;
    }
private:
    string getRange(int left, int right) {
        if (left > right) {
            return "";
        } else if (left == right) {
            return to_string(left);
        } else {
            return to_string(left) + "->" + to_string(right);
        }
    }
};
