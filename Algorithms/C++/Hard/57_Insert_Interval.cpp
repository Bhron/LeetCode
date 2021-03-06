/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;

        if (intervals.empty()) {
            result.push_back(newInterval);
            return result;
        }

        int insert_index = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].end < newInterval.start) {
                result.push_back(intervals[i]);
                insert_index++;
            } else if (intervals[i].start > newInterval.end) {
                result.push_back(intervals[i]);
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }

        auto it = result.begin();
        result.insert(it + insert_index, newInterval);

        return result;
    }
};
