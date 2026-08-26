class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0;
        int j = 0;
        int n = s.length();
        int count = 0;
        string result = "";
        
        int len = INT_MAX;
        while (j < n) {
            if (s[j] == '1') {
                count++;
            }
            while (i <= j && count == k) {
                if (len > j - i + 1) {
                    len=j-i+1;
                    result=s.substr(i,len);
                    
                }
                else if(len==j-i+1&&result>s.substr(i,len)){
                    
                        result=s.substr(i,len);
                    
                }
                if (s[i] == '1') {
                    count--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};