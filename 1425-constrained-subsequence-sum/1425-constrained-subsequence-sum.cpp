class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>dp(nums.size());
         dp[0]=nums[0];
        int ans = dp[0];
        pq.push({nums[0],0});
        for(int i=1;i<nums.size();i++){
            while(!pq.empty() && i-pq.top().second>k) pq.pop();
            dp[i]=nums[i];
          if(!pq.empty())  dp[i]=max(dp[i],nums[i]+pq.top().first);
          ans=max(ans,dp[i]);
          pq.push({dp[i],i});
        }
        return ans;
    }
};