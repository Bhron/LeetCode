class Solution {
    func searchRange(nums: [Int], _ target: Int) -> [Int] {
        var positions = [Int](count: 2, repeatedValue: -1)

        if nums.isEmpty {
            return positions
        }

        var start = 0, end = nums.count - 1
        while start + 1 < end {
            let mid = start + (end - start) / 2
            if nums[mid] >= target {
                end = mid
            } else {
                start  = mid
            }
        }

        if nums[start] == target {
            positions[0] = start
        } else if nums[end] == target {
            positions[0] = end
        }

        if positions[0] == -1 {
            return positions
        }

        start = positions[0]
        end = nums.count - 1
        while start + 1 < end {
            let mid = start + (end - start) / 2
            if nums[mid] <= target {
                start = mid
            } else {
                end  = mid
            }
        }

        if nums[end] == target {
            positions[1] = end
        } else {
            positions[1] = start
        }

        return positions
    }
}
