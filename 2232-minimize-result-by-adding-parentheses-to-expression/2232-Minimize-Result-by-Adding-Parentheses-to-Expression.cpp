class Solution {
public:
    string minimizeResult(string expression) {
        int plusPos = expression.find('+');
        string a = expression.substr(0, plusPos);
        string b = expression.substr(plusPos + 1);

        int best = INT_MAX;
        string ans;

        for (int i = 0; i < a.size(); i++) {
            int left = 1;
            int mid1 = stoi(a.substr(i));

            if (i > 0) {
                left = stoi(a.substr(0, i));
            }

            for (int j = 1; j <= b.size(); j++) {
                int mid2 = stoi(b.substr(0, j));
                int right = 1;

                if (j < b.size()) {
                    right = stoi(b.substr(j));
                }

                int value = left * (mid1 + mid2) * right;

                if (value < best) {
                    best = value;
                    ans = a.substr(0, i) + "(" + a.substr(i) + "+" + 
                          b.substr(0, j) + ")" + b.substr(j);
                }
            }
        }

        return ans;
    }
};