class Solution {
public:
    long long countSubstrings(string s, char c) {
        vector<long long> vt(s.length(), 0);
        long long result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c)
                vt[i] = 1;
        }
        for (int i = 1; i < vt.size(); i++) {
            vt[i] += vt[i - 1];
        
        }
        for(int i=0;i<s.length();i++){
            if(s[i]==c)result+=vt[i];
        }
        return result;
    }
};