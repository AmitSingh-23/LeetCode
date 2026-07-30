class Solution {
public:
    int minimumPushes(string word) {
    int m=word.length();
    vector<int>vt(26,0);
   for(int i=0;i<m;i++){
        int ind=word[i]-'a';
        vt[ind]++;
     }
     sort(vt.begin(),vt.end(),[](int a,int b){
        return a>b;
     });
     int result=0;
     int count=0;
     int add=0;
     for(int i=0;i<26;i++){
        if(count%8==0){
            add++;
        } 
        count++;
        result+=vt[i]*add;
       
     }
     return result;

    }
};