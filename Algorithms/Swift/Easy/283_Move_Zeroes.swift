class Solution {
    func moveZeroes(inout nums: [Int]) {
        var i = 0, j = 0
        while j < nums.count {
            if nums[j] != 0 {
                nums[i] = nums[j]
                i += 1
            }
            j += 1
        }

        while i < nums.count {
            nums[i] = 0
            i += 1
        }
    }
}
