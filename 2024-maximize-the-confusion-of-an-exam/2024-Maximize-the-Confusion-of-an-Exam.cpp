class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int result = 0;
        int i = 0;
        int val = 0;
        for (int j = 0; j < answerKey.size(); j++) {

            if (answerKey[j] == 'F') {
                val++;
            }

            while (i <= j && val > k) {

                if (answerKey[i] == 'F') {

                    val--;
                }
                i++;
            }
            result = max(result, j - i + 1);
        }
        i = 0;
        val = 0;
        for (int j = 0; j < answerKey.size(); j++) {

            if (answerKey[j] == 'T') {
                val++;
            }
            while (i <= j && val > k) {

                if (answerKey[i] == 'T') {

                    val--;
                }
                i++;
            }
            result = max(result, j - i + 1);
        }
        return result;
    }
};