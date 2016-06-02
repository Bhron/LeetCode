class NumArray {
public:
    NumArray(vector<int> &nums) {
        prefixSums.clear();

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            prefixSums.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if (i > 0) {
             return prefixSums[j] - prefixSums[i - 1];
        } else {
            return prefixSums[j];
        }
    }
private:
    vector<int> prefixSums;
};
