class Solution {
    func isStrobogrammatic(num: String) -> Bool {
        let map: [Character : Character] = ["0" : "0", "1" : "1", "6" : "9", "8" : "8", "9" : "6"]

        var start = 0, end = num.characters.count - 1
        let startIndex = num.characters.startIndex

        while start <= end {
            let startCharacter = num.characters[startIndex.advancedBy(start)]
            guard let mappedCharacter = map[startCharacter] else {
                return false
            }

            if mappedCharacter != num.characters[startIndex.advancedBy(end)] {
                return false
            }

            start += 1
            end -= 1
        }

        return true
    }
}
