class Solution {
public:
vector<vector<int>>dp;
int help(vector<int>& nums1, vector<int>& nums2,int i, int j){
    if(i==nums1.size() || j==nums2.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int len=0;
    if(nums1[i]==nums2[j]){
        len = 1+ help(nums1,nums2,i+1,j+1);
    }
    else len = max({help(nums1,nums2,i+1,j),help(nums1,nums2,i,j+1)});
    return dp[i][j]= len;
}
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m=nums2.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return help(nums1,nums2,0,0);
    }
};