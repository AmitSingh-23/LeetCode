class Solution {
public:
   int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> vt;
        int m=nums.size();
        for(int i=0;i<m;i++){    
            vt[nums[i]].push_back(i);
        }
        int result=INT_MAX;
        for(auto &[key,value]:vt){
            int n=value.size();
            if (n<3)continue;
            int i=0;
            while(i+2<n){
                int val=abs(value[i]-value[i+1])+abs(value[i+1]-value[i+2])+abs(value[i+2]-value[i]);
                result=min(val,result);
                i++;
            }
        }
        return (result==INT_MAX) ? -1:result;
    }
};