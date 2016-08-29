/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    if (nums.length === 0) {
        return 0
    }
    
    var start = 0, end = nums.length - 1
    
    while (start + 1 < end) {
        var mid = start + Math.floor((end - start) / 2)
        if (nums[mid] >= target) {
            end = mid
        } else {
            start = mid
        }
    }
    
    if (nums[start] >= target) {
        return start
    } else if (nums[end] >= target) {
        return end
    }
    return nums.length
};
