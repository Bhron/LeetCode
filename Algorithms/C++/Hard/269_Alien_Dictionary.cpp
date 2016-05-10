class Solution {
public:
    string alienOrder(vector<string>& words) {
        string order;

        vector<DirectedGraphNode*> nodes = constructGraph(words);

        int counter = 0;
        queue<DirectedGraphNode*> q;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i]->exist) {
                counter++;
                if (nodes[i]->indegree == 0) {
                    q.push(nodes[i]);
                }
            }
        }

        while (!q.empty()) {
            DirectedGraphNode* node = q.front();
            q.pop();
            order += node->label;

            for (const auto& neighbor: node->neighbors) {
                int index = neighbor - 'a';
                nodes[index]->indegree--;
                if (nodes[index]->indegree == 0) {
                    q.push(nodes[index]);
                }
            }
        }

        if (order.length() != counter) {
            return "";
        }
        return order;
    }

private:
    class DirectedGraphNode {
    public:
        char label;
        unordered_set<char> neighbors;
        int indegree;
        bool exist;

        DirectedGraphNode(char label) : label(label), indegree(0), exist(false) { }
    };

    vector<DirectedGraphNode*> constructGraph(const vector<string>& words) {
        vector<DirectedGraphNode*> nodes;
        for (int i = 0; i < 26; i++) {
            nodes.push_back(new DirectedGraphNode(i + 'a'));
        }

        for (int i = 0; i < words.size(); i++) {
            const string& word = words[i];
            for (int j = 0; j < word.length(); j++) {
                nodes[word[j] - 'a']->exist = true;
            }

            if (i > 0) {
                int len = min(words[i - 1].length(), words[i].length());
                int j;
                char c1, c2;
                for (j = 0; j < len; j++) {
                    if (words[i - 1][j] != words[i][j]) {
                        c1 = words[i - 1][j];
                        c2 = words[i][j];
                        break;
                    }
                }

                if (j < len) {
                    unordered_set<char>& neighbors = nodes[c1 - 'a']->neighbors;
                    if (neighbors.find(c2) == neighbors.end()) {
                        neighbors.insert(c2);
                        nodes[c2 - 'a']->indegree++;
                    }
                }
            }
        }

        return nodes;
    }
};
