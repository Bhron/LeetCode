// Hash Table, Time Complexity O(n)
class Solution {
    func isAnagram(s: String, _ t: String) -> Bool {
        if s.characters.count != t.characters.count {
            return false
        }

        var dict = [Character : Int]()
        for character in s.characters {
            if dict[character] != nil {
                dict[character]! += 1
            } else {
                dict[character] = 1
            }
        }

        for character in t.characters {
            if dict[character] == nil {
                return false
            } else {
                dict[character]! -= 1
            }
        }

        for counter in dict.values {
            if counter != 0 {
                return false
            }
        }

        return true
    }
}
