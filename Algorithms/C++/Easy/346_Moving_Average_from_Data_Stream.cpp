class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        while (!q.empty()) {
            q.pop();
        }
        window_size = size;
        sum = 0;
    }
    
    double next(int val) {
        if (q.size() < window_size) {
            q.push(val);
            sum += val;
        } else {
            int prev_elem = q.front();
            q.pop();
            sum -= prev_elem;
            
            q.push(val);
            sum += val;
        }
        
        
        return (double)sum / window_size;
    }
private:
    queue<int> q;
    int window_size;
    int sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
