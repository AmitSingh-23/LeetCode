class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int i = 0;
        int j = skill.size() - 1;
        long long team = skill[i] + skill[j];
        long long sum = 0;
        while (i < j) {
            if (skill[i] + skill[j] != team)
                return -1;
            sum += skill[i] * skill[j];
            i++;
            j--;
        }
        return sum;
    }
};