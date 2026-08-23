class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n = s.length();
        string result;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);

            } else if (s[i] == ')') {
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop();

                } else {
                    st.push(i);
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if ((!st.empty()) && st.top() == i) {
                st.pop();

            } else {
                result += s[i];
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};