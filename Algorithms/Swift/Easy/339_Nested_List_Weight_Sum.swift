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
    func depthSum(nestedList: [NestedInteger]) -> Int {
        return depthSumForList(nestedList, atDepth: 1)
    }

    private func depthSumForList(nestedList: [NestedInteger], atDepth depth: Int) -> Int {
        if nestedList.isEmpty {
            return 0
        }

        var sum = 0
        for item in nestedList {
            if item.isInteger() {
                sum += item.getInteger() * depth
            } else {
                sum += depthSumForList(item.getList(), atDepth: depth + 1)
            }
        }

        return sum
    }
}
