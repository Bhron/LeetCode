class Solution {
    func containsDuplicate(nums: [Int]) -> Bool {
        if nums.isEmpty {
            return false
        }

        var dict = [Int : Int]()
        for num in nums {
            if let count = dict[num] {
                return true
            } else {
                dict[num] = 1
            }
        }

        return false
    }
}
