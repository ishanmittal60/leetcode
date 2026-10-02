class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int m=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<m) m =prices[i];
            else ans=max(ans,prices[i]-m);
        }
        return ans;
    }
};