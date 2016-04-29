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
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), compare);

        int new_size = intervals.size();
        for (int i = 0, j = 1; j < intervals.size(); j++) {
            if (intervals[j].start <= intervals[i].end) {
                intervals[i].end = max(intervals[i].end, intervals[j].end);
                new_size--;
            } else {
                intervals[++i] = intervals[j];
            }
        }

        int old_size = intervals.size();
        for (int i = 0; i < old_size - new_size; i++) {
            intervals.pop_back();
        }

        return intervals;
    }
private:
    static bool compare(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
};
