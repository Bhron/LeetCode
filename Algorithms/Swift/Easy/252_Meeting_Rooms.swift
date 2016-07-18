/**
 * Definition for an interval.
 * public class Interval {
 *   public var start: Int
 *   public var end: Int
 *   public init(_ start: Int, _ end: Int) {
 *     self.start = start
 *     self.end = end
 *   }
 * }
 */
class Solution {
    func canAttendMeetings(intervals: [Interval]) -> Bool {
        if intervals.isEmpty {
            return true
        }

        let sortedIntervals = intervals.sort { $0.start < $1.start }

        for i in 0..<sortedIntervals.count - 1 {
            let before = sortedIntervals[i]
            let after = sortedIntervals[i + 1]

            if before.end > after.start {
                return false
            }
        }

        return true
    }
}
