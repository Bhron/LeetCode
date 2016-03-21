class MinStack {
public:
    void push(int x) {
        if (min_s.empty() || x <= min_s.top()) {
            min_s.push(x);
        }
        s.push(x);
    }

    void pop() {
        int val = s.top();

        if (min_s.top() == val) {
            min_s.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min_s.top();
    }
private:
    stack<int> s;
    stack<int> min_s;
};
