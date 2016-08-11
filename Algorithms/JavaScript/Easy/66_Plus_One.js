/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    if (digits.length === 0) {
        return [1]
    }
    
    var carry = 1
    for (var i = digits.length - 1; i >= 0; i--) {
        digits[i] += carry
        carry = Math.floor(digits[i] / 10)
        digits[i] %= 10
    }
    
    if (carry === 0) {
        return digits
    }
    
    digits[0] %= 10
    digits.unshift(1)
    return digits
};
