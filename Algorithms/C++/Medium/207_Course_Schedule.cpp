// BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses <= 1 || prerequisites.size() <= 1) {
            return true;
        }

        vector<DirectedGraphNode*> nodes = construct_graph(numCourses, prerequisites);

        queue<DirectedGraphNode*> q;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i]->indegree == 0) {
                q.push(nodes[i]);
            }
        }

        vector<int> courses;
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

        return courses.size() == numCourses;
    }

private:
    class DirectedGraphNode {
    public:
        int label;
        unordered_set<int> neighbors;
        int indegree;

        DirectedGraphNode(int label) : label(label), indegree(0) { }
    };

    vector<DirectedGraphNode*> construct_graph(const int n, const vector<pair<int, int>>& prerequisites) {
        vector<DirectedGraphNode*> nodes;
        for (int i = 0; i < n; i++) {
            nodes.push_back(new DirectedGraphNode(i));
        }

        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i].first;
            int prerequisite = prerequisites[i].second;

            unordered_set<int>& neighbors = nodes[prerequisite]->neighbors;
            if (neighbors.find(course) == neighbors.end()) {
                neighbors.insert(course);
                nodes[course]->indegree++;
            }
        }

        return nodes;
    }
};

// DFS
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses <= 1 || prerequisites.size() <= 1) {
            return true;
        }

        vector<DirectedGraphNode*> nodes = construct_graph(numCourses, prerequisites);

        vector<int> visited(numCourses, 0);
        for (int i = 0; i < nodes.size(); i++) {
            DirectedGraphNode* node = nodes[i];
            if (visited[node->label] == 0) {
                if (DFS(nodes, visited, node) == false) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    class DirectedGraphNode {
    public:
        int label;
        unordered_set<int> neighbors;

        DirectedGraphNode(int label) : label(label) { }
    };

    vector<DirectedGraphNode*> construct_graph(const int n, const vector<pair<int, int>>& prerequisites) {
        vector<DirectedGraphNode*> nodes;
        for (int i = 0; i < n; i++) {
            nodes.push_back(new DirectedGraphNode(i));
        }

        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i].first;
            int prerequisite = prerequisites[i].second;
            nodes[prerequisite]->neighbors.insert(course);
        }

        return nodes;
    }

    bool DFS(vector<DirectedGraphNode*>& nodes, vector<int>& visited, DirectedGraphNode* node) {
        visited[node->label] = -1;

        for (const auto& neighbor: node->neighbors) {
            if (visited[neighbor] == -1) {
                return false;
            } else if (visited[neighbor] == 0) {
                if (DFS(nodes, visited, nodes[neighbor]) == false) {
                    return false;
                }
            }
        }

        visited[node->label] = 1;

        return true;
    }
};
