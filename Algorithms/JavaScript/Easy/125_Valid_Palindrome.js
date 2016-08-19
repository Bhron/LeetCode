/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    if (s.length === 0) {
        return true
    }

    var start = 0, end = s.length - 1
    while (start < end) {
        if (!isAlphanumeric(s[start])) {
            start++
        } else if (!isAlphanumeric(s[end])) {
            end--
        } else if (s[start].toLowerCase() != s[end].toLowerCase()) {
            return false
        } else {
            start++
            end--
        }
    }

    return true
};

var isAlphanumeric = function(c) {
    return /^[a-z0-9]+$/i.test(c)
}
