class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int high=*max_element(arr.begin(),arr.end());
        int low=0;
        int m=arr.size();
        int result=INT_MAX;
        int diff=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            int sum=0;
            for(int i =0;i<m;i++){
                if(arr[i]>mid){
                    sum+=mid;
                }
                else{
                    sum+=arr[i];
                }
            }
            if(diff>abs(sum-target))
{
diff=abs(sum-target);
result=mid;

}
else if(diff==abs(sum-target)) {
    result=min(mid,result);
}           if(sum>=target){
               high=mid-1;
            }
            else{
low=mid+1;
            }
        }

return result;
    }
};