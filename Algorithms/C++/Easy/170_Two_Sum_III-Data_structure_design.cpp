class TwoSum {
public:
    TwoSum() {
        hash.clear();
    }

    // Add the number to an internal data structure.
    void add(int number) {
        hash[number]++;
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for (auto it: hash) {
            int num = it.first;
            int target = value - num;
            if (hash.find(target) != hash.end()) {
                if (target != num || it.second >= 2) {
                    return true;
                }
            }
        }

        return false;
    }
private:
    unordered_map<int, int> hash;
};

// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
