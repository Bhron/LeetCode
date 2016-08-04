class Solution {
    func findMissingRanges(nums: [Int], _ lower: Int, _ upper: Int) -> [String] {
        var ranges = [String]()
        
        if lower > upper {
            return ranges
        }
        
        if nums.isEmpty {
            return [getRange(lower, upper)!]
        }
        
        var start = lower, end = nums[0] - 1
        if let range = getRange(start, end) {
            ranges.append(range)
        }
        
        for index in 0..<nums.count - 1 {
            start = nums[index] + 1
            end   = nums[index + 1] - 1
            
            if let range = getRange(start, end) {
                ranges.append(range)
            }
        }
        
        start = nums[nums.count - 1] + 1
        end = upper
        if let range = getRange(start, end) {
            ranges.append(range)
        }
        
        return ranges
    }
    
    private func getRange(start: Int, _ end: Int) -> String? {
        if start > end {
            return nil
        } else if start == end {
            return String(start)
        } else {
            return "\(start)->\(end)"
        }
    }
}
