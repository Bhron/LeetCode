class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        counter++;

        if (counter % 2 == 1) {
            if (max_heap.empty() || num <= min_heap.top()) {
                max_heap.push(num);
            } else {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
        } else {
            if (num >= max_heap.top()) {
                min_heap.push(num);
            } else {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (counter % 2 == 1) {
            return max_heap.top();
        } else {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
    }
private:
    priority_queue<int> max_heap;
    priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    int counter = 0;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
