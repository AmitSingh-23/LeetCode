class Solution {
public:
    long long smallestNumber(long long num) {
        if(num==0)return num;
        long long  k=1;
        string s;
         if(num<0){
            k=-1;
         
 num=k*num; 
  s=to_string(num);
  sort(s.begin(),s.end(),[](char a,char b){
    return a>b;
  });
         }
         
         else{
            s= to_string(num);
            sort(s.begin(),s.end());
            int i=0;int j=0;
                while(s[j]=='0'){
                    j++;

                }
                swap(s[i],s[j]);
            
         }
        
return k*stoll(s);
    }
};