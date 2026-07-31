class Solution {
public:
  
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m=landStartTime.size();
        int n=waterStartTime.size();
       
       int ans=INT_MAX;
       int resultl=INT_MAX;
       int resultw=INT_MAX; 
        for(int i=0;i<m;i++){
        resultl=min(landStartTime[i]+landDuration[i],resultl);
        }
     
        for(int i=0;i<n;i++){
            if(resultl<=waterStartTime[i]){
                 ans=min(waterStartTime[i]+waterDuration[i],ans);    
            }
            else{
                ans=min(resultl+waterDuration[i],ans);  
            }
            resultw=min(waterStartTime[i]+waterDuration[i],resultw);

        }
        for(int i=0;i<m;i++){
            if(resultw<=landStartTime[i]){
                ans=min(landStartTime[i]+landDuration[i],ans);

            }   
        else{
            ans=min(resultw+landDuration[i],ans);

            }
        }
        return ans;
        
    


    }

};