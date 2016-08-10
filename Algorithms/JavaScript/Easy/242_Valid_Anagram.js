// Hash Table
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if (s.length === 0) {
        if (t.length === 0) {
            return true
        } else {
            return false
        }
    }

    if (s.length != t.length) {
        return false
    }

    var hash = {}
    for (i = 0; i < s.length; i++) {
        let character = s[i]
        if (!hash[character]) {
            hash[character] = 1
        } else {
            hash[character] += 1
        }
    }

    for (i = 0; i < t.length; i++) {
        let character = t[i]
        if (!hash[character]) {
            return false
        } else if (hash[character] === 0) {
            return false
        }
        hash[character] -= 1
    }
    return true
};

// Sort
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if (s.length === 0) {
        if (t.length === 0) {
            return true
        } else {
            return false
        }
    }

    if (s.length != t.length) {
        return false
    }

    s = s.split("").sort(strCompare).join("")
    t = t.split("").sort(strCompare).join("")

    return s === t
};

function strCompare(str1, str2) {
    return str1.localeCompare(str2)
}
