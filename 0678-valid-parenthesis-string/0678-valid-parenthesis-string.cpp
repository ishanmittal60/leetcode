class Solution {
public:
    bool checkValidString(string s) {
        int up=0;
        int down=0;
      //  int i=0;
        int n=s.size();
        for(char c:s){
            if(c=='('){
                up++;
                down++;
            }
            else if(c==')'){
                up--;
                down--;
            }
            else{
                up--;
                down++;
            }
            if(down<0) return false;
            if(up<0) up=0;
        }
        return up==0;
    }
};