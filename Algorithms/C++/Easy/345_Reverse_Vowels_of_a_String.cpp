class Solution {
public:
    string reverseVowels(string s) {
        if (s.empty()) {
            return s;
        }
        
        int start = 0, end = s.length() - 1;
        while (start < end) {
            while (start < end) {
                char c = tolower(s[start]);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    break;
                } else {
                    start++;
                }
            }
            
            while (start < end) {
                char c = tolower(s[end]);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    break;
                } else {
                    end--;
                }
            }
            
            if (start < end) {
                char tmp = s[start];
                s[start] = s[end];
                s[end] = tmp;
                
                start++;
                end--;
            } else {
                break;
            }
        }
        
        return s;
    }
};
