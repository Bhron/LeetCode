class Solution {
    func combinationSum(candidates: [Int], _ target: Int) -> [[Int]] {
        var combinations = [[Int]]()

        if candidates.isEmpty {
            return combinations
        }

        var sortedCandidates = candidates
        sortedCandidates.sortInPlace()

        var currentCombination = [Int]()
        helper(&combinations, &currentCombination, 0, sortedCandidates, target)

        return combinations
    }

    private func helper(inout combinations: [[Int]], inout _ currentCombination: [Int], _ position: Int, _ candidates: [Int], _ target: Int) {
        if target == 0 {
            combinations.append(currentCombination)
            return
        }

        var previous: Int! = nil
        for var i = position; i < candidates.count; i++ {
            if candidates[i] > target {
                return
            }

            if previous != nil && previous == candidates[i] {
                continue
            }

            currentCombination.append(candidates[i])
            helper(&combinations, &currentCombination, i, candidates, target - candidates[i])
            currentCombination.removeLast()

            previous = candidates[i]
        }
    }
}
