class Solution {
    func searchMatrix(matrix: [[Int]], _ target: Int) -> Bool {
        if matrix.isEmpty || matrix[0].isEmpty {
            return false
        }

        let m = matrix.count, n = matrix[0].count

        var start = 0, end = m * n - 1
        while start + 1 < end {
            let mid = start + (end - start) / 2
            let x = mid / n, y = mid % n
            if matrix[x][y] == target {
                return true
            } else if matrix[x][y] < target {
                start = mid
            } else {
                end = mid
            }
        }

        if matrix[start / n][start % n] == target || matrix[end / n][end % n] == target {
            return true
        }
        return false
    }
}
