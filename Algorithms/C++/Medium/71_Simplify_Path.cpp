class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) {
            return "";
        }

        vector<string> pathComponents = split(path, '/');

        stack<string> reversePathStack;
        for (int i = 0; i < pathComponents.size(); i++) {
            string component = pathComponents[i];
            if (component == ".") {
                ;
            } else if (component == "..") {
                if (!reversePathStack.empty()) {
                    reversePathStack.pop();
                }
            } else {
                reversePathStack.push(component);
            }
        }

        if (reversePathStack.empty()) {
            return "/";
        }

        stack<string> pathStack;
        while (!reversePathStack.empty()) {
            pathStack.push(reversePathStack.top());
            reversePathStack.pop();
        }

        string simplifiedPath = "";
        while (!pathStack.empty()) {
            simplifiedPath += "/" + pathStack.top();
            pathStack.pop();
        }

        return simplifiedPath;
    }

private:
    vector<string> split(const string &str, char delimiter) {
        vector<string> strs;

        stringstream ss(str);
        string item;

        while (getline(ss, item, delimiter)) {
            if (!item.empty()) {
                strs.push_back(item);
            }
        }

        return strs;
    }
};
