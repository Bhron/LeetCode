class Solution {
    func merge(inout nums1: [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        var end = m + n - 1

        var i = m - 1, j = n - 1
        while i >= 0 && j >= 0 {
            if nums1[i] < nums2[j] {
                nums1[end] = nums2[j]
                j -= 1
            } else {
                nums1[end] = nums1[i]
                i -= 1
            }
            end -= 1
        }

        while j >= 0 {
            nums1[end] = nums2[j]
            end -= 1
            j -= 1
        }
    }
}
