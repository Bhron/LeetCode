class Solution {
    func findMin(nums: [Int]) -> Int {
        if nums.isEmpty {
            return 0
        }

        var minElement = nums[0]
        for elem in nums {
            if elem < minElement {
                minElement = elem
            }
        }

        return minElement
    }
}
