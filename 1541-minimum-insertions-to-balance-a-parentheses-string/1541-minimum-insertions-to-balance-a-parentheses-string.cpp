class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int o=0;
        int a=0;

        for(int i=0;i<n;i++){
            if(s[i]=='(') o++;
            else{
                if(i+1<n && s[i+1]==')'){
                    i++;
                }
                else a++;
                if(o>0) o--;
                else a++;
            }
        }
        return a+2*o;
    }
};