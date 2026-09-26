class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> umpp;
        for (int i = 0; i < knowledge.size(); i++) {
            umpp[knowledge[i][0]] = knowledge[i][1];
        }
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                int st = i+1;
                int end = i;
                while (i < s.length() && s[i] != ')') {
                    i++;
                }
                end = i-1;
                string rep = s.substr(st, end - st + 1);
                if (umpp.find(rep) != umpp.end()) {
                    result += umpp[rep];
                } else {
                    result += '?';
                }
               
            } else {
                result += s[i];
            }
        }
        return result;
    }
};