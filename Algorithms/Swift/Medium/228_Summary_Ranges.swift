class Solution {
    func summaryRanges(nums: [Int]) -> [String] {
        var ranges = [String]()
        
        if nums.isEmpty {
            return ranges
        }
        
        var i = 0
        while i < nums.count {
            var start = nums[i]
            var end = start
            
            i += 1
            while i < nums.count && nums[i] == nums[i - 1] + 1 {
                end = nums[i]
                i += 1
            }
            
            if end == start {
                ranges.append(String(start))
            } else {
                ranges.append(String(start) + "->" + String(end))
            }
        }
        
        return ranges
    }
}
