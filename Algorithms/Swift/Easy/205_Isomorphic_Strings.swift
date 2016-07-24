class Solution {
    func isIsomorphic(s: String, _ t: String) -> Bool {
        if s.isEmpty && t.isEmpty {
            return true
        } else if s.isEmpty || t.isEmpty {
            return false
        } else if s.characters.count != t.characters.count {
            return false
        }

        let tStartIndex = t.characters.startIndex

        var dict = [Character : Character]()
        var set = Set<Character>()

        var mappedS = ""
        for (index, character) in s.characters.enumerate() {
            if let mappedCharacter = dict[character] {
                mappedS += String(mappedCharacter)
            } else {
                let tCharacter = t.characters[tStartIndex.advancedBy(index)]
                if set.contains(tCharacter) {
                    return false
                }

                dict[character] = tCharacter
                set.insert(tCharacter)

                mappedS += String(tCharacter)
            }
        }

        return t == mappedS
    }
}
