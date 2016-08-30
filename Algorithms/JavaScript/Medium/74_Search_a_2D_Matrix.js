/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    var m = matrix.length
    if (m === 0) {
        return false
    }
    
    var n = matrix[0].length
    if (n === 0) {
        return false
    }
    
    var start = 0, end = m * n - 1
    while (start + 1 < end) {
        var mid = start + Math.floor((end - start) / 2)
        var row = Math.floor(mid / n)
        var column = mid % n
        
        var value = matrix[row][column]
        if (value === target) {
            return true
        } else if (value < target) {
            start = mid
        } else {
            end = mid
        }
    }
    
    if (matrix[Math.floor(start / n)][start % n] === target) {
        return true
    }
    if (matrix[Math.floor(end / n)][end % n] === target) {
        return true
    }
    return false
};
