class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> indexes;

        if (numbers.empty()) {
            return indexes;
        }

        int start = 0, end = numbers.size() - 1;
        while (start < end) {
            int sum = numbers[start] + numbers[end];

            if (sum == target) {
                indexes.push_back(start + 1);
                indexes.push_back(end + 1);
                return indexes;
            } else if (sum < target) {
                start++;
            } else {
                end--;
            }
        }

        return indexes;
    }
};
