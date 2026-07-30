class Solution {
public:
    int takeCharacters(string s, int k) {
        int m=s.length();
        if(k==0)return 0;
        if(m<3||m<3*k)return -1;  
        int result=INT_MIN;
    vector<int>vt(3,0);
    for(int i=0;i<m;i++){
        vt[s[i]-'a']++;
    }
    if(!(vt[0]>=k&&vt[1]>=k&&vt[2]>=k))return -1;
    int i=0;int j=0;
    while(j<m){
        while(j<m&&vt[0]>=k&&vt[1]>=k&&vt[2]>=k){
               result=max(result,j-i);
             vt[s[j]-'a']--;
             j++;
            }
            while(i<=j&&!(vt[0]>=k&&vt[1]>=k&&vt[2]>=k)){
                vt[s[i]-'a']++;
                i++;
            }
    }

    if(vt[0]>=k&&vt[1]>=k&&vt[2]>=k){
        result=max(result,j-i);    
        }
    return m-result;
    
    }
};