class Solution {
public:
    string digitSum(string s, int k) {
        int n=s.size();
         
        while(n>k){
           string ans="";
            for(int i=0;i<n;i+=k){
                int y=0;
                for(int j=i;j<min(i+k,n);j++){
                    y+=s[j]-'0';
                }
                ans+=to_string(y);
            }
            s =ans;
            n =s.size();
        }
        return s;
    }
};