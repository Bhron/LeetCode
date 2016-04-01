class Solution {
    func isValid(s: String) -> Bool {
        if s.isEmpty {
            return true
        }

        var stack = [Character]()

        for c in s.characters {
            switch c {
            case "(", "{", "[":
                stack.append(c);
            case ")":
                let bracket = stack.last
                if bracket == nil || bracket! != "(" {
                    return false
                } else {
                    stack.removeLast()
                }
            case "}":
                let bracket = stack.last
                if bracket == nil || bracket! != "{" {
                    return false
                } else {
                    stack.removeLast()
                }
            case "]":
                let bracket = stack.last
                if bracket == nil || bracket! != "[" {
                    return false
                } else {
                    stack.removeLast()
                }
            default:
                break
            }
        }

        return stack.isEmpty
    }
}
