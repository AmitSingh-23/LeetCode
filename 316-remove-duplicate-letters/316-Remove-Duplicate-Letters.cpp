class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_map<char, int> umpp;
        unordered_map<char, bool> used;

        for (int i = 0; i < s.length(); i++) {
            umpp[s[i]]++;
        }

        for (int i = 0; i < s.length(); i++) {

            umpp[s[i]]--;

            if (used[s[i]])
                continue;

            while (!st.empty() && st.top() > s[i] && umpp[st.top()] > 0) {

                used[st.top()] = false;
                st.pop();
            }

            st.push(s[i]);
            used[s[i]] = true;
        }

        string result = "";

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};