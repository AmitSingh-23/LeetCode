class Solution {
public:
    string robotWithString(string s) {
        stack<char> st;

        vector<int> vt(26, 0);
        string result = "";

        for (int i = 0; i < s.length(); i++) {
            vt[s[i] - 'a']++;
        }
        int j = 0;
        for (int i = 0; i < s.length() && j < 26; i++) {

            st.push(s[i]);
            vt[s[i] - 'a']--;
            while (j < 26 && vt[j] == 0) {

                j++;
            }
            while (!st.empty() && (int)st.top() <= j + 'a') {
                result += st.top();
                st.pop();
            }
        }
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};