class Solution {
    func permuteUnique(nums: [Int]) -> [[Int]] {
        var permutations = [[Int]]()

        if nums.isEmpty {
            return permutations
        }

        var sortedNums = nums
        sortedNums.sortInPlace()

        var selected = [Bool](count: nums.count, repeatedValue: false)
        var currentPermutation = [Int]()

        helper(&permutations, &currentPermutation, &selected, sortedNums)

        return permutations
    }

    private func helper(inout permutations: [[Int]], inout _ currentPermutation: [Int], inout _ selected: [Bool], _ nums: [Int]) {
        if currentPermutation.count == nums.count {
            permutations.append(currentPermutation)
            return
        }

        for var i = 0; i < nums.count; i++ {
            if selected[i] == true {
                continue
            }

            if i > 0 && nums[i] == nums[i - 1] && !selected[i - 1] {
                continue
            }

            currentPermutation.append(nums[i])
            selected[i] = true
            helper(&permutations, &currentPermutation, &selected, nums)
            selected[i] = false
            currentPermutation.removeLast()
        }
    }
}
