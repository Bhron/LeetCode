/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public func isInteger() -> Bool
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     public func getInteger() -> Int
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     public func getList() -> [NestedInteger]
 * }
 */
class Solution {
    func depthSumInverse(nestedList: [NestedInteger]) -> Int {
        if nestedList.isEmpty {
            return 0
        }

        let deepestLevel = getDeepestLevelFor(nestedList, withCurrentLevel: 1)

        return getDepthSumFor(nestedList, withCurrentLevel: deepestLevel)
    }

    private func getDeepestLevelFor(nestedList: [NestedInteger], withCurrentLevel currentLevel: Int) -> Int {
        var deepestLevel = currentLevel

        for item in nestedList {
            if !item.isInteger() {
                let level = getDeepestLevelFor(item.getList(), withCurrentLevel: currentLevel + 1)
                if level > deepestLevel {
                    deepestLevel = level
                }
            }
        }

        return deepestLevel
    }

    private func getDepthSumFor(nestedList: [NestedInteger], withCurrentLevel currentLevel: Int) -> Int {
        var sum = 0

        for item in nestedList {
            if item.isInteger() {
                sum += item.getInteger() * currentLevel
            } else {
                sum += getDepthSumFor(item.getList(), withCurrentLevel: currentLevel - 1)
            }
        }

        return sum
    }
}
