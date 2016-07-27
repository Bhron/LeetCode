/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int deepestLevel = getDeepestLevel(nestedList, 1);

        return getDepthSum(nestedList, deepestLevel);
    }
private:
    int getDeepestLevel(vector<NestedInteger>& nestedList, int currentLevel) {
        int deepestLevel = currentLevel;

        for (int i = 0; i < nestedList.size(); i++) {
            if (!nestedList[i].isInteger()) {
                int level = getDeepestLevel(nestedList[i].getList(), currentLevel + 1);
                if (level > deepestLevel) {
                    deepestLevel = level;
                }
            }
        }

        return deepestLevel;
    }

    int getDepthSum(vector<NestedInteger>& nestedList, int currentLevel) {
        int sum = 0;
        for (int i = 0; i < nestedList.size(); i++) {
            if (!nestedList[i].isInteger()) {
                sum += getDepthSum(nestedList[i].getList(), currentLevel - 1);
            } else {
                sum += nestedList[i].getInteger() * currentLevel;
            }
        }

        return sum;
    }
};
