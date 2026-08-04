class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>result;
        int k=nums[0];
        int i=0;

        while(k<=nums[nums.size()-1]&&i<nums.size()){
            if(k==nums[i]){
                i++;
                
            }
            else{
                result.push_back(k);

            }
            k++;
        }
        return result;
    }
};