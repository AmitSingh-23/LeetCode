class Solution {
public:
    int sumCounts(vector<int>& nums) {
        long long result=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int>umpp;
            for(int j=i;j<nums.size();j++){
                umpp[nums[j]]++;
            result+=umpp.size()*umpp.size();

            }

        }
          return result;
    }
  

};