class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> IPAddresses;
        
        if (s.empty()) {
            return IPAddresses;
        }
        
        helper(s, "", 0, 0, IPAddresses);
        
        return IPAddresses;
    }
private:
    void helper(const string& s, string cur, int pos, int count, vector<string>& IPAddresses) {
        if (pos >= s.length() || count > 3) {
            return;
        }
        
        if (count == 3) {
            if (s.length() - pos > 3) {
                return;
            }
            
            string num = s.substr(pos, s.length() - pos);
            if (!(num.length() > 1 && num[0] == '0') && (stoi(num) <= 255)) {
                cur += num;
                IPAddresses.push_back(cur);
            }
            return;
        }
        
        for (int i = 1; i <= 3; i++) {
            if (pos + i >= s.length()) {
                break;
            }
            
            string num = s.substr(pos, i);
            if (!(num.length() > 1 && num[0] == '0') && (stoi(num) <= 255)) {
                helper(s, cur + num + ".", pos + i, count + 1, IPAddresses);
            }
        }
    }
};
