class Solution {
public:
    string removeDuplicateLetters(string s) {

        unordered_map<char, int> umpp;
        unordered_map<char, int> umpp2;
        string r;
        stack<char> st;
        for (auto it : s) {
            umpp[it]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (umpp2[s[i]] != 0) {
                umpp[s[i]]--;
                continue;
            }

            while (!st.empty() && st.top() > s[i] && umpp[st.top()] > 0) {
                umpp2[st.top()]--;
                st.pop();
            }

            st.push(s[i]);
            umpp2[s[i]]++;
            umpp[s[i]]--;
        }
        while (!st.empty()) {
            r += st.top();

            st.pop();
        }
        reverse(r.begin(), r.end());
        return r;
    
    }
};