
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }

        string result = "";

        for (int i = 0; i < target.length(); i++) {
            int a = target[i] - 'a';

            if (count[a] > 0) {
                result += (char)(a + 'a');
                count[a]--;
            } else {
                bool check = false;

                for (int j = a + 1; j < 26; j++) {
                    if (count[j] > 0) {
                        result += (char)(j + 'a');
                        count[j]--;
                        check = true;
                        break;
                    }
                }

                if (check) {
                    for (int j = 0; j < 26; j++) {
                        while (count[j] > 0) {
                            result += (char)(j + 'a');
                            count[j]--;
                        }
                    }

                    return result;
                }

                while (!result.empty()) {
                    int last = result.back() - 'a';
                    result.pop_back();
                    count[last]++;

                    int pos = result.length();
                    int need = target[pos] - 'a';

                    for (int j = need + 1; j < 26; j++) {
                        if (count[j] > 0) {
                            result += (char)(j + 'a');
                            count[j]--;

                            for (int k = 0; k < 26; k++) {
                                while (count[k] > 0) {
                                    result += (char)(k + 'a');
                                    count[k]--;
                                }
                            }

                            return result;
                        }
                    }
                }

                return "";
            }
        }

        while (!result.empty()) {
            int last = result.back() - 'a';
            result.pop_back();
            count[last]++;

            int pos = result.length();
            int need = target[pos] - 'a';

            for (int j = need + 1; j < 26; j++) {
                if (count[j] > 0) {
                    result += (char)(j + 'a');
                    count[j]--;

                    for (int k = 0; k < 26; k++) {
                        while (count[k] > 0) {
                            result += (char)(k + 'a');
                            count[k]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
    }
};
