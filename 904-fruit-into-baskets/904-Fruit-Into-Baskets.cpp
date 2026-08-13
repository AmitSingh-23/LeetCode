class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int val1 = -1;
        int val2 = -1;
        int j = 0;
        unordered_map<int, int> umpp;

        int result = 1;
        for (int i = 0; i < fruits.size(); i++) {
            umpp[fruits[i]]++;
            if (val1 == -1) {
                val1 = fruits[i];
            } else if (val2 == -1 && val1 != fruits[i]) {
                val2 = fruits[i];
            }
            if (umpp.size() > 2) {
                while (j < i&&umpp.size()>2) {
                    umpp[fruits[j]]--;
                    if (umpp[val1] == 0) {
                        umpp.erase(val1);
                        val1 = fruits[i];
                    
                    } else if (umpp[val2] == 0) {
                        umpp.erase(val2);
                        val2 = fruits[i];
                        
                    }
                    j++;
                }
            }
            result = max(result, i - j + 1);
        }
        return result;
    }
};