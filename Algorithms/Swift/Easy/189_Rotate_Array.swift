class Solution {
    func rotate(inout nums: [Int], _ k: Int) {
        if nums.isEmpty {
            return
        }

        let stepsToRotate = k % nums.count
        if stepsToRotate == 0 {
            return
        }

        rotateArray(&nums, from: 0, to: nums.count - stepsToRotate - 1)
        rotateArray(&nums, from: nums.count - stepsToRotate, to: nums.count - 1)
        rotateArray(&nums, from: 0, to: nums.count - 1)
    }

    private func rotateArray(inout nums: [Int], from startIndex: Int, to endIndex: Int) {
        if startIndex >= endIndex {
            return
        }

        var start = startIndex, end = endIndex
        while start < end {
            let tmp = nums[start]
            nums[start] = nums[end]
            nums[end] = tmp

            start += 1
            end -= 1
        }
    }
}
