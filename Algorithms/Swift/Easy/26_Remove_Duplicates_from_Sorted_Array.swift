class Solution {
    func removeDuplicates(inout nums: [Int]) -> Int {
        if nums.isEmpty {
            return 0
        }

        var len = 0;
        for i in 1..<nums.count {
            if nums[i] != nums[len] {
                len += 1
                nums[len] = nums[i]
            }
        }

        return len + 1
    }
}
