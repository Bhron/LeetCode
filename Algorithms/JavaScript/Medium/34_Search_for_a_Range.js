/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    var positions = [-1, -1]

    if (nums.length === 0) {
        return positions
    }

    var start = 0, end = nums.length - 1, mid
    while (start + 1 < end) {
        mid = start + Math.floor((end - start) / 2)
        if (nums[mid] >= target) {
            end = mid
        } else {
            start = mid
        }
    }

    if (nums[start] === target) {
        positions[0] = start
    } else if (nums[end] === target) {
        positions[0] = end
    } else {
        return positions
    }

    start = positions[0], end = nums.length - 1
    while (start + 1 < end) {
        mid = start + Math.floor((end - start) / 2)
        if (nums[mid] <= target) {
            start = mid
        } else {
            end = mid
        }
    }

    if (nums[end] === target) {
        positions[1] = end
    } else {
        positions[1] = start
    }
    return positions
};
