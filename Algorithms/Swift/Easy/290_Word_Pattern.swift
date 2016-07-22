class Solution {
    func wordPattern(pattern: String, _ str: String) -> Bool {
        if pattern.isEmpty || str.isEmpty {
            return false
        }

        var words = str.characters.split { $0 == " " }.map(String.init)

        if pattern.characters.count != words.count {
            return false
        }

        var dict = [String : String]()
        var set = Set<String>()
        for (index, character) in pattern.characters.enumerate() {
            let letter = String(character)
            let word = words[index]

            if dict[letter] == nil {
                if set.contains(word) {
                    return false
                } else {
                    dict[letter] = word
                    set.insert(word)
                }
            } else if dict[letter]! != word {
                return false
            }
        }

        return true
    }
}
