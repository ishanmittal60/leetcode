class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        int a=10;
        while(n-a>=0){
            n-=a;
            a-=1;
        }
        if(a%2==0) return false;
        return true;
    }
};