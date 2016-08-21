/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    if (haystack === "" || needle === "") {
        if (needle === "") {
            return 0
        } else if (haystack === "") {
            return -1
        }
    }

    if (haystack.length < needle.length) {
        return -1
    }

    var index
    for (index = 0; index <= haystack.length - needle.length; index++) {
        var i
        for (i = 0; i < needle.length && haystack[index + i] === needle[i]; i++) ;

        if (i === needle.length) {
            return index
        }
    }

    return -1
};
