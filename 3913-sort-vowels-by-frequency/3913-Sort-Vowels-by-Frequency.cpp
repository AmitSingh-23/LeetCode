class Solution {
public:
    string sortVowels(string s) {

        vector<int> vt(26, 0);
        vector<int> first(26, s.length());
        vector<char> v;

        for(int i = 0; i < s.length(); i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                vt[s[i]-'a']++;

                if(first[s[i]-'a'] == s.length()){
                    first[s[i]-'a'] = i;
                }
            }
        }

        for(char c : {'a', 'e', 'i', 'o', 'u'}){
            if(vt[c-'a'] > 0){
                v.push_back(c);
            }
        }

        sort(v.begin(), v.end(), [&](char a, char b){
            if(vt[a-'a'] != vt[b-'a']){
                return vt[a-'a'] > vt[b-'a'];
            }
            return first[a-'a'] < first[b-'a'];
        });

        int j = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                s[i] = v[j];
                vt[v[j]-'a']--;

                if(vt[v[j]-'a'] == 0){
                    j++;
                }
            }
        }

        return s;
    }
};