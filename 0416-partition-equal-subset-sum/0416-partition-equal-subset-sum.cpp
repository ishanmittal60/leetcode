class Solution {
public:
bool re(vector<int>& arr, int sum, int i,vector<vector<int>> &dp){
       if(sum==0) return true;
       
      if(i<0) return false;
     
      if(dp[i][sum] !=-1) return dp[i][sum];
      if(arr[i]>sum) return dp[i][sum]= re(arr,sum,i-1,dp);
      bool pick = re(arr,sum-arr[i],i-1,dp);
      bool np = re(arr,sum,i-1,dp);
      return dp[i][sum] = pick || np;
  }
    bool canPartition(vector<int>& nums) {
          int n = nums.size();
          int  sum = accumulate(nums.begin(),nums.end(),0);
          if(sum%2==1) return false; 
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        return re(nums,sum/2,n-1,dp);
    }
};