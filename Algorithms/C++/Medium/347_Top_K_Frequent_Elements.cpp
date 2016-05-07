class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> elems;

        if (nums.empty() || k <= 0) {
            return elems;
        }
        if (nums.size() <= k) {
            elems = nums;
            return elems;
        }

        unordered_map<int, int> num_frequent;
        for (int i = 0; i < nums.size(); i++) {
            num_frequent[nums[i]]++;
        }

        priority_queue<Element, vector<Element>, Comparator> pq;
        for (auto it : num_frequent) {
            int val = it.first;
            int frequent = it.second;

            if (pq.size() < k) {
                pq.push(Element(val, frequent));
            } else {
                Element min_elem = pq.top();
                if (min_elem.frequent < frequent) {
                    pq.pop();
                    pq.push(Element(val, frequent));
                }
            }
        }

        while (!pq.empty()) {
            Element elem = pq.top();
            pq.pop();

            elems.push_back(elem.val);
        }

        return elems;
    }
private:
    class Element {
    public:
        int val;
        int frequent;

        Element(int val, int frequent) {
            this->val = val;
            this->frequent = frequent;
        }
    };

    class Comparator {
    public:
        bool operator () (const Element& left, const Element& right) {
            return left.frequent > right.frequent;
        }
    };
};
