class Solution {
public:
    string smallestPalindrome(string s) {
        int m=s.length();
        if(m<=3)return s;

       int  k=m/2;
        if(m%2!=0){
     
       sort(s.begin(),s.begin()+k);
       sort(s.begin()+k+1,s.end(),[](char a,char b){
        return a>b;
       });

       }
       else{
 sort(s.begin(),s.begin()+k);
       sort(s.begin()+k,s.end(),[](char a,char b){
        return a>b;
       });
       }
       
      
       return s;
       
        
       
        
    }
};