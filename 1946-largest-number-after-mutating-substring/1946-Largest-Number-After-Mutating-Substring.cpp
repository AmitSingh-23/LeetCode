class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool mutate =false;

        for(int i=0;i<num.length();i++){
            int val=num[i]-'0';
            if(val<change[val]){
                num[i]=char(change[val]+'0');
                mutate=true;
            }
            if(val>change[val]&&mutate){
                break;
            }
            

        }
        return num;
    }
};