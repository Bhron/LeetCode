class Solution {
    func combine(n: Int, _ k: Int) -> [[Int]] {
        var combinations = [[Int]]()

        if n <= 0 || n < k {
            return combinations
        }

        var nums = [Int]()
        for i in 1...n {
            nums.append(i)
        }

        var currentCombination = [Int]()
        helper(&combinations, &currentCombination, 0, nums, k)

        return combinations
    }

    private func helper(inout combinations: [[Int]], inout _ currentCombination: [Int], _ position: Int, _ nums: [Int], _ k: Int) {
        if k == 0 {
            combinations.append(currentCombination)
            return
        }

        for var i = position; i < nums.count; i++ {
            currentCombination.append(nums[i])
            helper(&combinations, &currentCombination, i + 1, nums, k - 1)
            currentCombination.removeLast()
        }
    }
}
