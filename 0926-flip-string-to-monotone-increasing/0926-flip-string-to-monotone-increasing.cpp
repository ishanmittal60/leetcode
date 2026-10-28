class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int f=0;
        int z=0;
        for(char c:s){
            if(c=='1') z++;
            else f=min(f+1,z);
        }
        return f;
    }
};