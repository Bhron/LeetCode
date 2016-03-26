class Solution {
    func longestCommonPrefix(strs: [String]) -> String {
        if strs.isEmpty {
            return ""
        }

        var commonPrefix = ""

        var minLength = Int.max
        for str in strs {
            if str.characters.count < minLength {
                minLength = str.characters.count
            }
        }

        for var i = 0; i < minLength; i++ {
            let ch = strs[0][i]

            var j = 1;
            for ; j < strs.count && strs[j][i] == ch; j++ {

            }

            if j == strs.count {
                commonPrefix.append(ch)
            } else {
                return commonPrefix
            }
        }

        return commonPrefix;
    }
}

extension String {
    subscript(i: Int) -> Character {
        return self[self.startIndex.advancedBy(i)]
    }
}
