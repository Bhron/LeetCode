class Solution {
    func findPeakElement(nums: [Int]) -> Int {
        var start = 0, end = nums.count - 1
        while start + 1 < end {
            let mid = start + (end - start) / 2
            if nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1] {
                return mid
            } else if nums[mid - 1] > nums[mid] {
                end = mid
            } else {
                start = mid
            }
        }

        if nums[start] > nums[end] {
            return start
        }
        return end
    }
}
