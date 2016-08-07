class Solution {
    func convert(s: String, _ numRows: Int) -> String {
        if s.isEmpty || numRows <= 1 {
            return s
        }

        var result = ""
        var rows = [String](count: numRows, repeatedValue: "")

        let cycle = numRows + numRows - 2
        for (index, character) in s.characters.enumerate() {
            let rowIndex = index % cycle
            if rowIndex < numRows {
                rows[rowIndex] += String(character)
            } else {
                rows[cycle - rowIndex] += String(character)
            }
        }

        for row in rows {
            result += row
        }

        return result
    }
}
