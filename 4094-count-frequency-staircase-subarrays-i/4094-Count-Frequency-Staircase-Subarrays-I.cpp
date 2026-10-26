
class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int result = 0;

        for(int i = 0; i < nums.size(); i++) {
            unordered_map<int,int> umpp;
            vector<int> vt;
            for(int j = i; j < nums.size(); j++) {
                if(umpp[nums[j]] == 0) {
                    vt.push_back(nums[j]);
                }

                umpp[nums[j]]++;

                bool check = true;

                for(int k = 0; k < vt.size(); k++) {
                    if(umpp[vt[k]] != k + 1) {
                        check = false;
                        break;
                    }
                }

                if(check) result++;
            }
        }

        return result;
    }
};
