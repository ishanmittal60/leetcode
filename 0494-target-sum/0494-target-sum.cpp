class Solution {
public:
   int re(vector<int>& arr, int target,int i , vector<vector<int>> &dp){
      if(i<0) return (target==0);
      if(dp[i][target]!=-1) return dp[i][target];
     // int count=0;
      int np = re(arr,target,i-1,dp);
      int pic = 0;
    if(arr[i]<=target) pic = re(arr,target-arr[i],i-1,dp);
     
      return dp[i][target]=  pic+np;
  }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return re(arr,target,arr.size()-1,dp);
       
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int sum = accumulate(arr.begin(),arr.end(),0);
        int n=arr.size();
       if(sum<diff || (sum-diff)%2!=0) return 0;
       return perfectSum(arr,(sum-diff)/2);
    }
// int re(vector<int>& nums, int target,int i){
//      if(i == 0){
//             if(target == 0 && nums[0] == 0) return 2;
//             if(target == nums[0] || target == -nums[0]) return 1;
//             return 0;
//         }
//     int neg = re(nums,target-nums[i],i-1);
//     int pos = re(nums,target+nums[i],i-1);
//     return neg+pos;
// }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(nums,target);
    }
};