class Solution {
public:
    bool checkString(string s) {
        int n =s.size();
        int j=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                j=i;
                break;
                
            }
        }
        if(j==n-1 || j==-1) return true;
        for(int i=j+1;i<n;i++){
            if(s[i]=='a') return false;
        }
        return true;
    }
};