class Solution {
    func removeElement(inout nums: [Int], _ val: Int) -> Int {
        if nums.isEmpty {
            return 0
        }
        
        var j = 0
        for i in 0..<nums.count {
            if nums[i] != val {
                nums[j] = nums[i]
                j += 1
            }
        }
        
        return j
    }
}
