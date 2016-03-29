class Solution {
    func subsetsWithDup(nums: [Int]) -> [[Int]] {
        var allSubsets = [[Int]]()

        if nums.isEmpty {
            return allSubsets
        }

        var sortedNums = nums
        sortedNums.sortInPlace()
        var currentSubset = [Int]()

        helper(&allSubsets, &currentSubset, sortedNums, 0)

        return allSubsets
    }

    private func helper(inout allSubsets: [[Int]], inout _ currentSubset: [Int], _ nums: [Int], _ position: Int) {
        allSubsets.append(currentSubset)

        for var i = position; i < nums.count; i++ {
            if i > position && nums[i] == nums[i - 1] {
                continue
            }

            currentSubset.append(nums[i])
            helper(&allSubsets, &currentSubset, nums, i + 1)
            currentSubset.removeLast()
        }
    }
}
