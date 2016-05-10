class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> courses;

        if (numCourses <= 0) {
            return courses;
        }

        vector<DirectedGraphNode*> nodes = constructGraph(numCourses, prerequisites);

        queue<DirectedGraphNode*> q;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i]->indegree == 0) {
                q.push(nodes[i]);
            }
        }

        while (!q.empty()) {
            DirectedGraphNode* node = q.front();
            q.pop();
            courses.push_back(node->label);

            for (const auto& neighbor: node->neighbors) {
                nodes[neighbor]->indegree--;
                if (nodes[neighbor]->indegree == 0) {
                    q.push(nodes[neighbor]);
                }
            }
        }

        if (courses.size() != numCourses) {
            return vector<int>();
        }
        return courses;
    }

private:
    class DirectedGraphNode {
    public:
        int label;
        unordered_set<int> neighbors;
        int indegree;

        DirectedGraphNode(int label) : label(label), indegree(0) { }
    };

    vector<DirectedGraphNode*> constructGraph(int n, const vector<pair<int, int>>& prerequisites) {
        vector<DirectedGraphNode*> nodes;
        for (int i = 0; i < n; i++) {
            nodes.push_back(new DirectedGraphNode(i));
        }

        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i].first;
            int prerequisite = prerequisites[i].second;

            auto& neighbors = nodes[prerequisite]->neighbors;
            if (neighbors.find(course) == neighbors.end()) {
                neighbors.insert(course);
                nodes[course]->indegree++;
            }
        }

        return nodes;
    }
};
